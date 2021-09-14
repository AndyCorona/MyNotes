package com.likezhen.www;


import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class JdbcQuery {

    /**
     * 查询的通用操作
     *
     * @param clazz 数据库中表对应的 Java 类的 Class 对象
     * @param sql   预编译的 sql 语句
     * @param args  填充占位符的参数
     * @return 保存查询结果的 Java 对象的集合
     */
    public <T> List<T> query(Class<T> clazz, String sql, Object... args) {
        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {

            //获取数据库连接
            con = JDBCUtils.getConnection();

            //创建 PreparedStatement 对象（预编译 sql 语句）
            ps = con.prepareStatement(sql);

            //填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }

            //执行 sql 语句，获得结果集
            rs = ps.executeQuery();

            //获取结果集元数据对象
            ResultSetMetaData metaData = rs.getMetaData();

            //获取结果集列数
            int columnCount = metaData.getColumnCount();

            //创建集合存储多个对象
            ArrayList<T> list = new ArrayList<T>();


            //按行遍历结果集
            while (rs.next()) {

                //通过反射创建对象存储一行的数据
                T t = clazz.newInstance();

                //按列遍历一行数据
                for (int i = 0; i < columnCount; i++) {

                    //获取当前列别名
                    String columnLabel = metaData.getColumnLabel(i + 1);

                    //用于保存当前列值
                    Object object = null;

                    //过滤出 BLOB 类型
                    if (metaData.getColumnTypeName(i + 1).contains("BLOB") && rs.getBlob(i + 1) != null) {

                        //获取 Blob 对象
                        Blob blob = rs.getBlob(i + 1);

                        //保存在 E 盘根目录，保存路径作为列值
                        object = "E:" + File.separator + Math.random() + ".png";

                        //创建输入输出流
                        InputStream is = blob.getBinaryStream();
                        FileOutputStream out = new FileOutputStream((String) object);

                        byte[] buffer = new byte[1024];
                        int len = 0;
                        while ((len = is.read(buffer)) != -1) {
                            out.write(buffer, 0, len);
                        }
                    } else {

                        //获取当前列值
                        object = rs.getObject(i + 1);
                    }

                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, object);
                }
                list.add(t);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(ps, con, rs);
        }
        return null;
    }



    public static void main(String[] args) {

        //查询不含 blob 数据的 user 表
        JdbcQuery jdbcQuery = new JdbcQuery();

//        List<User> list = jdbcQuery.query(User.class, "select name, password, address from user where id < ?;", 5);
//        for (User user : list) {
//            System.out.println(user);
//        }

//        查询包含 blob 数据的 customers 表
        List<Customers> list1 = jdbcQuery.query(Customers.class, "select * from customers where id > ?", 10);
        for (Customers customers : list1)
            System.out.println(customers);
    }
}
