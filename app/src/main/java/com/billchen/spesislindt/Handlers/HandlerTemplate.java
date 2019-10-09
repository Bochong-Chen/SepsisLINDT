package com.billchen.spesislindt.Handlers;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

import com.billchen.spesislindt.databinding.ActivityMainBinding;

public class HandlerTemplate extends Handler {

    // the data binding that allows access to UI elements
    ActivityMainBinding binding;

    // private constructor prevents multiple instances
    private HandlerTemplate(ActivityMainBinding binding) {
        super(Looper.getMainLooper());
        this.binding = binding;
    }

    // override the handle method
    @Override
    public void handleMessage(Message msg) {
        // put implementations here
        super.handleMessage(msg);
    }
}
