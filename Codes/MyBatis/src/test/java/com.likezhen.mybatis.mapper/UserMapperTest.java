package com.likezhen.mybatis.mapper;


import com.likezhen.mybatis.model.Role;
import com.likezhen.mybatis.model.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.BeforeClass;
import org.junit.Test;

import java.io.IOException;
import java.io.Reader;

public class UserMapperTest {

    private static SqlSessionFactory sqlSessionFactory;

    @BeforeClass
    public static void init() {
        try {
            //通过 org.apache.ibatis.io.Resources 类读取配置文件
            Reader reader = Resources.getResourceAsReader("mybatis-config.xml");
            //使用 SqlSessionFactoryBuilder 实例化 SqlSessionFactory
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testGetUserById() {

        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            User user = mapper.getUserById(1);
            System.out.println(user);
        } finally {
            sqlSession.close();
        }
    }

    @Test
    public void testGetRoleById() {

        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            Role role = mapper.getRoleById(1);
            System.out.println(role);
        } finally {
            sqlSession.close();
        }
    }

    @Test
    public void testGetUserAndRoleById() {

        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            User user = mapper.getUserAndRoleById(1);
            System.out.println(user);
        } finally {
            sqlSession.close();
        }
    }

}
