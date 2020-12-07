package com.billchen.sepsislindt.Handlers;

import android.annotation.SuppressLint;

import java.util.EnumSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

// code for message parsing
@SuppressLint("UseSparseArrays")
public enum HandlerCode {
    HEART_RATE(0x100),
    RESPIRATION_RATE(0x101),
    SKIN_TEMPERATURE(0x102),
    POSTURE(0x103),
    PEAK_ACCLERATION(0x104),
    BREATHING_RAW(0x105),
    ECG(0x106),
    Spo2(0x107),

    GP_MSG_ID(0x20),
    BREATHING_MSG_ID(0x21),
    ECG_MSG_ID(0x22),
    RtoR_MSG_ID(0x24),
    ACCEL_100mg_MSG_ID(0x2A),
    SUMMARY_MSG_ID(0x2B);


    //GP_HANDLER_ID((int) 0x20);


    private static final Map<Integer, HandlerCode> lookup = new HashMap<>();
    private final int code;

    HandlerCode(int code) {
        this.code = code;
    }

    public static HandlerCode get(int code) {
        return lookup.get(code);
    }

    static {
        Iterator i$ = EnumSet.allOf(HandlerCode.class).iterator();
        while(i$.hasNext()) {
            HandlerCode handlerCode = (HandlerCode) i$.next();
            lookup.put(handlerCode.code, handlerCode);
        }
    }
}
