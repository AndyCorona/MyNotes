<%@ page import="java.util.Collection" %>
<%@ page import="java.util.Iterator" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@include file="common.jsp" %>
<jsp:useBean id="cart" scope="session" class="com.likezhen.bookstore.ShoppingCart"/>
<html>
<head><title>所有书目</title></head>
<%@include file="banner.jsp" %>

<%
    //加入购物车
    String bookId = request.getParameter("Add");
    if (bookId != null) {
        BookDetails book = BookDB.getBookDetails(bookId);
        cart.add(bookId, book);
%>
<p>您已将<em><%=book.getTitle()%>
</em>加入购物车</p>
<%
    }
    if (cart.getNumberOfItems() > 0) {
%>
<p><a href="<%=request.getContextPath()%>/showcart.jsp">查看购物车</a>
    <a href="<%=request.getContextPath()%>/cashier.jsp">结帐</a></p>

<%
    }
%>

<h3>请选择想要购买的书：</h3>
<table>
    <%
        Collection<BookDetails> list = BookDB.getBooks();
        Iterator<BookDetails> iterator = list.iterator();
        while (iterator.hasNext()) {
            BookDetails book = iterator.next();
            String Id = book.getBookId();
    %>
    <tr>
        <td>
            <a href="<%=request.getContextPath()%>/bookdetails.jsp?bookId=<%=Id%>"><%=book.getTitle()%>
            </a>
        </td>
        <td rowspan="2"><a href="<%=request.getContextPath()%>/catalog.jsp?Add=<%=Id%>">加入购物车</a></td>
    </tr>
    <tr>
        <td>作者：<%=book.getName()%>
        </td>
    </tr>
    <%}%>
</table>


</body>
</html>
