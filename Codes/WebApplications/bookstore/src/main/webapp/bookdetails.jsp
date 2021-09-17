<%@ page import="java.math.BigInteger" %>
<%@ page contentType="text/html;charset=UTF-8" %>
<%@include file="common.jsp" %>
<html>
<head><title>详细信息</title></head>
<%@ include file="banner.jsp" %>

<%--获得要显示的书本 ID--%>
<%
    String bookId = request.getParameter("bookId");
    if (bookId == null)
        bookId = "201";
    BookDetails book = BookDB.getBookDetails(bookId);
    if (book == null) {
%>
<p>书号"<%=bookId%>"在数据库中不存在</p>
<a href="<%=request.getContextPath()%>/catalog.jsp">继续购物</a>

<%
        return;
    }
%>

<p>书名：<%=book.getTitle()%></p>
<p>作者：<em><%=book.getName()%></em></p>
<p>价格：<%=book.getPrice()%>&nbsp;元</p>
<p>销量：<%=book.getSaleAmount()%></p>
<p>评论：<%=book.getDescription()%></p>

<p><a href="<%=request.getContextPath()%>/catalog.jsp?Add=<%=bookId%>">加入购物车</a>
    <a href="<%=request.getContextPath()%>/catalog.jsp">继续购物</a></p>
</body>
</html>
