package com.billchen.sepsislindt.Dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;

import com.billchen.sepsislindt.Pojo.UserInfo;

import java.util.List;

import io.reactivex.Flowable;


@Dao
public interface UserInfoDao {

    @Query("SELECT * FROM user_info")
    Flowable<List<UserInfo>> getAll();

    @Query("SELECT * FROM user_info WHERE uid IN (:userIds)")
    List<UserInfo> loadAllByIds(int[] userIds);

    @Insert
    void insert(UserInfo userInfo);

    @Delete
    void delete(UserInfo userInfo);
}
