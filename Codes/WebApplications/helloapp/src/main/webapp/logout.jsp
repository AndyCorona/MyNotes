<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/19
  Time: 10:09
  To change this template use File | Settings | File Templates.
--%>
<%--退出登录，销毁会话--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head><title>注销</title></head>
<body>
<%
    String name = (String) session.getAttribute("username");
    session.invalidate();
%>

<p>再见，<%=name%></p>
<a href="login.jsp">重新登录</a>

</body>
</html>
