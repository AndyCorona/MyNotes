<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/10
  Time: 19:04
  To change this template use File | Settings | File Templates.
--%>
<%--目标组件，接收来自源组件的转发请求，并将响应结果发送给客户端--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>target</title>
</head>
<body>
<%--获取客户端的请求参数--%>
<p>hello, <%= request.getParameter("username")%></p>
<%--获取源组件传递过来的额外请求参数--%>
<p>hello, <%= request.getParameter("id")%></p>
</body>
</html>
