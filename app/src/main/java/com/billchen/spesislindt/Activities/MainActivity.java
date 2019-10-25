package com.billchen.spesislindt;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;

import com.billchen.spesislindt.Handlers.BioharnessHandler;
import com.billchen.spesislindt.Handlers.SpO2Handler;
import com.billchen.spesislindt.Service.ConnectionService;
import com.billchen.spesislindt.databinding.ActivityMainBinding;

import java.util.logging.Level;
import java.util.logging.Logger;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;


@SuppressLint({"SetTextI18n", "HandlerLeak"})
public class MainActivity extends AppCompatActivity {

    private ConnectionService connectionService;
    private static Logger logger = Logger.getLogger("MainActivity");

    //UI data binding
    private ActivityMainBinding binding;


    //This is for C++ library, which will be included later
    // Used to load the 'native-lib' library on application startup.
    /*static {
        System.loadLibrary("native-lib");
    }*/


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //UI bindings
        binding = DataBindingUtil.setContentView(this, R.layout.activity_main);

        this.connectionService = ConnectionService.getInstance();

        //Attach listener to SPO2 Pulse Oximeter
        if (binding.spo2Button != null) {
            binding.spo2Button.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    SpO2Handler spO2Handler = new SpO2Handler(binding);
                    boolean success = connectionService.connectSpo2(spO2Handler);
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
        if (binding.bioharnessButton != null) {
            binding.bioharnessButton.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    BioharnessHandler bioharnessHandler = new BioharnessHandler(binding);
                    boolean success = connectionService.connectBioHarness(bioharnessHandler);
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


    //this is a C++ function from C++ Library.
    /*
    public native String stringFromJNI();*/

}
