package com.likezhen.www;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.util.Properties;

/**
 * 获取数据库连接
 */
public class JdbcConnection {
    public static void main(String[] args) {
        InputStream is = null;
        try {

            //读取配置文件内容，配置文件相对于 src/ 目录的路径
            is = JdbcConnection.class.getClassLoader().getResourceAsStream("jdbc.properties");
            Properties info = new Properties();
            info.load(is);

            //获得配置信息
            String user = info.getProperty("user");
            String password = info.getProperty("password");
            String url = info.getProperty("url");
            String driver = info.getProperty("driver");

            //通过反射加载驱动
            Class.forName(driver);

            //获取连接
            Connection con = DriverManager.getConnection(url, user, password);
            System.out.println("获取数据库连接为 " + con);
        } catch (Exception e1) {
            e1.printStackTrace();
        } finally {
            if (is != null) {
                try {
                    is.close();
                } catch (IOException e2) {
                    e2.printStackTrace();
                }
            }
        }
    }
}
