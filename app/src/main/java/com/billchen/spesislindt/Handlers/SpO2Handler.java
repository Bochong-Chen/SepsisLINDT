package com.billchen.spesislindt.Handlers;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.spesislindt.databinding.ActivityMainBinding;

public class SpO2Handler extends Handler {

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

    public SpO2Handler(ActivityMainBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == Spo2) {
            int SpO2 = msg.getData().getInt("SpO2");
            binding.spO2Text.setText(String.valueOf(SpO2));
        }
    }
}
