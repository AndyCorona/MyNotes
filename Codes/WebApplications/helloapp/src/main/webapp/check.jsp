<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/19
  Time: 9:45
  To change this template use File | Settings | File Templates.
--%>
<%--从会话范围内获取用户名，存放到会话范围内--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head><title>验证</title></head>
<body>

<%
    String name = null;
    name = request.getParameter("username");
    if (name != null) {
        session.setAttribute("username", name);
    } else {
        name = (String) session.getAttribute("username");
        if (name == null) response.sendRedirect("login.jsp");
    }
%>

<a href="login.jsp">切换用户</a>
<a href="logout.jsp">注销</a>
<p>当前用户为：<%=name%>
</p>
</body>
</html>
