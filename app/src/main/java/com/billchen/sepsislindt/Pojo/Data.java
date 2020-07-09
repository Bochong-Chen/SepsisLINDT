package com.billchen.sepsislindt.Pojo;


import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.PrimaryKey;
import androidx.room.TypeConverters;

import com.billchen.sepsislindt.Utils.LocalDB.UserDatabase.DateConverters;

import java.util.Date;

@Entity
public class Data {

    public Data() {}

    @Ignore
    public Data(int uid, double heartRate, double respRate, double sysBp,
                double diasBp, double spo2, double temperature) {
        this.uid = uid;
        this.heartRate = heartRate;
        this.respRate = respRate;
        this.sysBp = sysBp;
        this.diasBp = diasBp;
        this.spo2 = spo2;
        this.temperature = temperature;
        this.confidence = 1;
        this.createTime = new Date();
        this.updateTime = new Date();
    }

    @PrimaryKey(autoGenerate = true)
    public int id;

    public int uid;

    @ColumnInfo(name = "heart_rate")
    public double heartRate;

    @ColumnInfo(name = "resp_rate")
    public double respRate;

    @ColumnInfo(name = "sys_bp")
    public double sysBp;

    @ColumnInfo(name = "dias_bp")
    public double diasBp;

    public double spo2;

    public double temperature;

    public int confidence;

    @ColumnInfo(name = "create_time")
    @TypeConverters(DateConverters.class)
    public Date createTime;

    @ColumnInfo(name = "update_time")
    @TypeConverters(DateConverters.class)
    public Date updateTime;
}
