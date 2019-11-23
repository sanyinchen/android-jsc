package com.sanyinchen.jsc;

import androidx.annotation.NonNull;

public enum Bridge {
    INS;

    static {

        System.loadLibrary("c++_shared");
        System.loadLibrary("jsc");
        System.loadLibrary("bridge");
    }

    public native String stringFromJNI(@NonNull String content);
}
