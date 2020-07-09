package com.billchen.sepsislindt.Pojo;


import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.Index;
import androidx.room.PrimaryKey;
import androidx.room.TypeConverters;

import com.billchen.sepsislindt.Utils.LocalDB.UserDatabase.DateConverters;

import java.util.Date;

@Entity(indices = {@Index(value = {"username"}, unique = true)})
public class User {

    public User() {}

    @Ignore
    public User(String username, String password) {
        this.username = username;
        this.password = password;
        this.createTime = new Date();
        this.updateTime = new Date();
    }

    @PrimaryKey(autoGenerate = true)
    public int uid;

    public String username;

    public String password;

    @ColumnInfo(name = "create_time")
    @TypeConverters(DateConverters.class)
    public Date createTime;

    @ColumnInfo(name = "update_time")
    @TypeConverters(DateConverters.class)
    public Date updateTime;
}
