package com.billchen.sepsislindt.Service;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothProfile;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.billchen.sepsislindt.Utils.BioHarnessListener;
import com.billchen.sepsislindt.Utils.Spo2Listener;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.List;
import java.util.Set;
import java.util.UUID;
import java.util.logging.Level;
import java.util.logging.Logger;

import zephyr.android.BioHarnessBT.BTClient;

public class ConnectionService {

    private static ConnectionService instance = null;

    private static Logger logger = Logger.getLogger("ConnectionService");

    private String bioHarnessMacID;
    private BluetoothAdapter adapter;
    private Set<BluetoothDevice> pairedDevices;

    private volatile BluetoothDevice bioHarnessDevice;
    private BioHarnessListener bioHarnessListener;
    private BTClient bioHarnessClient;

    private volatile BluetoothDevice spo2Device;
    private volatile BluetoothSocket spo2Socket;
    volatile InputStream spo2InputStream;
    volatile OutputStream spo2OutputStream;


    private static final UUID CCCD = UUID.fromString("00002902-0000-1000-8000-00805f9b34fb");
    private static final UUID Blood_Pressure_SERVICE_UUID = UUID.fromString("00001810-0000-1000-8000-00805f9b34fb");
    private static final UUID Blood_Pressure_Measurement_CHAR_UUID = UUID.fromString("00002A35-0000-1000-8000-00805f9b34fb");
    private BluetoothGatt mBluetoothGatt;
    private Handler bpHandler;


    private ConnectionService() {
        bioHarnessMacID = "00:07:80:9D:8A:E8";
        adapter = BluetoothAdapter.getDefaultAdapter();
        pairedDevices = adapter.getBondedDevices();
    }

    public static ConnectionService getInstance() {
        if (instance == null) {
            instance = new ConnectionService();
        }
        return instance;
    }

    public boolean connectBioHarness(Handler bioHarnessHandler) {
        if (adapter == null) {
            logger.log(Level.INFO, "This device doesn't support bluetooth");
            return false;
        }
        pairedDevices = adapter.getBondedDevices();
        bioHarnessDevice = null;
        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                if (device.getName().startsWith("BH")) {
                    bioHarnessDevice = device;
                    bioHarnessMacID = bioHarnessDevice.getAddress();
                    break;
                }
            }
        }

        if (bioHarnessDevice == null) {
            return false;
        }

        bioHarnessClient = new BTClient(adapter, bioHarnessMacID);
        bioHarnessListener = new BioHarnessListener(bioHarnessHandler);
        bioHarnessClient.addConnectedEventListener(bioHarnessListener);
        if (bioHarnessClient.IsConnected()) {
            bioHarnessClient.start();
        }
        return true;
    }

    public boolean connectSpo2(Handler spo2Handler) {
        if (adapter == null) {
            logger.log(Level.INFO, "This device doesn't support bluetooth");
            return false;
        }
        pairedDevices = adapter.getBondedDevices();
        spo2Device = null;
        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                if (device.getName().equals("SpO202")) {
                    spo2Device = device;
                    break;
                }
            }
        }

        if (spo2Device == null) {
            return false;
        }

        try {
            spo2Socket = spo2Device.createRfcommSocketToServiceRecord(
                    UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"));
            spo2Socket.connect();
            spo2InputStream = spo2Socket.getInputStream();
            spo2OutputStream = spo2Socket.getOutputStream();
            new Spo2Listener(spo2InputStream, spo2OutputStream, spo2Handler);
        } catch (IOException ioe) {
            logger.log(Level.WARNING, "SpO2 Connection failed");
            return false;
        }
        return true;
    }

    public boolean connectBloodPressure(Context context, Handler handler) {

        bpHandler = handler;

        if (adapter == null) {
            logger.log(Level.INFO, "This device doesn't support bluetooth");
            return false;
        }
        pairedDevices = adapter.getBondedDevices();
        boolean success = false;

        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                if (device.getName().equals("BLEsmart_0000011FEC21E511C7CF")) {
                    System.out.println("Found device, connecting...");
                    mBluetoothGatt = device.connectGatt(context, true, mGattCallback);
                    success = true;
                    break;
                }
            }
        }

        return success;
    }

    private BluetoothGattCallback mGattCallback = new BluetoothGattCallback() {
        @Override
        public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {

            if (newState == BluetoothProfile.STATE_CONNECTED) {
                System.out.println("Connected to GATT.");

                // Service discovering
                // Attempts to discover services after successful connection.
                boolean mIsDiscoveredService = mBluetoothGatt.discoverServices();

                if (mIsDiscoveredService) {
                    System.out.println("Service discovered");
                }

            } else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
                System.out.println("Disconnected to GATT.");
                if (mBluetoothGatt != null) {
                    mBluetoothGatt.close();
                }

                if (!adapter.isEnabled()) {
                    System.out.println("Bluetooth is disable now.");
                }
            }
        }

        @Override
        public void onServicesDiscovered(BluetoothGatt gatt, int status) {
            System.out.println("onServicesDiscovered: " + String.format("Status=0x%02X", status));
            boolean ret;

            if (status == BluetoothGatt.GATT_SUCCESS) {
                BluetoothGattService serv;
                List<BluetoothGattService> services = gatt.getServices();

                for (int i = 0; i < services.size(); i++) {
                    serv = services.get(i);

                    // Blood Pressure Service is discovered
                    if (serv.getUuid().equals(Blood_Pressure_SERVICE_UUID)) {
                        System.out.println("Blood Pressure Service is discovered");

                        List<BluetoothGattCharacteristic> chars = serv.getCharacteristics();
                        for (int j = 0; j < chars.size(); j++) {
                            BluetoothGattCharacteristic characteristic = chars.get(j);
                            if (characteristic == null) {
                                continue;
                            }

                            if (characteristic.getUuid().equals(Blood_Pressure_Measurement_CHAR_UUID)) {
                                ret = gatt.setCharacteristicNotification(characteristic, true);
                                if (!ret) {
                                    continue;
                                }

                                System.out.println("Blood_Pressure_Measurement:characteristic.getDescriptor");

                                // Set enable Indication value to the descriptor
                                BluetoothGattDescriptor descriptor = characteristic.getDescriptor(CCCD);
                                descriptor.setValue(BluetoothGattDescriptor.ENABLE_INDICATION_VALUE);

                                mBluetoothGatt.writeDescriptor(descriptor);
                            }
                        }
                    }
                }
            }
        }

        @Override
        public void onCharacteristicChanged(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic) {

            if (characteristic.getUuid().equals(Blood_Pressure_Measurement_CHAR_UUID)) {
                byte[] data = characteristic.getValue();
//                System.out.println(Arrays.toString(data));
//                System.out.println("????????????????");

                int idx = 0;

                byte flags = data[idx++];

                // 0: mmHg	1: kPa
                boolean kPa = (flags & 0x01) > 0;
                // 0: No Timestamp info 1: With Timestamp info
                boolean timestampFlag = (flags & 0x02) > 0;
                // 0: No PlseRate info 1: With PulseRate info
                boolean pulseRateFlag = (flags & 0x04) > 0;
                // 0: No UserID info 1: With UserID info
                boolean userIdFlag = (flags & 0x08) > 0;
                // 0: No MeasurementStatus info 1: With MeasurementStatus info
                boolean measurementStatusFlag = (flags & 0x10) > 0;

                // Set BloodPressureMeasurement unit
                String unit;
                if (kPa) {
                    unit = "kPa";
                } else {
                    unit = "mmHg";
                }

                // Parse Blood Pressure Measurement
                short systolicVal = 0;
                short diastolicVal = 0;
                short meanApVal = 0;

                byte[] buf = new byte[2];
                System.arraycopy(data, idx, buf, 0, 2);
                idx += 2;
                ByteBuffer byteBuffer = ByteBuffer.wrap(buf);
                byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
                systolicVal = byteBuffer.getShort();

                System.arraycopy(data, idx, buf, 0, 2);
                idx += 2;
                byteBuffer = ByteBuffer.wrap(buf);
                byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
                diastolicVal = byteBuffer.getShort();

                System.arraycopy(data, idx, buf, 0, 2);
                idx += 2;
                byteBuffer = ByteBuffer.wrap(buf);
                byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
                meanApVal = byteBuffer.getShort();
                double[] bloodPressure = new double[3];
                bloodPressure[0] = systolicVal;
                bloodPressure[1] = diastolicVal;
                bloodPressure[2] = meanApVal;

                // Parse PulseRate
                short pulseRateVal = 0;
                if (pulseRateFlag) {
                    System.arraycopy(data, idx, buf, 0, 2);
                    byteBuffer = ByteBuffer.wrap(buf);
                    byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
                    pulseRateVal = byteBuffer.getShort();
                }
                double[] heartRate = new double[2];
                heartRate[0] = pulseRateVal;

                Message HRate_msg = bpHandler.obtainMessage(1);
                Bundle HR_bundle = new Bundle();
                HR_bundle.putDouble("HeartRate", heartRate[0]);
                HRate_msg.setData(HR_bundle);
                bpHandler.sendMessage(HRate_msg);

                Message BP_msg = bpHandler.obtainMessage(2);
                Bundle BP_bundle = new Bundle();
                BP_bundle.putDouble("Systolic", bloodPressure[0]);
                BP_bundle.putDouble("Diastolic", bloodPressure[1]);
                BP_msg.setData(BP_bundle);
                bpHandler.sendMessage(BP_msg);
            }
        }
    };

}
