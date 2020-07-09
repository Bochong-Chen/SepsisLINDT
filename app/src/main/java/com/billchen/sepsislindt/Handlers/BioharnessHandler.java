package com.billchen.sepsislindt.Handlers;

import android.annotation.SuppressLint;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.sepsislindt.databinding.ActivityMeasureBinding;


@SuppressLint("DefaultLocale")
public class BioharnessHandler extends Handler {

    private ActivityMeasureBinding binding;

    private short[] total;
    private int size;

    public BioharnessHandler(ActivityMeasureBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;

        total = new short[540];
        size = 0;
    }

    @Override
    public void handleMessage(Message msg) {
        if (msg.what == HandlerCode.HEART_RATE.ordinal()) {
            int hr = msg.getData().getInt("HeartRate");
            //binding.hrText.setText(String.valueOf(hr));
        }

        if (msg.what == HandlerCode.RESPIRATION_RATE.ordinal()) {
            double resp = msg.getData().getDouble("RespirationRate");
            //binding.respText.setText(String.format("%.2f", resp));
        }


        /*if (msg.what == HandlerCode.BREATHING_RAW.ordinal()) {
            short[] breath = msg.getData().getShortArray("BreathingRaw");
            //System.out.println(Arrays.toString(breath));
            if (breath != null) {
                for (short b : breath) {
                    total[size++] = b;
                    if (size >= total.length) {
                        System.out.println(Arrays.toString(total));
                        size = 0;
                    }
                }
                System.out.println(size);
            }
        }*/

    }
}
