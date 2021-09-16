package com.likezhen.www;

import java.sql.Connection;
import java.sql.PreparedStatement;

public class JdbcBatch {
    /**
     * 未使用批量处理
     * @throws Exception
     */
    public void noBatch() throws Exception {

        long start = System.currentTimeMillis();

        //获取数据库连接
        Connection con = JDBCUtils.getConnection();

        //创建 PreparedStatement 对象（预编译 sql 语句）
        String sql = "insert into user(name) values(?)";
        PreparedStatement ps = con.prepareStatement(sql);

        //插入十万条数据，每条语句单独提交
        for (int i = 0; i < 100000; i++) {
            ps.setString(1, "name_" + i);
            ps.execute();
        }

        long end = System.currentTimeMillis();
        System.out.println("花费时间：" + (end - start) + " 毫秒"); //157748 毫秒
    }

    /**
     * 使用批量处理
     * @throws Exception
     */
    public void batch() throws Exception {

        long start = System.currentTimeMillis();

        //获取数据库连接
        Connection con = JDBCUtils.getConnection();
        //关闭自动提交
        con.setAutoCommit(false);

        //创建 PreparedStatement 对象（预编译 sql 语句）
        String sql = "insert into user(name) values(?)";
        PreparedStatement ps = con.prepareStatement(sql);

        //插入十万条数据
        for (int i = 0; i < 100000; i++) {
            ps.setString(1, "name_" + i);
            //批量处理，缓存 sql 语句
            ps.addBatch();
            //每五万条语句处理一次，并清空缓存区
            if (i % 50000 == 0) {
                ps.executeBatch();
                ps.clearBatch();
            }
        }

        //提交语句
        con.commit();

        long end = System.currentTimeMillis();
        System.out.println("花费时间：" + (end - start) + " 毫秒"); //951 毫秒
    }

    public static void main(String[] args) {
        JdbcBatch batch = new JdbcBatch();
        try {

            batch.batch();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
