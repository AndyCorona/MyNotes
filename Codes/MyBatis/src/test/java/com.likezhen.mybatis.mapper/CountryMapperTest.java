package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Country;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.BeforeClass;
import org.junit.Test;

import java.io.IOException;
import java.io.Reader;
import java.util.List;


public class CountryMapperTest {
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
    public void testSelectAll() {
        //实例化 SqlSession
        SqlSession sqlSession = sqlSessionFactory.openSession();
        try {
            //通过映射接口获取映射器
            CountryMapper mapper = sqlSession.getMapper(CountryMapper.class);
            //执行映射 SQL 语句
            List<Country> countryList = mapper.selectAll();
            for (Country country : countryList) {
                System.out.println(country.getId() + country.getCountryname() + country.getCountrycode());
            }
        } finally {
            //关闭 SqlSession
            sqlSession.close();
        }
    }

    @Test
    public void testSelectOne() {
        //实例化 SqlSession
        SqlSession sqlSession = sqlSessionFactory.openSession();
        try {
            //通过映射接口获取映射器
            CountryMapper mapper = sqlSession.getMapper(CountryMapper.class);
            //执行映射 SQL 语句
            Country country = mapper.selectOne(1);
            System.out.println(country);
        } finally {
            //关闭 SqlSession
            sqlSession.close();
        }
    }
}
