package com.likezhen.www;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;

public class JdbcUpdate {
    /**
     * 增删改的通用操作
     * @param sql 预编译的 sql 语句
     * @param args 填充占位符的参数
     */
    public void update(String sql, Object... args) {
        Connection con = null;
        PreparedStatement ps = null;
        try {
            //获取数据库连接
            con = JDBCUtils.getConnection();

            //创建 PreparedStatement 对象（预编译 sql 语句）
            ps = con.prepareStatement(sql);

            //填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }

            //执行 sql 语句
            ps.execute();

        } catch (Exception e1) {
            e1.printStackTrace();
        } finally {
            JDBCUtils.closeResource(ps, con);
        }
    }

    public static void main(String[] args) {
        JdbcUpdate jdbcUpdate = new JdbcUpdate();

//        插入数据
        jdbcUpdate.update("insert into user(id, name,password,address,phone) values(?,?,?,?,?);", 6, "likezhen", "andy", "FuJian", "18750718582");

//        修改数据
        jdbcUpdate.update("update user set name = ? where id =6;", "andycorona");

//        删除数据
        jdbcUpdate.update("delete from user where id =6;");

//        插入 blob 数据
        try {
            jdbcUpdate.update("insert into customers() values(?,?,?,?,?);", 19, "likezhen", "812453627@qq.com", new Date(201982931), new FileInputStream(new File("e:" + File.separator + "likezhen.png")));
        } catch (IOException e) {
            e.printStackTrace();
        }

//        修改 blob 数据
        try {
            jdbcUpdate.update("update customers set photo = ? where id = 19;", new FileInputStream(new File("e:" + File.separator + "andy.jpg")));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
