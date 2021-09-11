<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/10
  Time: 19:04
  To change this template use File | Settings | File Templates.
--%>
<%--源组件，将请求转发给目标组件 target.jsp--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>source</title>
</head>
<body>
<%--源组件的响应结果不会发送到客户端--%>
<p>请求转发之前</p>
<%--使用 jsp:param 标签向目标组件传递额外的请求参数--%>
<jsp:forward page="target.jsp">
    <jsp:param name="id" value="1"/>
</jsp:forward>
<%--源组件请求转发之后的代码不会执行--%>
<%System.out.println("请求转发之后");%>
</body>
</html>
