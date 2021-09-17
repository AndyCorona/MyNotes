<%@ page contentType="text/html;charset=UTF-8" %>
<%@ include file="common.jsp" %>
<html>
<head>
    <link rel="stylesheet" href="WEB-INF\classes\normalize.css">
    <title>网上书城</title>
</head>
<%@ include file="banner.jsp" %>
<a href="<%=request.getContextPath()%>/catalog.jsp">查看所有书目</a>

<form action="bookdetails.jsp" method="post">
    <h3>请输入查询信息</h3>
    <b>书的编号：</b>
    <input type="text" name="bookId"/>
    <input type="submit" value="查询"/>
</form>
</body>
</html>
