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
import com.billchen.sepsislindt.Pojo.User;
import com.billchen.sepsislindt.R;
import com.billchen.sepsislindt.Utils.LocalDB.UserDatabase;
import com.billchen.sepsislindt.databinding.ActivityLoginBinding;

import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.schedulers.Schedulers;

public class LoginActivity extends AppCompatActivity {

    private String username;
    private String password;

    private ActivityLoginBinding binding;
    private SharedPreferences sharedPref;

    private UserDao userDao;

    /*static {
        System.loadLibrary("get-predict");
    }

    private native double getPredict(double[] data);*/

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);


        //double[] data = {63, 21, 129, 90, 95, 100.10, 64, 29, 145, 40, 96, 100.10, 60, 31, 159, 51, 96,
        //        100.10, 63, 29, 155, 42, 96, 100.10, 1, -4, 3, 8, 2, -2, 1, -4, 3, 1, -4, 3, 1, -4, 3, 1, -4, 3};


        // set up date binding
        binding = DataBindingUtil.setContentView(this, R.layout.activity_login);

        // set up database for user
        UserDatabase userDatabase = UserDatabase.getInstance(this);
        userDao = userDatabase.userDao();

        // shared-preferences files that keep user info
        sharedPref = this.getSharedPreferences(
                "user", Context.MODE_PRIVATE
        );

        // check if there is a saved user for automatic login
        username = sharedPref.getString("username", "");
        password = sharedPref.getString("password", "");
        new Thread(() -> {
            autoLogin(username, password);
        }).start();

        // when the login button is clicked, pass email and password for verification
        if (binding.loginButton != null) {
            binding.loginButton.setOnClickListener(v -> {
                new Thread(() -> {
                    username = binding.emailInput.getText().toString();
                    password = binding.passwordInput.getText().toString();
                    login(username, password);
                }).start();
            });
        }

        // when the register button is clicked, pass email and password for registration
        if (binding.createButton != null) {
            binding.createButton.setOnClickListener(v -> {
                new Thread(() -> {
                    username = binding.emailInput.getText().toString();
                    password = binding.passwordInput.getText().toString();
                    register(username, password);
                }).start();
            });
        }
    }

    // show a toast saying "Login Failed"
    private void showLoginFailed() {
        try {
            Toast.makeText(getApplicationContext(), "Login Failed", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            Looper.prepare();
            Toast.makeText(getApplicationContext(), "Login Failed", Toast.LENGTH_SHORT).show();
            Looper.loop();
        }
    }

    // more like checking if the login info is valid
    private void autoLogin(String username, String password) {
        userDao.findByName(username, password)
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(users -> {
                    if (users.size() > 0) {
                        User user = users.get(0);
                        SharedPreferences.Editor editor = sharedPref.edit();
                        editor.putInt("uid", user.uid);
                        editor.putString("username", user.username);
                        editor.putString("password", user.password);
                        editor.commit();
                        Intent intent = new Intent(LoginActivity.this, MeasureActivity.class);
                        startActivity(intent);
                        finish();
                    }
                }, e -> {});
    };

    // check if login info is valid
    private void login(String username, String password) {
        userDao.findByName(username, password)
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(users -> {
                    if (users.size() > 0) {
                        User user = users.get(0);
                        SharedPreferences.Editor editor = sharedPref.edit();
                        editor.putInt("uid", user.uid);
                        editor.putString("username", user.username);
                        editor.putString("password", user.password);
                        editor.commit();
                        Intent intent = new Intent(LoginActivity.this, MeasureActivity.class);
                        startActivity(intent);
                    } else {
                        showLoginFailed();
                    }
                }, e-> {
                    showLoginFailed();
                });
    }

    // register the login info and bring user to the info page
    private void register(String username, String password) {
        User u = null;
        try {
            u = userDao.loadByLogin(username, password);
        } catch (Exception ignored) {}
        if (u == null) {
            SharedPreferences.Editor editor = sharedPref.edit();
            editor.putString("tmp_username", username);
            editor.putString("tmp_password", password);
            editor.commit();
            Intent intent = new Intent(LoginActivity.this, InfoActivity.class);
            startActivity(intent);
        } else {
            try {
                Toast.makeText(getApplicationContext(), "Register Failed", Toast.LENGTH_SHORT).show();
            } catch (Exception e) {
                Looper.prepare();
                Toast.makeText(getApplicationContext(), "Register Failed", Toast.LENGTH_SHORT).show();
                Looper.loop();
            }
        }
    }
}
