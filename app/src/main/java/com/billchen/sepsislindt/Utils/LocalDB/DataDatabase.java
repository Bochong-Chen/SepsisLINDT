package com.billchen.sepsislindt.Utils.LocalDB;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;
import androidx.room.TypeConverter;

import com.billchen.sepsislindt.Dao.DataDao;
import com.billchen.sepsislindt.Pojo.Data;

import java.util.Date;

@Database(entities = {Data.class}, version = 2, exportSchema = false)
public abstract class DataDatabase extends RoomDatabase {

    private static final String DB_NAME = "data_db";
    private static DataDatabase instance;

    public abstract DataDao dataDao();

    public static synchronized DataDatabase getInstance(Context context) {
        if (instance == null) {
            instance = Room.databaseBuilder(context.getApplicationContext(),
                    DataDatabase.class, DB_NAME)
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