package com.likezhen.www;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {
    /**
     * 获取数据库连接
     *
     * @return 数据库连接
     * @throws Exception
     */
    public static Connection getConnection() throws Exception {
        //加载配置文件
        InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("jdbc.properties");
        Properties info = new Properties();
        info.load(is);

        //获取配置文件信息
        String user = info.getProperty("user");
        String password = info.getProperty("password");
        String url = info.getProperty("url");
        String driver = info.getProperty("driver");

        //加载驱动
        Class.forName(driver);

        //获取数据库连接
        Connection con = DriverManager.getConnection(url, user, password);
        return con;
    }

    /**
     * 关闭增删改操作用到的资源
     *
     * @param ps
     * @param con
     */
    public static void closeResource(PreparedStatement ps, Connection con) {
        if (ps != null) {
            try {
                ps.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     * 关闭查询操作用到的资源
     *
     * @param ps
     * @param con
     * @param rs
     */
    public static void closeResource(PreparedStatement ps, Connection con, ResultSet rs) {
        JDBCUtils.closeResource(ps, con);
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
