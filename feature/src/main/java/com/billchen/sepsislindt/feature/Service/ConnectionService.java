package com.billchen.sepsislindt.feature.Service;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;

import com.billchen.sepsislindt.feature.Utils.BioHarnessListener;
import com.billchen.sepsislindt.feature.Utils.Spo2Listener;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;
import java.util.logging.Level;
import java.util.logging.Logger;

import android.bluetooth.BluetoothSocket;
import android.os.Handler;

import zephyr.android.BioHarnessBT.BTClient;

public class ConnectionService {

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


    ConnectionService() {
        bioHarnessMacID = "00:07:80:9D:8A:E8";
        adapter = BluetoothAdapter.getDefaultAdapter();
        pairedDevices = adapter.getBondedDevices();
    }

    private boolean connectBioHarness(Handler bioHarnessHandler) {
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

    private boolean connectSpo2(Handler spo2Handler) {
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
}
