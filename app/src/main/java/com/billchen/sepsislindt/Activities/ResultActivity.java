package com.billchen.sepsislindt.Activities;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.billchen.sepsislindt.Dao.DataDao;
import com.billchen.sepsislindt.Pojo.Data;
import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.Utils.LocalDB.DataDatabase;
import com.billchen.sepsislindt.databinding.ActivityResultBinding;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.LineGraphSeries;

import java.util.ArrayList;
import java.util.List;

public class ResultActivity extends AppCompatActivity {

    ActivityResultBinding binding;
    private SharedPreferences sharedPref;

    private DataDatabase dataDatabase;
    private DataDao dataDao;

    private ArrayList<Double> hrArray;
    private ArrayList<Double> respArray;
    private ArrayList<Double> sysArray;
    private ArrayList<Double> diasArray;
    private ArrayList<Double> spo2Array;
    private ArrayList<Double> tempArray;

    double result = -100;

    // load C++ library
    static {
        System.loadLibrary("get-predict");
    }

    // C++ native method
    private native double getPredict(double[] data);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);

        // set up data binding
        binding = DataBindingUtil.setContentView(this, R.layout.activity_result);

        // get stored login data
        sharedPref = this.getSharedPreferences(
                "user", Context.MODE_PRIVATE
        );

        // prepare database
        dataDatabase = DataDatabase.getInstance(this);
        dataDao = dataDatabase.dataDao();

        int _uid = sharedPref.getInt("uid", -1);

        hrArray = new ArrayList<>();
        respArray = new ArrayList<>();
        sysArray = new ArrayList<>();
        diasArray = new ArrayList<>();
        spo2Array = new ArrayList<>();
        tempArray = new ArrayList<>();

        new Thread(() -> {
            List<Data> datas = dataDao.getAllByUid(_uid);
            for (Data data: datas) {
                hrArray.add(data.heartRate);
                respArray.add(data.respRate);
                sysArray.add(data.sysBp);
                diasArray.add(data.diasBp);
                spo2Array.add(data.spo2);
                tempArray.add(data.temperature);
            }

            // format data
            if (hrArray.size() >= 4) {
                double[] jdata = new double[42];
                int idx = 0;
                double[] hrDiff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = hrArray.get(hrArray.size() - 4 + i);
                    if (i < 3) {
                        hrDiff[i] = hrArray.get(hrArray.size() - 4 + i) - hrArray.get(hrArray.size() - 3 + i);
                    }
                }
                for (double hrdiff : hrDiff) {
                    jdata[idx++] = hrdiff;
                }

                double[] respDiff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = respArray.get(respArray.size() - 4 + i);
                    if (i < 3) {
                        respDiff[i] = respArray.get(respArray.size() - 4 + i) - respArray.get(respArray.size() - 3 + i);
                    }
                }
                for (double respdiff : respDiff) {
                    jdata[idx++] = respdiff;
                }

                double[] sysDiff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = sysArray.get(sysArray.size() - 4 + i);
                    if (i < 3) {
                        sysDiff[i] = sysArray.get(sysArray.size() - 4 + i) - sysArray.get(sysArray.size() - 3 + i);
                    }
                }
                for (double sysdiff : sysDiff) {
                    jdata[idx++] = sysdiff;
                }

                double[] diasDiff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = diasArray.get(diasArray.size() - 4 + i);
                    if (i < 3) {
                        diasDiff[i] = diasArray.get(diasArray.size() - 4 + i) - diasArray.get(diasArray.size() - 3 + i);
                    }
                }
                for (double diasdiff : diasDiff) {
                    jdata[idx++] = diasdiff;
                }

                double[] spo2Diff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = spo2Array.get(spo2Array.size() - 4 + i);
                    if (i < 3) {
                        spo2Diff[i] = spo2Array.get(spo2Array.size() - 4 + i) - spo2Array.get(spo2Array.size() - 3 + i);
                    }
                }
                for (double spo2diff : spo2Diff) {
                    jdata[idx++] = spo2diff;
                }

                double[] tempDiff = new double[3];
                for (int i = 0; i < 4; i++) {
                    jdata[idx++] = tempArray.get(tempArray.size() - 4 + i);
                    if (i < 3) {
                        tempDiff[i] = tempArray.get(tempArray.size() - 4 + i) - tempArray.get(tempArray.size() - 3 + i);
                    }
                }
                for (double tempdiff : tempDiff) {
                    jdata[idx++] = tempdiff;
                }

                // get prediction result
                double _result = getPredict(jdata);
                if (_result == 1) {
                    binding.textViewResult.setText("Probability of Sepsis: High");
                    binding.textViewResult.setTextColor(Color.RED);
                } else if (_result == 2) {
                    binding.textViewResult.setText("Probability of Spesis: Low");
                    binding.textViewResult.setTextColor(Color.GREEN);
                }
            } else {
                binding.textViewResult.setText("Probability of Sepsis: Inconclusive");
                binding.textViewResult.setTextColor(Color.GRAY);
            }

            // prepare data for display
            DataPoint[] hr_data = new DataPoint[hrArray.size()];
            DataPoint[] resp_data = new DataPoint[respArray.size()];
            DataPoint[] sys_data = new DataPoint[sysArray.size()];
            DataPoint[] dias_data = new DataPoint[diasArray.size()];
            DataPoint[] spo2_data = new DataPoint[spo2Array.size()];
            DataPoint[] temp_data = new DataPoint[tempArray.size()];

            for (int i = 0; i < hrArray.size(); i++) {
                hr_data[i] = new DataPoint(i, hrArray.get(i));
                resp_data[i] = new DataPoint(i, respArray.get(i));
                sys_data[i] = new DataPoint(i, sysArray.get(i));
                dias_data[i] = new DataPoint(i, diasArray.get(i));
                spo2_data[i] = new DataPoint(i, spo2Array.get(i));
                temp_data[i] = new DataPoint(i, tempArray.get(i));
            }

            // add data points to the graph
            binding.hrGraph.addSeries(new LineGraphSeries<>(hr_data));
            binding.respGraph.addSeries(new LineGraphSeries<>(resp_data));
            binding.sysGraph.addSeries(new LineGraphSeries<>(sys_data));
            binding.diasGraph.addSeries(new LineGraphSeries<>(dias_data));
            binding.spo2Graph.addSeries(new LineGraphSeries<>(spo2_data));
            binding.tempGraph.addSeries(new LineGraphSeries<>(temp_data));

            binding.hrGraph.setTitle("Heart Rate");
            binding.respGraph.setTitle("Respiratory Rate");
            binding.sysGraph.setTitle("Systolic Blood Pressure");
            binding.diasGraph.setTitle("Diastolic Blood Pressure");
            binding.spo2Graph.setTitle("SpO2");
            binding.tempGraph.setTitle("Temperature");
        }).start();

        for (int i = 0; i < 1000000; i++) {
            if (result > -5) {
                if (result == 1) {
                    binding.textViewResult.setText("Probability of Sepsis: High");
                    binding.textViewResult.setTextColor(Color.RED);
                } else if (result == 2) {
                    binding.textViewResult.setText("Probability of Spesis: Low");
                    binding.textViewResult.setTextColor(Color.GREEN);
                } else {
                    binding.textViewResult.setText("Probability of Sepsis: Inconclusive");
                    binding.textViewResult.setTextColor(Color.GRAY);
                }
            }
        }
    }

}
