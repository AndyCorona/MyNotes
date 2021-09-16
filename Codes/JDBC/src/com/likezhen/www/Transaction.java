package com.likezhen.www;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Transaction {
    /**
     * 开启数据库事务，无异常则提交，有异常则回滚
     */
    public void transaction() {

        Connection con = null;
        PreparedStatement ps = null;

        try {
            //获取数据库连接
            con = JDBCUtils.getConnection();
            //开启事务
            con.setAutoCommit(false);

            //创建 PreparedStatement 对象（预编译 sql 语句）
            String sql = "insert into user(name) values (?)";
            ps = con.prepareStatement(sql);

            //填充占位符，执行 sql 语句
            ps.setString(1, "rout");
            ps.execute();

            //模拟异常
            System.out.println(10 / 0);

            //若没有异常，提交事务
            con.commit();
        } catch (Exception e) {
            e.printStackTrace();
            try {
                //若有异常，回滚事务
                con.rollback();
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
        } finally {
            try {
                //开启自动提交，关闭数据库连接时才会提交语句，否则会回滚。
                con.setAutoCommit(true);
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
            //关闭连接
            JDBCUtils.closeResource(ps, con);
        }
    }

    public static void main(String[] args) {
        Transaction transaction = new Transaction();
        transaction.transaction();
    }
}
