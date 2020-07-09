package com.billchen.sepsislindt.Dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;

import com.billchen.sepsislindt.Pojo.User;

import java.util.List;

import io.reactivex.Flowable;


@Dao
public interface UserDao {

    @Query("SELECT * FROM user WHERE username LIKE :username AND " +
            "password LIKE :password LIMIT 1")
    Flowable<List<User>> findByName(String username, String password);

    @Insert
    long insert(User user);

    @Query("SELECT * FROM user WHERE username = :username AND " +
            "password = :password LIMIT 1")
    User loadByLogin(String username, String password);




    @Query("SELECT * FROM user WHERE uid IN (:userIds)")
    List<User> loadAllByIds(int[] userIds);

    @Query("SELECT * FROM user")
    Flowable<List<User>> getAll();



    @Delete
    void delete(User user);
}