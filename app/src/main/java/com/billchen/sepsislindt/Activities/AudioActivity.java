package com.billchen.sepsislindt.Activities;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.databinding.DataBindingUtil;

import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.databinding.ActivityAudioBinding;

import java.util.ArrayList;
import java.util.logging.Logger;

public class AudioActivity extends AppCompatActivity {

    private static Logger logger = Logger.getLogger("AudioActivity");

    // Data binding with activity_audio.xml
    private ActivityAudioBinding binding;

    // Audio related variables
    private final int MY_PERMISSIONS_RECORD_AUDIO = 1;
    private static final int RECORDER_SAMPLERATE = 8000;
    private static final int RECORDER_CHANNELS = AudioFormat.CHANNEL_IN_MONO;
    private static final int RECORDER_AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    private AudioRecord recorder = null;
    private Thread recordingThread = null;
    private boolean isRecording = false;
    int BufferElements2Rec = 1024; // want to play 2048 (2K) since 2 bytes we use only 1024
    int BytesPerElement = 2; // 2 bytes in 16bit format

    ArrayList<Double> data = new ArrayList<>();


    static {
        // Load the C library from ./cpp/get_result/main.c
        System.loadLibrary("get-result");
    }

    // Implementation at ./cpp/get_result/main.c
    private native double getResult(double[] array, double fs, boolean flag);



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio);

        // UI bindings
        binding = DataBindingUtil.setContentView(this, R.layout.activity_audio);

        // Connect buttons to listeners
        setButtonHandlers();
        // Toggle Start and Stop buttons
        enableButtons(false);
    }

    private void setButtonHandlers() {
        binding.btnStart.setOnClickListener(btnClick);
        binding.btnStop.setOnClickListener(btnClick);
    }

    // Start recording and store to the ArrayList data
    private void startRecording() {

        // Check if the app has permission to record audio samples
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.RECORD_AUDIO}, MY_PERMISSIONS_RECORD_AUDIO);
        }

        recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
                RECORDER_SAMPLERATE, RECORDER_CHANNELS,
                RECORDER_AUDIO_ENCODING, BufferElements2Rec * BytesPerElement);

        recorder.startRecording();
        isRecording = true;
        recordingThread = new Thread(() -> {
            short[] sData = new short[BufferElements2Rec];
            data.clear();
            while (isRecording) {
                // gets the voice output from microphone to byte format
                recorder.read(sData, 0, BufferElements2Rec);
                for (short i: sData) {
                    data.add((double) i);
                }
            }
        }, "AudioRecorder Thread");
        recordingThread.start();
    }

    // Stop recording, calculate the breathing rate, and return to MeasureActivity
    private void stopRecording() {
        // stops the recording activity
        if (null != recorder) {
            isRecording = false;
            recorder.stop();
            recorder.release();
            recorder = null;
            recordingThread = null;

            // prepare the data to be read by C code
            double[] jdata = new double[data.size()];
            int idx = 0;
            for (double data_i: data) {
                jdata[idx++] = data_i;
            }

            // run C code to get breathing rate
            double result = getResult(jdata, RECORDER_SAMPLERATE, false);

            // go back to MeasureActivity with result stored in intent
            Intent intent = new Intent(AudioActivity.this, MeasureActivity.class);
            intent.putExtra("breathing", result);
            startActivity(intent);
            finish();

        }
    }

    private View.OnClickListener btnClick = v -> {
        switch (v.getId()) {
            case R.id.btnStart: {
                enableButtons(true);
                startRecording();
                break;
            }
            case R.id.btnStop: {
                enableButtons(false);
                stopRecording();
                break;
            }
        }
    };


    private void enableButtons(boolean isRecording) {
        binding.btnStart.setEnabled(!isRecording);
        binding.btnStop.setEnabled(isRecording);
    }
}
