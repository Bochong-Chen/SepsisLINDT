package com.billchen.spesislindt.Handlers;

import android.annotation.SuppressLint;

import java.util.EnumSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

@SuppressLint("UseSparseArrays")
public enum HandlerCode {
    HEART_RATE((int) 0x100),
    RESPIRATION_RATE((int) 0x101),
    SKIN_TEMPERATURE((int) 0x102),
    POSTURE((int) 0x103),
    PEAK_ACCLERATION((int) 0x104),
    BREATHING_RAW((int) 0x105),
    ECG((int) 0x106),
    Spo2((int) 0x107),

    GP_MSG_ID((int) 0x20),
    BREATHING_MSG_ID((int) 0x21),
    ECG_MSG_ID((int) 0x22),
    RtoR_MSG_ID((int) 0x24),
    ACCEL_100mg_MSG_ID((int) 0x2A),
    SUMMARY_MSG_ID((int) 0x2B),

    GP_HANDLER_ID((int) 0x20);


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
