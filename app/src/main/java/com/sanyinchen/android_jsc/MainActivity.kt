package com.sanyinchen.android_jsc

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import com.sanyinchen.jsc.Bridge

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        var content = "function sum(a,b) { return a+b; };\n 'res is : '+sum(1,2)"
        val editText = findViewById<EditText>(R.id.input_edit_text)
        editText.setText(content)
        val button = findViewById<Button>(R.id.func_click);
        val show = findViewById<TextView>(R.id.res_text)
        button.setOnClickListener {
            content = editText.text.toString()
            Log.d("src_test", "content:" + content)
            show.setText(Bridge.INS.stringFromJNI(content))
        }
    }
}
