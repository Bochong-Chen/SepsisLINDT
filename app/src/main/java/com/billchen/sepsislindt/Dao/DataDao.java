package com.billchen.sepsislindt.Dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;

import com.billchen.sepsislindt.Pojo.Data;

import java.util.List;

import io.reactivex.Flowable;


@Dao
public interface DataDao {

    @Query("SELECT * FROM data")
    Flowable<List<Data>> getAll();

    @Query("SELECT * FROM data WHERE uid = :uid")
    List<Data> getAllByUid(int uid);

    @Query("SELECT * FROM data WHERE uid IN (:userIds)")
    List<Data> loadAllByIds(int[] userIds);

    @Insert
    void insert(Data data);

    @Delete
    void delete(Data data);
}
