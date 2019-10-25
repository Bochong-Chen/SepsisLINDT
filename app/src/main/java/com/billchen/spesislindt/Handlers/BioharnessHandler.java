package com.billchen.spesislindt.Handlers;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.spesislindt.databinding.ActivityMainBinding;


public class BioharnessHandler extends Handler {

    private ActivityMainBinding binding;

    public BioharnessHandler(ActivityMainBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == HandlerCode.HEART_RATE.ordinal()) {
            int hr = msg.getData().getInt("HeartRate");
            binding.hrText.setText(String.valueOf(hr));
        }

        if (msg.what == HandlerCode.RESPIRATION_RATE.ordinal()) {
            double resp = msg.getData().getDouble("RespirationRate");
            binding.respText.setText(String.valueOf(resp));
        }
    }
}
