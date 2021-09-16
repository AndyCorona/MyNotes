package com.likezhen.www;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbcp2.BasicDataSource;
import org.apache.commons.dbcp2.BasicDataSourceFactory;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.util.Properties;

public class Pool {
    public static Connection getDbcpConnection() throws Exception {

        //加载配置文件
        InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("dbcp.properties");
        Properties info = new Properties();
        info.load(is);

        //创建数据源
        BasicDataSource dataSource = BasicDataSourceFactory.createDataSource(info);

        //获取连接
        return dataSource.getConnection();
    }

    public static Connection getC3P0Connection() throws Exception {

        //加载配置文件，创建数据源
        ComboPooledDataSource dataSource = new ComboPooledDataSource("c3p0");//传入配置文件中 named-config 标签的 name 属性值

        //获取连接
        return dataSource.getConnection();
    }

    public static Connection getDruidConnection() throws Exception {

        //加载配置文件
        InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("druid.properties");
        Properties info = new Properties();
        info.load(is);

        //创建数据源
        DataSource dataSource = DruidDataSourceFactory.createDataSource(info);

        //获取连接
        return dataSource.getConnection();
    }

    public static void main(String[] args) {
//        try {
//
//            Connection con = Pool.getDbcpConnection();
//            System.out.println(con);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//        try {
//            Connection con = Pool.getC3P0Connection();
//            System.out.println(con);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//        try {
//
//            Connection con = Pool.getDruidConnection();
//            System.out.println(con);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
    }
}
