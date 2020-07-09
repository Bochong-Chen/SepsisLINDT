package com.billchen.sepsislindt.Utils.LocalDB;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;
import androidx.room.TypeConverter;

import com.billchen.sepsislindt.Dao.UserInfoDao;
import com.billchen.sepsislindt.Pojo.UserInfo;

import java.util.Date;

@Database(entities = {UserInfo.class}, version = 2, exportSchema = false)
public abstract class UserInfoDatabase extends RoomDatabase {

    private static final String DB_NAME = "user_info_db";
    private static UserInfoDatabase instance;

    public abstract UserInfoDao userInfoDao();

    public static synchronized UserInfoDatabase getInstance(Context context) {
        if (instance == null) {
            instance = Room.databaseBuilder(context.getApplicationContext(),
                    UserInfoDatabase.class, DB_NAME)
                    .fallbackToDestructiveMigration()
                    .build();
        }
        return instance;
    }

    public static class DateConverters {
        @TypeConverter
        public Date fromTimestamp(Long value) {
            return value == null ? null : new Date(value);
        }

        @TypeConverter
        public Long dateToTimestamp(Date date) {
            if (date == null) {
                return null;
            } else {
                return date.getTime();
            }
        }
    }
}