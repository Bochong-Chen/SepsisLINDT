package com.billchen.spesislindt.Handlers;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.widget.TextView;

import com.billchen.spesislindt.R;
import com.billchen.spesislindt.databinding.ActivityMainBinding;

import androidx.databinding.DataBindingUtil;

public class BioharnessHandler extends Handler {

    // Code for communication
    private final int Spo2 = 0x127;
    private final int HEART_RATE = 0x100;
    private final int RESPIRATION_RATE = 0x101;
    private final int SKIN_TEMPERATURE = 0x102;
    private final int POSTURE = 0x103;
    private final int PEAK_ACCLERATION = 0x104;
    private final int BREATHING_RAW = 0x105;
    private final int ECG = 0x106;
    private final int UI = 0x107;

    ActivityMainBinding binding;

    public BioharnessHandler(ActivityMainBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == HEART_RATE) {
            int hr = msg.getData().getInt("HeartRate");
            binding.hrText.setText(Integer.toString(hr));
        }

        if (msg.what == RESPIRATION_RATE) {
            double resp = msg.getData().getDouble("RespirationRate");
            binding.respText.setText(Double.toString(resp));
        }
    }
}
