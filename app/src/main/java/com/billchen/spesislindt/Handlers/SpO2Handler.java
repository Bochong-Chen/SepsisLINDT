package com.billchen.spesislindt.Handlers;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.spesislindt.databinding.ActivityMainBinding;

public class SpO2Handler extends Handler {

    private ActivityMainBinding binding;

    public SpO2Handler(ActivityMainBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == HandlerCode.Spo2.ordinal()) {
            int SpO2 = msg.getData().getInt("SpO2");
            binding.spO2Text.setText(String.valueOf(SpO2));
        }
    }
}
