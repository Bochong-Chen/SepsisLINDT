package com.billchen.sepsislindt.Activities;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Looper;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.billchen.sepsislindt.Dao.UserDao;
import com.billchen.sepsislindt.Dao.UserInfoDao;
import com.billchen.sepsislindt.Pojo.User;
import com.billchen.sepsislindt.Pojo.UserInfo;
import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.Utils.LocalDB.UserDatabase;
import com.billchen.sepsislindt.Utils.LocalDB.UserInfoDatabase;
import com.billchen.sepsislindt.databinding.ActivityInfoBinding;

public class InfoActivity extends AppCompatActivity {

    private int uid;

    private String name;
    private int age;
    private boolean sex;
    private double height;
    private double weight;

    private ActivityInfoBinding binding;
    private SharedPreferences sharedPref;

    private UserInfoDao userInfoDao;
    private UserDao userDao;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_info);

        // set up date binding
        binding = DataBindingUtil.setContentView(this, R.layout.activity_info);

        // set up database for user
        UserDatabase userDatabase = UserDatabase.getInstance(this);
        userDao = userDatabase.userDao();

        UserInfoDatabase userInfoDatabase = UserInfoDatabase.getInstance(this);
        userInfoDao = userInfoDatabase.userInfoDao();


        // shared-preferences files that keep user info
        sharedPref = this.getSharedPreferences(
                "user", Context.MODE_PRIVATE
        );

        if (binding.nextButton != null) {
            binding.nextButton.setOnClickListener(v -> {
                new Thread(() -> {
                    name = binding.editTextName.getText().toString();
                    try {
                        age = Integer.parseInt(binding.editTextAge.getText().toString());
                        String gender = String.valueOf(binding.spinnerGender.getSelectedItem());
                        if (gender.equals("Male")) {
                            sex = true;
                        } else if (gender.equals("Female")) {
                            sex = false;
                        } else {
                            throw new Exception();
                        }
                        height = Double.parseDouble(binding.editTextHeight.getText().toString());
                        weight = Double.parseDouble(binding.editTextWeight.getText().toString());

                        // try register now
                        String username = sharedPref.getString("tmp_username", "");
                        String password = sharedPref.getString("tmp_password", "");
                        User u = null;
                        try {
                            u = userDao.loadByLogin(username, password);
                        } catch (Exception ignored) {}
                        if (u == null) {
                            User u1 = new User(username, password);
                            int uid = (int) userDao.insert(u1);
                            UserInfo u2 = new UserInfo(uid, name, height, weight, sex);
                            userInfoDao.insert(u2);
                            SharedPreferences.Editor editor = sharedPref.edit();
                            editor.putInt("uid", uid);
                            editor.putString("username", username);
                            editor.putString("password", password);
                            editor.remove("tmp_username");
                            editor.remove("tmp_password");
                            editor.commit();
                            Intent intent = new Intent(InfoActivity.this, MeasureActivity.class);
                            startActivity(intent);
                        } else {
                            try {
                                Toast.makeText(getApplicationContext(), "Register Error", Toast.LENGTH_SHORT).show();
                            } catch (Exception e1) {
                                Looper.prepare();
                                Toast.makeText(getApplicationContext(), "Register Error", Toast.LENGTH_SHORT).show();
                                Looper.loop();
                            }
                            onBackPressed();
                        }

                    } catch (Exception e) {
                        e.printStackTrace();
                        try {
                            Toast.makeText(getApplicationContext(), "Format Error", Toast.LENGTH_SHORT).show();
                        } catch (Exception e1) {
                            Looper.prepare();
                            Toast.makeText(getApplicationContext(), "Format Error", Toast.LENGTH_SHORT).show();
                            Looper.loop();
                        }
                    }
                }).start();
            });
        }

        if (binding.backButton != null) {
            binding.backButton.setOnClickListener(v -> {
                onBackPressed();
            });
        }
    }

    @Override
    public void onBackPressed() {
        SharedPreferences.Editor editor = sharedPref.edit();
        editor.remove("tmp_username");
        editor.remove("tmp_password");
        editor.commit();
        Intent intent = new Intent(InfoActivity.this, LoginActivity.class);
        startActivity(intent);
    }

}
