package com.billchen.spesislindt;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

import com.billchen.spesislindt.Service.ConnectionService;

import java.util.logging.Level;
import java.util.logging.Logger;

import androidx.appcompat.app.AppCompatActivity;


@SuppressLint({"SetTextI18n", "HandlerLeak"})
public class MainActivity extends AppCompatActivity {

    private ConnectionService connectionService;
    private static Logger logger = Logger.getLogger("MainActivity");

    //UI elements
    private Button Spo2_Button = null;
    private Button Bioharness_Button = null;
    private TextView HRText = null;
    private TextView RespText = null;
    private TextView SpO2Text = null;

    //Code for handler communications
    private final int Spo2 = 0x127;
    private final int HEART_RATE = 0x100;
    private final int RESPIRATION_RATE = 0x101;
    private final int SKIN_TEMPERATURE = 0x102;
    private final int POSTURE = 0x103;
    private final int PEAK_ACCLERATION = 0x104;
    private final int BREATHING_RAW = 0x105;
    private final int ECG = 0x106;
    private final int UI = 0x107;

    //This is for C++ library, which will be included later
    // Used to load the 'native-lib' library on application startup.
    /*static {
        System.loadLibrary("native-lib");
    }*/


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //UI elements
        Spo2_Button = findViewById(R.id.Spo2_button);
        Bioharness_Button = findViewById(R.id.bioharness_button);
        HRText = findViewById(R.id.HRText);
        RespText = findViewById(R.id.RespText);
        SpO2Text = findViewById(R.id.SpO2Text);

        this.connectionService = ConnectionService.getInstance();

        //Attach listener to SPO2 Pulse Oximeter
        if (Spo2_Button != null) {
            Spo2_Button.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    boolean success = connectionService.connectSpo2(Spo2Handler);
                    //TODO: Make better connection handles
                    if (success) {
                        logger.log(Level.INFO, "SpO2 connection success.");
                    } else {
                        logger.log(Level.INFO, "SpO2 connection failure.");
                    }
                }
            });
        }

        //Attach listener to BioHarness
        if (Bioharness_Button != null) {
            Bioharness_Button.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    boolean success = connectionService.connectBioHarness(BioHarnessHandler);
                    //TODO: Make better connection handles
                    if (success) {
                        logger.log(Level.INFO, "BioHarness connection success.");
                    } else {
                        logger.log(Level.INFO, "BioHarness connection failure.");
                    }
                }
            });
        }
    }

        //The handler that gets messages and takes action depending on them
        final Handler Spo2Handler = new Handler() {
            public void handleMessage(final Message msg) {
                if (msg.what == Spo2) {
                    int SpO2 = msg.getData().getInt("SpO2");
                    SpO2Text.setText(String.valueOf(SpO2));
                }
            }
        };

        //The handler that gets messages and takes action depending on them
        final Handler BioHarnessHandler = new Handler() {
            public void handleMessage(final Message msg1) {
                if (msg1.what == HEART_RATE) {
                    int hr = msg1.getData().getInt("HeartRate");
                    HRText.setText(Integer.toString(hr));
                }

                if (msg1.what == RESPIRATION_RATE) {
                    double resp = msg1.getData().getDouble("RespirationRate");
                    RespText.setText(Double.toString(resp));
                }
            }
        };
    }

    //this is a C++ function from C++ Library.
    /*
    public native String stringFromJNI();*/
