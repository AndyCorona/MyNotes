<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/19
  Time: 9:28
  To change this template use File | Settings | File Templates.
--%>
<%--使用会话的 JSP，用于登录。之后跳转到 check.jsp 页面--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head><title>登录</title></head>
<body>
<%
    String name = "";
    if (!session.isNew()) {
        name = (String) session.getAttribute("username");
        if (name == null) name = "";
    }
%>
<p>欢迎光临，请登录</p>
<p>SessionID: <%=session.getId()%></p>

<form name="loginForm" action="check.jsp" method="post">
    <table>
        <tr>
            <td>用户名：</td>
            <td><input type="text" name="username" value="<%=name%>" autofocus required></td>
        </tr>
        <tr>
            <td>密码：</td>
            <td><input type="text" name="password" value="" required></td>
        </tr>
        <tr>
            <td><input type="submit" name="submit" value="提交"></td>
        </tr>
    </table>
</form>
</body>
</html>
