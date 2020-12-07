package com.billchen.sepsislindt.Activities;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.billchen.sepsislindt.Dao.DataDao;
import com.billchen.sepsislindt.Handlers.HandlerCode;
import com.billchen.sepsislindt.Pojo.Data;
import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.Service.ConnectionService;
import com.billchen.sepsislindt.Utils.LocalDB.DataDatabase;
import com.billchen.sepsislindt.databinding.ActivityMeasureBinding;

import java.util.logging.Level;
import java.util.logging.Logger;

@SuppressLint("DefaultLocale")
public class MeasureActivity extends AppCompatActivity {

    private double[] hr = new double[]{0,0,0};
    private int hrFlag;

    private double[] resp = new double[]{0,0,0};
    private int respFlag;

    private double[] sys = new double[]{0,0};
    private int sysFlag;

    private double[] dias = new double[]{0,0};
    private int diasFlag;

    private double[] spo2 = new double[]{0,0};
    private int spo2Flag;

    private ConnectionService connectionService;
    private static Logger logger = Logger.getLogger("MeasureActivity");

    private ActivityMeasureBinding binding;
    private SharedPreferences sharedPref;

    private DataDatabase dataDatabase;
    private DataDao dataDao;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_measure);

        // set up data binding
        binding = DataBindingUtil.setContentView(this, R.layout.activity_measure);

        // TODO: the data is not encrypted
        // get stored login info
        sharedPref = this.getSharedPreferences(
                "user", Context.MODE_PRIVATE
        );

        dataDatabase = DataDatabase.getInstance(this);
        dataDao = dataDatabase.dataDao();

        // service that connects all the devices
        this.connectionService = ConnectionService.getInstance();

        // connect pulse Oximeter when button clicked
        if (binding.buttonPulseOximeter != null) {
            binding.buttonPulseOximeter.setOnClickListener(v -> {
                // TODO: should not provide handler on this side
                boolean success = connectionService.connectSpo2(SPO2Handler);
                // TODO: Make better connection handles
                if (success) {
                    logger.log(Level.INFO, "SpO2 connection success.");
                } else {
                    logger.log(Level.INFO, "SpO2 connection failure.");
                }
            });
        }

        // connect bioharness when button clicked
        if (binding.buttonChestStrap != null) {
            binding.buttonChestStrap.setOnClickListener(v -> {
                // TODO: should not provide handler on this side
                boolean success = connectionService.connectBioHarness(BHHandler);
                // TODO: Make better connection handles
                if (success) {
                    logger.log(Level.INFO, "BioHarness connection success.");
                } else {
                    logger.log(Level.INFO, "BioHarness connection failure.");
                }
            });
        }

        // connect blood pressure cuff when button clicked
        if (binding.buttonBloodPressure != null) {
            binding.buttonBloodPressure.setOnClickListener(v -> {
                // TODO: should not provide handler on this side
                boolean success = connectionService.connectBloodPressure(this, BPHandler);
                // TODO: Make better connection handles
                if (success) {
                    logger.log(Level.INFO, "BP connection success.");
                } else {
                    logger.log(Level.INFO, "BP connection failure.");
                }
            });
        }

        // jump to audio intake page when clicked
        if (binding.buttonMicrophone != null) {
            binding.buttonMicrophone.setOnClickListener(v -> {
                Intent intent = new Intent(MeasureActivity.this, AudioActivity.class);
                startActivity(intent);
            });
        }

        // jump to camera intake page when clicked
        if (binding.buttonFlashCamera != null) {
            binding.buttonFlashCamera.setOnClickListener(v -> {
                Intent intent = new Intent(MeasureActivity.this, CameraActivity.class);
                startActivity(intent);
            });
        }

        // jump to seek camera app when clicked
        if (binding.buttonIR != null) {
            binding.buttonIR.setOnClickListener(v -> {
                Intent launchIntent = getPackageManager().getLaunchIntentForPackage("com.example.seeksimple");
                if (launchIntent != null) {
                    startActivity(launchIntent);
                } else {
                    Toast.makeText(MeasureActivity.this, "There is no package available in android", Toast.LENGTH_LONG).show();
                }
            });
        }

        // record data and jump to result page when clicked
        if (binding.buttonMeasureResults != null) {
            binding.buttonMeasureResults.setOnClickListener(v -> {
                try {
                    double _hr = Double.parseDouble(binding.editTextHeartRate.getText().toString());
                    double _resp = Double.parseDouble(binding.editTextRespiratoryRate.getText().toString());
                    double _sys = Double.parseDouble(binding.editTextSystolicPressure.getText().toString());
                    double _dias = Double.parseDouble(binding.editTextDiastolicPressure.getText().toString());
                    double _spo2 = Double.parseDouble(binding.editTextSpO2.getText().toString());
                    double _temp = Double.parseDouble(binding.editTextTemperature.getText().toString());
                    int _uid = sharedPref.getInt("uid", -1);
                    Data d = new Data(_uid, _hr, _resp, _sys, _dias, _spo2, _temp);
                    new Thread(() -> {
                        dataDao.insert(d);
                        try {
                            Toast.makeText(getApplicationContext(), "Measurement Success", Toast.LENGTH_SHORT).show();
                        } catch (Exception e1) {
                            Looper.prepare();
                            Toast.makeText(getApplicationContext(), "Measurement Success", Toast.LENGTH_SHORT).show();
                            Looper.loop();
                        }
                    }).start();

                } catch (Exception e) {
                    try {
                        Toast.makeText(getApplicationContext(), "Measurement Failed", Toast.LENGTH_SHORT).show();
                    } catch (Exception e1) {
                        Looper.prepare();
                        Toast.makeText(getApplicationContext(), "Measurement Failed", Toast.LENGTH_SHORT).show();
                        Looper.loop();
                    }
                }
            });
        }

        // jump to result page when clicked
        if (binding.buttonDisplayResults != null) {
            binding.buttonDisplayResults.setOnClickListener(v -> {
                Intent intent = new Intent(MeasureActivity.this, ResultActivity.class);
                startActivity(intent);
            });
        }

        // determine which way to get hr data
        // TODO: there should be an enum for all the states
        if (binding.spinnerHeartRate != null) {
            binding.spinnerHeartRate.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    String option = binding.spinnerHeartRate.getSelectedItem().toString();
                    if (option.equals("Manual Input")) {
                        hrFlag = 2;
                        binding.editTextHeartRate.setFocusableInTouchMode(true);
                        binding.editTextHeartRate.setText(String.format("%.2f", hr[hrFlag]));
                    } else {
                        try {
                            double data = Double.parseDouble(binding.editTextHeartRate.getText().toString());
                            hr[hrFlag] = data;
                        } catch (Exception ignored) {}
                        binding.editTextHeartRate.setFocusable(false);
                        switch (option) {
                            case "Chest Strap":
                                hrFlag = 0;
                                break;
                            case "Flash Camera":
                                hrFlag = 1;
                                break;
                        }
                        binding.editTextHeartRate.setText(String.format("%.2f", hr[hrFlag]));
                    }
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                    hrFlag = 3;
                    binding.editTextHeartRate.setFocusableInTouchMode(true);
                    binding.editTextHeartRate.setText(String.format("%.2f", hr[hrFlag]));
                }
            });
        }

        // determine which way to get respiratory rate data
        // TODO: there should be an enum for all the states
        if (binding.spinnerRespiratoryRate != null) {
            binding.spinnerRespiratoryRate.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    String option = binding.spinnerRespiratoryRate.getSelectedItem().toString();
                    if (option.equals("Manual Input")) {
                        respFlag = 2;
                        binding.editTextRespiratoryRate.setFocusableInTouchMode(true);
                        binding.editTextRespiratoryRate.setText(String.valueOf(resp[respFlag]));
                    } else {
                        try {
                            double data = Double.parseDouble(binding.editTextRespiratoryRate.getText().toString());
                            resp[respFlag] = data;
                        } catch (Exception ignored) {}
                        binding.editTextRespiratoryRate.setFocusable(false);
                        switch (option) {
                            case "Chest Strap":
                                respFlag = 0;
                                break;
                            case "Microphone":
                                respFlag = 1;
                                break;
                        }
                        binding.editTextRespiratoryRate.setText(String.format("%.2f", resp[respFlag]));
                    }
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                    respFlag = 2;
                    binding.editTextRespiratoryRate.setFocusableInTouchMode(true);
                    binding.editTextRespiratoryRate.setText(String.format("%.2f", resp[respFlag]));
                }
            });
        }

        // determine which way to get systolic blood pressure data
        // TODO: there should be an enum for all the states
        if (binding.spinnerSystolicPressure != null) {
            binding.spinnerSystolicPressure.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    String option = binding.spinnerSystolicPressure.getSelectedItem().toString();
                    if (option.equals("Manual Input")) {
                        sysFlag = 1;
                        binding.editTextSystolicPressure.setFocusableInTouchMode(true);
                        binding.editTextSystolicPressure.setText(String.valueOf(sys[sysFlag]));
                    } else {
                        try {
                            double data = Double.parseDouble(binding.editTextSystolicPressure.getText().toString());
                            sys[sysFlag] = data;
                        } catch (Exception ignored) {}
                        binding.editTextSystolicPressure.setFocusable(false);
                        sysFlag = 0;
                        }
                        binding.editTextSystolicPressure.setText(String.format("%.2f", sys[sysFlag]));
                    }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                    respFlag = 1;
                    binding.editTextSystolicPressure.setFocusableInTouchMode(true);
                    binding.editTextSystolicPressure.setText(String.format("%.2f", sys[sysFlag]));
                }
            });
        }

        // determine which way to get diastolic blood pressure data
        // TODO: there should be an enum for all the states
        if (binding.spinnerDiastolicPressure != null) {
            binding.spinnerDiastolicPressure.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    String option = binding.spinnerDiastolicPressure.getSelectedItem().toString();
                    if (option.equals("Manual Input")) {
                        diasFlag = 1;
                        binding.editTextDiastolicPressure.setFocusableInTouchMode(true);
                        binding.editTextDiastolicPressure.setText(String.valueOf(dias[diasFlag]));
                    } else {
                        try {
                            double data = Double.parseDouble(binding.editTextDiastolicPressure.getText().toString());
                            dias[diasFlag] = data;
                        } catch (Exception ignored) {}
                        binding.editTextDiastolicPressure.setFocusable(false);
                        diasFlag = 0;
                    }
                    binding.editTextDiastolicPressure.setText(String.format("%.2f", dias[diasFlag]));
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                    diasFlag = 1;
                    binding.editTextDiastolicPressure.setFocusableInTouchMode(true);
                    binding.editTextDiastolicPressure.setText(String.format("%.2f", dias[diasFlag]));
                }
            });
        }

        // determine which way to get spo2 data
        // TODO: there should be an enum for all the states
        if (binding.spinnerSpO2 != null) {
            binding.spinnerSpO2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    String option = binding.spinnerSpO2.getSelectedItem().toString();
                    if (option.equals("Manual Input")) {
                        spo2Flag = 1;
                        binding.editTextSpO2.setFocusableInTouchMode(true);
                        binding.editTextSpO2.setText(String.valueOf(dias[diasFlag]));
                    } else {
                        try {
                            double data = Double.parseDouble(binding.editTextSpO2.getText().toString());
                            spo2[spo2Flag] = data;
                        } catch (Exception ignored) {}
                        binding.editTextSpO2.setFocusable(false);
                        spo2Flag = 0;
                    }
                    binding.editTextSpO2.setText(String.format("%.2f", spo2[spo2Flag]));
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                    spo2Flag = 1;
                    binding.editTextSpO2.setFocusableInTouchMode(true);
                    binding.editTextSpO2.setText(String.format("%.2f", spo2[spo2Flag]));
                }
            });
        }
    }

    // initialization
    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);

        double resp1 = intent.getDoubleExtra("breathing", -1);
        if (resp1 != -1) {
            resp[1] = resp1;
            if (respFlag == 1) {
                binding.editTextRespiratoryRate.setText(String.format("%.2f", resp1));
            }
        }

        double hr1 = intent.getDoubleExtra("hr", -1);
        if (hr1 != -1) {
            hr[1] = hr1;
            if (hrFlag == 1) {
                binding.editTextHeartRate.setText(String.format("%.2f", hr1));
            }
        }
    }

    // handler for incoming data
    final Handler BHHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            if (msg.what == HandlerCode.HEART_RATE.ordinal()) {
                double hr1 = (double) msg.getData().getInt("HeartRate");
                hr[0] = hr1;
                if (hrFlag == 0) {
                    binding.editTextHeartRate.setText(String.format("%.2f", hr1));
                }
            }

            if (msg.what == HandlerCode.RESPIRATION_RATE.ordinal()) {
                double resp1 = msg.getData().getDouble("RespirationRate");
                resp[0] = resp1;
                if (respFlag == 0) {
                    binding.editTextRespiratoryRate.setText(String.format("%.2f", resp1));
                }
            }
        }
    };

    // handler for incoming data
    final Handler SPO2Handler = new Handler() {

        @Override
        public void handleMessage(Message msg) {
            if (msg.what == HandlerCode.Spo2.ordinal()) {
                double spo21 = (double) msg.getData().getInt("SpO2");
                spo2[0] = spo21;
                if (spo2Flag == 0) {
                    binding.editTextSpO2.setText(String.format("%.2f", spo21));
                }
            }
        }
    };

    // handler for incoming data
    final Handler BPHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            if (msg.what == 2) {
                sys[sysFlag] = msg.getData().getDouble("Systolic");
                dias[diasFlag] = msg.getData().getDouble("Diastolic");
                if (sysFlag == 0) {
                    binding.editTextSystolicPressure.setText(String.format("%.2f", sys[sysFlag]));
                }
                if (diasFlag == 0) {
                    binding.editTextDiastolicPressure.setText(String.format("%.2f", dias[diasFlag]));
                }
            }
        }
    };
}
