package com.billchen.sepsislindt.Pojo;


import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.PrimaryKey;
import androidx.room.TypeConverters;

import com.billchen.sepsislindt.Utils.LocalDB.UserDatabase.DateConverters;

import java.util.Date;

@Entity(tableName = "user_info")
public class UserInfo {

    public UserInfo() {}

    @Ignore
    public UserInfo(int uid, String name,
                    double height, double weight, boolean sex) {
        this.uid = uid;
        this.name = name;
        this.height = height;
        this.weight = weight;
        this.sex = sex;
        this.createTime = new Date();
        this.updateTime = new Date();
    }

    @PrimaryKey
    public int uid;

    public String name;

    public double height;

    public double weight;

    public boolean sex;

    @ColumnInfo(name = "create_time")
    @TypeConverters(DateConverters.class)
    public Date createTime;

    @ColumnInfo(name = "update_time")
    @TypeConverters(DateConverters.class)
    public Date updateTime;
}
