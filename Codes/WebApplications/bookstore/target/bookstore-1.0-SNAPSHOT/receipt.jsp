<%@ page contentType="text/html;charset=UTF-8" %>
<%@include file="common.jsp" %>
<jsp:useBean id="cart" scope="session" class="com.likezhen.bookstore.ShoppingCart"/>
<%
    BookDB.buyBook(cart);
    session.invalidate();
%>

<html>
<head><title>支付成功</title></head>
<%@ include file="banner.jsp" %>

<h3><%=request.getParameter("cardname")%>：感谢您光临网上书城</h3>
<p><a href="<%=request.getContextPath()%>/index.jsp">返回主页</a></p>
</body>
</html>
