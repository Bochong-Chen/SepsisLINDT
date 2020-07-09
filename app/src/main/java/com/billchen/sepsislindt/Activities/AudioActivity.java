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

    private ActivityAudioBinding binding;

    //Audio Related
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
        System.loadLibrary("get-result");
    }

    private native double getResult(double[] array, double fs, boolean flag);



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio);

        // UI bindings
        binding = DataBindingUtil.setContentView(this, R.layout.activity_audio);

        // Audio Recording
        setButtonHandlers();
        enableButtons(false);

        int bufferSize = AudioRecord.getMinBufferSize(RECORDER_SAMPLERATE,
                RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING);
    }

    private void setButtonHandlers() {
        binding.btnStart.setOnClickListener(btnClick);
        binding.btnStop.setOnClickListener(btnClick);
    }

    private void enableButton(int id, boolean isEnable) {
        findViewById(id).setEnabled(isEnable);
    }

    private void enableButtons(boolean isRecording) {
        enableButton(R.id.btnStart, !isRecording);
        enableButton(R.id.btnStop, isRecording);
    }

    private void startRecording() {

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.RECORD_AUDIO}, MY_PERMISSIONS_RECORD_AUDIO);
        }

        recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
                RECORDER_SAMPLERATE, RECORDER_CHANNELS,
                RECORDER_AUDIO_ENCODING, BufferElements2Rec * BytesPerElement);

        recorder.startRecording();
        isRecording = true;
        recordingThread = new Thread(new Runnable() {
            public void run() {
                short[] sData = new short[BufferElements2Rec];
                data.clear();
                while (isRecording) {
                    // gets the voice output from microphone to byte format
                    recorder.read(sData, 0, BufferElements2Rec);
                    for (short i: sData) {
                        data.add((double) i);
                    }
                }
            }
        }, "AudioRecorder Thread");
        recordingThread.start();
    }

    private void stopRecording() {
        // stops the recording activity
        if (null != recorder) {
            isRecording = false;
            recorder.stop();
            recorder.release();
            recorder = null;
            recordingThread = null;

            double[] jdata = new double[data.size()];
            int idx = 0;
            for (double data_i: data) {
                jdata[idx++] = data_i;
            }

            double result = getResult(jdata, RECORDER_SAMPLERATE, false);
            Intent intent = new Intent(AudioActivity.this, MeasureActivity.class);
            intent.putExtra("breathing", result);
            startActivity(intent);
            finish();



        }
    }

    private View.OnClickListener btnClick = new View.OnClickListener() {
        public void onClick(View v) {
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
        }
    };
}
