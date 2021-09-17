<%@ page import="java.io.PrintWriter" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isErrorPage="true" %>
<html>
<head>
    <title>出错了</title>
</head>
<body>
<p>
    服务器端发生错误：<%=exception.getMessage()%>
</p>
<p>
    错误原因为：<% exception.printStackTrace(new PrintWriter(out));%>
</p>

</body>
</html>
