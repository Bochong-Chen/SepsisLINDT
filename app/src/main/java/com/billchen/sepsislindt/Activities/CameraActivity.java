package com.billchen.sepsislindt.Activities;

import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.hardware.Camera;
import android.os.Bundle;
import android.os.PowerManager;
import android.view.SurfaceHolder;
import android.widget.ProgressBar;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.Utils.ImageProcessing;
import com.billchen.sepsislindt.databinding.ActivityCameraBinding;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public class CameraActivity extends AppCompatActivity {

    //UI initialization
    private ActivityCameraBinding binding;

    //Variables Initialization
    private static final AtomicBoolean processing = new AtomicBoolean(false);
    private static SurfaceHolder previewHolder = null;
    private static Camera camera = null;
    private static PowerManager.WakeLock wakeLock = null;

    //Toast
    private Toast mainToast;

    //ProgressBar
    private ProgressBar ProgHeart;
    public int ProgP =0;
    public int inc=0;

    //Beats variable
    public int Beats=0;
    public double bufferAvgB=0;

    //Freq + timer variable
    private static long startTime = 0;
    private double SamplingFreq;

    //SPO2 variable
    private static Double [] RedBlueRatio ;
    public int o2;
    double Stdr=0;
    double Stdb=0;
    double sumred=0;
    double sumblue=0;

    //BloodPressure variables
    public double Gen, Age, Hei, Wei;
    public double Q =4.5;
    private static int SP = 0, DP = 0;

    //Arraylist
    public ArrayList<Double> GreenAvgList=new ArrayList<Double>();
    public ArrayList<Double> RedAvgList=new ArrayList<Double>();
    public ArrayList<Double> BlueAvgList=new ArrayList<Double>();
    public ArrayList<Double> AvgList = new ArrayList<>();
    public int counter = 0;

    static {
        System.loadLibrary("get-result");
    }

    private native double getResult(double[] array, double fs, boolean flag);



    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera);

        binding = DataBindingUtil.setContentView(this, R.layout.activity_camera);

        Bundle extras = getIntent().getExtras();

        //Get parameters from Db
        //TODO: Assign temporary numbers
        Hei = 174;
        Wei = 78;
        Age = 21;
        Gen = 1;

        if(Gen == 1){
            Q=5;
        }

        // XML - Java Connecting
        previewHolder = binding.preview.getHolder();
        previewHolder.addCallback(surfaceCallback);
        previewHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
        ProgHeart = binding.HRPB;
        ProgHeart.setProgress(0);

        // WakeLock Initialization : Forces the phone to stay On
        PowerManager pm = (PowerManager) getSystemService(Context.POWER_SERVICE);
        wakeLock = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, "CameraActivity:DoNotDimScreen");
    }

    //Prevent the system from restarting your activity during certain configuration changes,
    // but receive a callback when the configurations do change, so that you can manually update your activity as necessary.
    //such as screen orientation, keyboard availability, and language

    @Override
    public void onConfigurationChanged(@NonNull Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    //Wakelock + Open device camera + set orientation to 90 degree
    //store system time as a start time for the analyzing process
    //your activity to start interacting with the user.
    @Override
    public void onResume() {
        super.onResume();

        wakeLock.acquire(600000);

        camera = Camera.open();

        camera.setDisplayOrientation(90);

        startTime = System.currentTimeMillis();
    }

    //call back the frames then release the camera + wakelock and Initialize the camera to null
    //Called as part of the activity lifecycle when an activity is going into the background, but has not (yet) been killed. The counterpart to onResume().
    //When activity B is launched in front of activity A,
    //this callback will be invoked on A. B will not be created until A's onPause() returns, so be sure to not do anything lengthy here.
    @Override
    public void onPause() {
        super.onPause();
        wakeLock.release();
        camera.setPreviewCallback(null);
        camera.stopPreview();
        camera.release();
        camera = null;

    }

    //getting frames data from the camera and start the measuring process
    private Camera.PreviewCallback previewCallback = new Camera.PreviewCallback() {

        @Override
        public void onPreviewFrame(byte[] data, Camera cam) {
            //if data or size == null ****
            if (data == null) throw new NullPointerException();
            Camera.Size size = cam.getParameters().getPreviewSize();
            if (size == null) throw new NullPointerException();

            //Atomically sets the value to the given updated value if the current value == the expected value.
            if (!processing.compareAndSet(false, true)) return;

            //put width + height of the camera inside the variables
            int width = size.width;
            int height = size.height;

            //RGB intensities initialization
            double GreenAvg;
            double RedAvg;
            double BlueAvg;



            byte[] tmp = data.clone();
            double sum = 0;
            int count = 0;
            for (byte i: tmp) {
                sum += (double) i;
                count++;
            }
            double avg = sum / count;

            AvgList.add(avg);



            //Getting Red intensity after applying image processing on frame data, 1 stands for red
            RedAvg=ImageProcessing.decodeYUV420SPtoRedBlueGreenAvg(
                    data.clone(), width, height,1);
            //Summing Red intensity for the whole period of recording which is 30 second


            ++counter; //counts the number of frames for the whole period of recording " 30 s "

            //To check if we got a good red intensity to process if not return to the condition and set it again until we get a good red intensity
            if (RedAvg < 200) {
                inc=0;
                ProgP=inc;
                counter=0;
                ProgHeart.setProgress(ProgP);
                processing.set(false);
            }


            long endTime = System.currentTimeMillis();
            double totalTimeInSecs = (endTime - startTime) / 1000d; //convert time to seconds to be compared with 30 seconds
            if (totalTimeInSecs >= 30) {

                SamplingFreq =  (counter/totalTimeInSecs);

                double[] jdata = new double[AvgList.size()];
                int idx = 0;
                for (double data_i: AvgList) {
                    jdata[idx] = data_i;
                    idx += 1;
                }

                double result = getResult(jdata, SamplingFreq, true);
                Intent intent = new Intent(CameraActivity.this, MeasureActivity.class);
                intent.putExtra("hr", result);
                startActivity(intent);
                finish();
            }

            //keeps incrementing the progress bar and keeps the loop until we have a valid values for the previous if state
            if(RedAvg != 0){
                ProgP=inc++/30;
                ProgHeart.setProgress(ProgP);}
            processing.set(false);
        }
    };

    private SurfaceHolder.Callback surfaceCallback = new SurfaceHolder.Callback() {

        @Override
        public void surfaceCreated(SurfaceHolder holder) {
            try {
                camera.setPreviewDisplay(previewHolder);
                camera.setPreviewCallback(previewCallback);
            } catch (Throwable t) {
                t.printStackTrace();
            }
        }

        @Override
        public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

            Camera.Parameters parameters = camera.getParameters();
            parameters.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);

            Camera.Size size = getSmallestPreviewSize(width, height, parameters);
            if (size != null) {
                parameters.setPreviewSize(size.width, size.height);
            }

            camera.setParameters(parameters);
            camera.startPreview();
        }

        @Override
        public void surfaceDestroyed(SurfaceHolder holder) {
        }
    };

    private static Camera.Size getSmallestPreviewSize(int width, int height, Camera.Parameters parameters) {
        Camera.Size result = null;

        for (Camera.Size size : parameters.getSupportedPreviewSizes()) {
            if (size.width <= width && size.height <= height) {
                if (result == null) {
                    result = size;
                } else {
                    int resultArea = result.width * result.height;
                    int newArea = size.width * size.height;
                    if (newArea < resultArea) result = size;
                }
            }
        }

        return result;
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        Intent i = new Intent(CameraActivity.this, MeasureActivity.class);
        startActivity(i);
        finish();
    }
}
