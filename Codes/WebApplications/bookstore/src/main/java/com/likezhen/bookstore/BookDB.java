package com.likezhen.bookstore;

import java.sql.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/**
 * 操作数据库的类
 */
public class BookDB {
    private String url = "jdbc:mysql://localhost:3306/BookDB";
    private String username = "root";
    private String password = "123456";
    private String driverName = "com.mysql.cj.jdbc.Driver";

    public BookDB() throws Exception {
        Class.forName(driverName);
    }

    public Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }

    public void closeResource(Connection con) {
        try {
            if (con != null) {
                con.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void closeResource(PreparedStatement ps) {
        try {
            if (ps != null) {
                ps.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void closeResource(ResultSet rs) {
        try {
            if (rs != null) {
                rs.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    /**
     * 获取书城上架的所有书目数量
     */
    public int getNumberOfBookS() {
        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        int count = 0;
        try {
            con = getConnection();
            ps = con.prepareStatement("select count(*) from books");
            rs = ps.executeQuery();
            if (rs.next()) {
                count = rs.getInt(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeResource(con);
            closeResource(ps);
            closeResource(rs);
        }
        return count;
    }

    /**
     * 获取书城中所有的书本集合
     */
    public Collection<BookDetails> getBooks() {
        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        Collection<BookDetails> list = new ArrayList<BookDetails>();
        try {
            con = getConnection();
            ps = con.prepareStatement("select * from books;");
            rs = ps.executeQuery();

            while (rs.next()) {
                BookDetails book = new BookDetails(
                        rs.getString(1),
                        rs.getString(2),
                        rs.getString(3),
                        rs.getFloat(4),
                        rs.getInt(5),
                        rs.getString(6),
                        rs.getInt(7));
                list.add(book);

            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeResource(con);
            closeResource(ps);
            closeResource(rs);
        }
        return list;
    }

    /**
     * 获取一本书的详细信息
     *
     * @param bookId 一本书有且仅有一个 ID 作为标识符
     */
    public BookDetails getBookDetails(String bookId) {
        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            con = getConnection();
            ps = con.prepareStatement("select * from books where id = ?");
            ps.setString(1, bookId);
            rs = ps.executeQuery();
            if (rs.next()) {
                BookDetails book = new BookDetails(
                        rs.getString(1),
                        rs.getString(2),
                        rs.getString(3),
                        rs.getFloat(4),
                        rs.getInt(5),
                        rs.getString(6),
                        rs.getInt(7));

                return book;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeResource(con);
            closeResource(ps);
            closeResource(rs);
        }
        return null;
    }

    /**
     * 购买书本后，更新数据库中的对应书本的销量
     *
     * @param cart 购物车对象
     */
    public void buyBook(ShoppingCart cart) {
        Connection con = null;
        Collection<ShoppingCartItem> items = cart.getItems();
        Iterator<ShoppingCartItem> iterator = items.iterator();

        try {
            con = getConnection();
            con.setAutoCommit(false);

            while (iterator.hasNext()) {
                ShoppingCartItem cartItem = iterator.next();
                BookDetails book = (BookDetails) cartItem.getItem();
                String id = book.getBookId();
                int quantity = cartItem.getQuantity();
                buyBook(id, quantity, con);
            }
            con.commit();
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                con.rollback();
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
        } finally {
            try {
                con.setAutoCommit(true);
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
            closeResource(con);
        }

    }

    /**
     * 购书后，实际更新数据库的操作
     *
     * @param bookId   书本的 ID 号
     * @param quantity 书本的数量
     * @param con      数据库连接
     */
    public void buyBook(String bookId, int quantity, Connection con) {
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = con.prepareStatement("select * from books where id = ?");
            ps.setString(1, bookId);
            rs = ps.executeQuery();

            if (rs.next()) {
                ps.close();
                ps = con.prepareStatement("update books set SALE_AMOUNT = SALE_AMOUNT + ? where ID = ?");
                ps.setInt(1, quantity);
                ps.setString(2, bookId);
                ps.execute();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeResource(ps);
            closeResource(rs);
        }
    }
}
