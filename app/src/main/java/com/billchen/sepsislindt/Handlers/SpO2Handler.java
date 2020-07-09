package com.billchen.sepsislindt.Handlers;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.sepsislindt.databinding.ActivityMeasureBinding;

public class SpO2Handler extends Handler {

    private ActivityMeasureBinding binding;

    public SpO2Handler(ActivityMeasureBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == HandlerCode.Spo2.ordinal()) {
            int spo2 = msg.getData().getInt("SpO2");
            //binding.spo2Text.setText(String.valueOf(spo2));
        }
    }
}
