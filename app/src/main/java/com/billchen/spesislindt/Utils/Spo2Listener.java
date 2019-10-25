package com.billchen.spesislindt.Utils;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.billchen.spesislindt.Handlers.HandlerCode;
import com.billchen.spesislindt.Service.ConnectionService;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Spo2Listener {

    private static Logger logger = Logger.getLogger("Spo2Listener");
    private ConnectionService connectionService;

    private ScheduledExecutorService generalPurposeExecutor = null;     // runs ResetTask and StopDataTask
    private ScheduledExecutorService readDataExecutor = null;           // runs and re-runs StartDataTask in an indefinite loop
    private ScheduledExecutorService keepAliveExecutor = null;          // runs KeepAliveTask every 5 minutes
    private boolean keepAliveTaskRunning;
    private static final int STAY_CONNECTED_PERIOD_SEC = 5;
    private InputStream inputStream;
    private OutputStream outputStream;
    private Handler spo2Handler;


    public Spo2Listener(InputStream inputStream, OutputStream outputStream, Handler handler) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        spo2Handler = handler;
        this.connectionService = ConnectionService.getInstance();
        startData();
    }

    private void startData() {
        if (keepAliveExecutor == null ||
                keepAliveExecutor.isShutdown() ||
                keepAliveExecutor.isTerminated()) {
            keepAliveExecutor = Executors.newSingleThreadScheduledExecutor();
        }
        if (!keepAliveTaskRunning) {
            keepAliveExecutor.scheduleAtFixedRate(new KeepAliveTask(inputStream, outputStream),
                    0, STAY_CONNECTED_PERIOD_SEC, TimeUnit.SECONDS);
            keepAliveTaskRunning = true;
        }
        if (readDataExecutor == null) {
            readDataExecutor = Executors.newSingleThreadScheduledExecutor();
        }
        readDataExecutor.submit(new StartDataTask(inputStream, outputStream, spo2Handler));
    }

    enum CMS50FWCommand {
        START_DATA((byte) 0xA1),             // 161
        STOP_DATA((byte) 0xA2),             // 162
        STAY_CONNECTED((byte) 0xAF),         // 175
        SEND_USER_INFORMATION((byte) 0xAB),  // 171
        PADDING((byte) 0x80),                // 128
        COMMAND_FOLLOWS((byte) 0x7D);        // 125

        private final byte command;

        CMS50FWCommand(byte command) {
            this.command = command;
        }

        public int asInt() {
            return (int) command;
        }
    }


    private class StartDataTask implements Runnable {

        private InputStream inputStream;
        private OutputStream outputStream;
        private Handler spo2Handler;

        private static final int BIT_0 = 1;
        private static final int BIT_1 = 2;
        private static final int BIT_2 = 4;
        private static final int BIT_3 = 8;
        private static final int BITS_ZERO_TO_THREE = BIT_0 | BIT_1 | BIT_2 | BIT_3;
        private static final int BIT_4 = 16;
        private static final int BIT_5 = 32;
        private static final int BIT_6 = 64;
        private static final int BITS_ZERO_TO_SIX = BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4 | BIT_5 | BIT_6;
        private static final int BIT_7 = 128;
        private static final int SIXTY_FOUR = 64;
        private static final int ONE_TWENTY_SEVEN = 127;
        private static final String COULD_NOT_PUT_STREAMING_DATA_INTO_A_NEW_DATA_FRAME = "Could not put streaming data into a new data frame.";
        private static final int COMMAND_ONE_TWENTY_NINE = 129;


        StartDataTask(InputStream inputStream, OutputStream outputStream, Handler handler) {
            this.inputStream = inputStream;
            this.outputStream = outputStream;
            this.spo2Handler = handler;
        }

        @Override
        public void run() {

            try {
                // writing to input stream in order to issue a command
                writeCommand(CMS50FWCommand.START_DATA);

                while (true) {
                    final DataFrame dataframe = getNextDataFrame(inputStream);
                    Message msg = spo2Handler.obtainMessage(HandlerCode.Spo2.ordinal());
                    Bundle b1 = new Bundle();
                    b1.putLong("time",dataframe.time);
                    b1.putInt("pulse", dataframe.pulseWaveForm);
                    b1.putBoolean("beep", dataframe.beep);
                    b1.putInt("SpO2",dataframe.spo2Percentage);

                    msg.setData(b1);
                    spo2Handler.sendMessage(msg);
                }
            } catch (IOException ioe) {
                logger.log(Level.WARNING, "Connection to CMS50FW has broken.");
            }

        }


        private void writeCommand(CMS50FWCommand command) throws IOException {
            CMS50FWCommand dataByte = CMS50FWCommand.PADDING;
            outputStream.write(CMS50FWCommand.COMMAND_FOLLOWS.asInt()); // mark the beginning of command bytes
            outputStream.write(COMMAND_ONE_TWENTY_NINE);                // 0x81 - not sure what this is
            outputStream.write(command.asInt());                        // the actual command
            outputStream.write(dataByte.asInt());                       // sometimes a particular byte must follow the command, but not always
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.flush();
        }

        private DataFrame getNextDataFrame(InputStream inputStream) {

            // separates each frame from previous frame
            //noinspection UnusedAssignment
            byte frameBoundary; // aka byte1

            // actual data is stored in these seven bytes
            //noinspection UnusedAssignment
            byte byte2; // ignored
            byte byte3;
            byte byte4;
            byte byte5;
            byte byte6;
            //noinspection UnusedAssignment
            byte byte7; // ignored
            //noinspection UnusedAssignment
            byte byte8; // ignored

            if (inputStream != null) {
                try {
                    // create a new empty data frame, ready to be filled in
                    DataFrame dataFrame = new DataFrame();

                    // search the stream until the byte which signals the beginning of the next data frame is found
                    while (true) {
                        byte frameBoundaryCandidate = waitForNextByte(inputStream);
                        if ((frameBoundaryCandidate & BIT_7) == BIT_7) { // look for next byte with the 7 bit set
                            //noinspection UnusedAssignment
                            frameBoundary = frameBoundaryCandidate;
                            break;
                        }
                    }

                    // the next 7 bytes are the meaningful ones in the CMS50FW data stream
                    // but, in this code, byte2, byte7 and byte8 will not be used

                    //noinspection UnusedAssignment
                    byte2 = waitForNextByte(inputStream);

                    // bytes we actually use
                    byte3 = waitForNextByte(inputStream);
                    byte4 = waitForNextByte(inputStream);
                    byte5 = waitForNextByte(inputStream);
                    byte6 = waitForNextByte(inputStream);

                    //noinspection UnusedAssignment
                    byte7 = waitForNextByte(inputStream);
                    //noinspection UnusedAssignment
                    byte8 = waitForNextByte(inputStream);

                    dataFrame.pulseWaveForm = (byte3 & BITS_ZERO_TO_SIX);
                    dataFrame.pulseIntensity = (byte4 & BITS_ZERO_TO_THREE);
                    dataFrame.pulseRate = (byte5 & BITS_ZERO_TO_SIX);
                    // TODO: this does not allow pulseRate to be above 127.  But for lower values, it seems to be correct.
                    dataFrame.spo2Percentage = (byte6 & BITS_ZERO_TO_SIX);
                    dataFrame.isFingerOutOfSleeve = (dataFrame.pulseWaveForm == SIXTY_FOUR) &&
                            (dataFrame.pulseRate == ONE_TWENTY_SEVEN) && (dataFrame.spo2Percentage == ONE_TWENTY_SEVEN);
                    dataFrame.beep = ((byte2 & BIT_6) == BIT_6);

                    return dataFrame;

                } catch (IOException e) {
                    logger.log(Level.WARNING, "Failed to obtain SPO2 info.");
                }
            }
            return null;
        }

        /**
         * Spins until a byte becomes available on the input stream. Then it
         * reads and returns that single byte.
         *
         * @return the next byte from the input stream
         * @throws IOException if the Bluetooth connection is unexpectedly closed or
         * the stream can't be read for some reason.
         */
        private byte waitForNextByte(InputStream inputStream) throws IOException {
            // It's important to check for a live connection frequently here because another thread
            // might close connection, causing an IOException to be thrown from this code

            //noinspection StatementWithEmptyBody
            while (inputStream.available() <= 0) {
                // do nothing until a byte is available from input stream
            }
            return (byte) inputStream.read();
            //return 0;
        }

    }

    private class DataFrame {
        public final long time;
        int pulseWaveForm;
        int pulseIntensity;
        int pulseRate;
        int spo2Percentage;
        boolean isFingerOutOfSleeve;
        boolean beep = false;

        DataFrame() {
            time = System.currentTimeMillis();
        }

    }

    class KeepAliveTask implements Runnable {

        InputStream inputStream;
        OutputStream outputStream;
        private static final int COMMAND_ONE_TWENTY_NINE = 129;
        //private static final String TAG = KeepAliveTask.class.getSimpleName();

        private static final String BROKEN_PIPE = "Broken pipe";
        private static final String COULD_NOT_WRITE_STAY_CONNECTED_COMMAND_MESSAGE = "Could not " +
                "write stay connected command because socket and/or output stream were not ready.";
        private static final String BROKEN_PIPE_LOG_MESSAGE = "Broken Connection to CMS50FW!";
        private static final String BROKEN_PIPE_COULD_NOT_WRITE_STAY_CONNECTED_COMMAND_MESSAGE = "Could not write stay connected command.";
        private static final String KEEP_ALIVE_TASK_EXITING_WITHOUT_WRITING_CMS50FW_COMMAND_MESSAGE =
                "Keep alive task exiting without writing command to CMS50FW because reading data is not currently enabled.";


        KeepAliveTask(InputStream inputStream, OutputStream outputStream) {
            this.inputStream = inputStream;
            this.outputStream = outputStream;
        }

        void writeCommand(CMS50FWCommand command) throws IOException {
            CMS50FWCommand dataByte = CMS50FWCommand.PADDING;
            outputStream.write(CMS50FWCommand.COMMAND_FOLLOWS.asInt()); // mark the beginning of command bytes
            outputStream.write(COMMAND_ONE_TWENTY_NINE);                // 0x81 - not sure what this is
            outputStream.write(command.asInt());                        // the actual command
            outputStream.write(dataByte.asInt());                       // sometimes a particular byte must follow the command, but not always
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.write(CMS50FWCommand.PADDING.asInt());
            outputStream.flush();
        }

        @Override
        public void run() {
            try {
                writeCommand(CMS50FWCommand.STAY_CONNECTED);
            } catch (IOException e) {
                logger.log(Level.WARNING, "Connection to CMS50FW has broken.");
            }
        }
    }
}





