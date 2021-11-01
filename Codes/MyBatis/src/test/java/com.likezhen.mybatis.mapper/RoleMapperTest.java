package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Role;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.BeforeClass;
import org.junit.Test;

import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;

public class RoleMapperTest {
    private static SqlSessionFactory sqlSessionFactory;

    @BeforeClass
    public static void init() {
        try {
            Reader reader = Resources.getResourceAsReader("mybatis-config.xml");
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testGetRoleById1() {
        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {

            RoleMapper mapper = sqlSession.getMapper(RoleMapper.class);
            Role role1 = mapper.getRoleById(1);

            Role role2 = mapper.getRoleById(1);

            System.out.println(role1 == role2);
        } finally {
            sqlSession.close();
        }
    }

    @Test
    public void testGetRoleById2() {
        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {

            RoleMapper mapper = sqlSession.getMapper(RoleMapper.class);
            Role role = mapper.dynamicSqlChoose(1);
            System.out.println(role);
        } finally {
            sqlSession.close();
        }
    }

    @Test
    public void testGetRoleById3() {
        SqlSession sqlSession = sqlSessionFactory.openSession();
        ArrayList<Role> roles = new ArrayList<>();

        try {

            RoleMapper mapper = sqlSession.getMapper(RoleMapper.class);
            roles = mapper.dynamicSqlForeach(Arrays.asList(1, 2, 3));
            System.out.println(roles);
        } finally {
            sqlSession.close();
        }
    }

    @Test
    public void testGetRoleById4() {
        SqlSession sqlSession = sqlSessionFactory.openSession();

        try {

            RoleMapper mapper = sqlSession.getMapper(RoleMapper.class);
            Role role = mapper.dynamicSqlBind("管");
            System.out.println(role);
        } finally {
            sqlSession.close();
        }
    }
}
