package com.billchen.spesislindt.Utils;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.billchen.spesislindt.Handlers.HandlerCode;
import com.billchen.spesislindt.Service.ConnectionService;

import java.util.Arrays;
import java.util.logging.Logger;

import zephyr.android.BioHarnessBT.*;

public class BioHarnessListener extends ConnectListenerImpl {

    private static Logger logger = Logger.getLogger("BioHarnessListener");
    private ConnectionService connectionService;

    private Handler handler;

    /*Creating the different Objects for different types of Packets*/
    private GeneralPacketInfo GPInfo = new GeneralPacketInfo();
    private ECGPacketInfo ECGInfoPacket = new ECGPacketInfo();
    private BreathingPacketInfo BreathingInfoPacket = new  BreathingPacketInfo();
    private RtoRPacketInfo RtoRInfoPacket = new RtoRPacketInfo();
    private AccelerometerPacketInfo AccInfoPacket = new AccelerometerPacketInfo();
    private SummaryPacketInfo SummaryInfoPacket = new SummaryPacketInfo();

    private PacketTypeRequest RqPacketType = new PacketTypeRequest();

    public BioHarnessListener(Handler handler) {
        super(handler, null);
        this.handler = handler;
        this.connectionService = ConnectionService.getInstance();
    }

    public void Connected(ConnectedEvent<BTClient> eventArgs) {
        System.out.println(String.format("Connected to BioHarness %s.", eventArgs.getSource().getDevice().getName()));
        /*Use this object to enable or disable the different Packet types*/
        RqPacketType.GP_ENABLE = true;
        RqPacketType.BREATHING_ENABLE = true;
        RqPacketType.LOGGING_ENABLE = true;
        //RqPacketType.RtoR_ENABLE = true;
        RqPacketType.ECG_ENABLE = true;


        //Creates a new ZephyrProtocol object and passes it the BTComms object
        ZephyrProtocol _protocol = new ZephyrProtocol(eventArgs.getSource().getComms(), RqPacketType);
        //ZephyrProtocol _protocol = new ZephyrProtocol(eventArgs.getSource().getComms(), );
        _protocol.addZephyrPacketEventListener(new ZephyrPacketListener() {
            public void ReceivedPacket(ZephyrPacketEvent eventArgs) {
                ZephyrPacketArgs msg = eventArgs.getPacket();
                long time = System.currentTimeMillis();
                byte CRCFailStatus;
                byte RcvdBytes;



                CRCFailStatus = msg.getCRCStatus();
                RcvdBytes = msg.getNumRvcdBytes() ;
                int MsgID = msg.getMsgID();
                byte [] DataArray = msg.getBytes();
                HandlerCode code = HandlerCode.get(MsgID);
                switch (code)
                {

                    case GP_MSG_ID:
                        //***************Displaying the Heart Rate********************************
                        int HRate =  GPInfo.GetHeartRate(DataArray);
                        Message HRate_msg = handler.obtainMessage(HandlerCode.HEART_RATE.ordinal());
                        Bundle HR_bundle = new Bundle();
                        HR_bundle.putInt("HeartRate", HRate);
                        HRate_msg.setData(HR_bundle);
                        handler.sendMessage(HRate_msg);
                        //System.out.println("Heart Rate is "+ HRate);


                        //***************Displaying the Respiration Rate********************************
                        double RespRate = GPInfo.GetRespirationRate(DataArray);
                        Message text1 = handler.obtainMessage(HandlerCode.RESPIRATION_RATE.ordinal());
                        Bundle b1 = new Bundle();
                        b1.putDouble("RespirationRate", RespRate);
                        text1.setData(b1);
                        handler.sendMessage(text1);
                        //System.out.println("Respiration Rate is "+ RespRate);


                        //***************Displaying the Skin Temperature*******************************


                        double SkinTempDbl = GPInfo.GetSkinTemperature(DataArray);
                        text1 = handler.obtainMessage(HandlerCode.SKIN_TEMPERATURE.ordinal());
                        //Bundle b1 = new Bundle();
                        b1.putString("SkinTemperature", String.valueOf(SkinTempDbl));
                        text1.setData(b1);
                        handler.sendMessage(text1);
                        //System.out.println("Skin Temperature is "+ SkinTempDbl);

                        //***************Displaying the Posture******************************************

                        int PostureInt = GPInfo.GetPosture(DataArray);
                        text1 = handler.obtainMessage(HandlerCode.POSTURE.ordinal());
                        b1.putString("Posture", String.valueOf(PostureInt));
                        text1.setData(b1);
                        handler.sendMessage(text1);
                        //System.out.println("Posture is "+ PostureInt);
                        //***************Displaying the Peak Acceleration******************************************

                        double PeakAccDbl = GPInfo.GetPeakAcceleration(DataArray);
                        text1 = handler.obtainMessage(HandlerCode.PEAK_ACCLERATION.ordinal());
                        b1.putString("PeakAcceleration", String.valueOf(PeakAccDbl));
                        text1.setData(b1);
                        handler.sendMessage(text1);
                        //System.out.println("Peak Acceleration is "+ PeakAccDbl);

                        byte ROGStatus = GPInfo.GetROGStatus(DataArray);
                        //System.out.println("ROG Status is "+ ROGStatus);

                        break;
                    case BREATHING_MSG_ID:
                        short[] breathingRaw =  BreathingInfoPacket.GetBreathingSamples(DataArray);
                        Message text5 = handler.obtainMessage(HandlerCode.BREATHING_RAW.ordinal());
                        Bundle b5 = new Bundle();
                        b5.putShortArray("BreathingRaw", breathingRaw);
                        text5.setData(b5);
                        handler.sendMessage(text5);
                        break;
                    case ECG_MSG_ID:
                        /*Do what you want. Printing Sequence Number for now*/
                        //System.out.println("ECG Packet Sequence Number is "+ECGInfoPacket.GetSeqNum(DataArray));
                        //short [] ECG_sample = ECGInfoPacket.GetECGSamples(DataArray);
                        //long ECG = ECGInfoPacket.GetMsofDay(DataArray);
                        //System.out.println("ECG Data:" + Arrays.toString(ECG_sample));
                        //Message ECG_msg = _aNewHandler.obtainMessage(ECG);
                        //Bundle ECG_bundle = new Bundle();
                        //ECG_bundle.putLong("time",time);
                        //ECG_bundle.putShortArray("ECG",ECG_sample);
                        //ECG_msg.setData(ECG_bundle);
                        //_aNewHandler.sendMessage(ECG_msg);
                        break;
                    case RtoR_MSG_ID:
                        /*Do what you want. Printing Sequence Number for now*/
                        //System.out.println("R to R Packet Sequence Number is "+RtoRInfoPacket.GetSeqNum(DataArray));
                        int[] RtoR = RtoRInfoPacket.GetRtoRSamples(DataArray);
                        long RtoR_time = RtoRInfoPacket.GetMsofDay(DataArray);
                        System.out.println("R to R Data:" + RtoR_time + Arrays.toString(RtoR));

                        break;
                    case ACCEL_100mg_MSG_ID:
                        /*Do what you want. Printing Sequence Number for now*/
                        System.out.println("Accelerometry Packet Sequence Number is "+AccInfoPacket.GetSeqNum(DataArray));
                        break;
                    case SUMMARY_MSG_ID:
                        /*Do what you want. Printing Sequence Number for now*/
                        System.out.println("Summary Packet Sequence Number is "+SummaryInfoPacket.GetSeqNum(DataArray));
                        break;

                }
            }
        });
    }

}