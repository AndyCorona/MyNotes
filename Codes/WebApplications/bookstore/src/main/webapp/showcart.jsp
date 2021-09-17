<%@ page import="java.util.Iterator" %>
<%@ page contentType="text/html;charset=UTF-8" %>
<%@ include file="common.jsp" %>
<jsp:useBean id="cart" scope="session" class="com.likezhen.bookstore.ShoppingCart"/>
<html>
<head><title>购物车</title></head>
<%@ include file="banner.jsp" %>

<%
    String bookId = request.getParameter("Remove");
    if (bookId != null) {
        BookDetails book = BookDB.getBookDetails(bookId);
        cart.remove(bookId, book);
%>
<h3>
    您删除了一本书：<%=book.getTitle()%>
</h3>

<%
    }
    if (request.getParameter("Clear") != null) {
        cart.clear();
%>

<em>购物车已清空</em>

<%
    }
%>

<%
    int numberOfItems = cart.getNumberOfItems();
    if (numberOfItems > 0) {
%>
<h3>您的购物车内有<%=numberOfItems%>本书</h3>

<table>
    <tr>
        <th>数量</th>
        <th>书名</th>
        <th>价格</th>
    </tr>
    <%
        Iterator<ShoppingCartItem> iterator = cart.getItems().iterator();
        while (iterator.hasNext()) {
            ShoppingCartItem cartItem = iterator.next();
            BookDetails book = cartItem.getItem();
    %>
    <tr>
        <td><%=cartItem.getQuantity()%>
        </td>
        <td><a href="<%=request.getContextPath()%>/bookdetails.jsp?bookId=<%=book.getBookId()%>"><%=book.getTitle()%>
        </a></td>
        <td><%=book.getPrice()%>
        </td>
        <td><a href="<%=request.getContextPath()%>/showcart.jsp?Remove=<%=book.getBookId()%>">删除</a></td>
    </tr>
    <%
        }
    %>

    <tr>
        <td colspan="2">总金额</td>
        <td><%=cart.getTotal()%>（元）</td>
    </tr>
</table>
<p>
    <a href="<%=request.getContextPath()%>/catalog.jsp">继续购物</a>
    <a href="<%=request.getContextPath()%>/cashier.jsp">结账</a>
    <a href="<%=request.getContextPath()%>/showcart.jsp?Clear=clear">清空购物车</a>
</p>

<%
} else {
%>

<p>您的购物车为空</p>
<p><a href="<%=request.getContextPath()%>/catalog.jsp">继续购物</a></p>

<%
    }
%>
</body>
</html>
