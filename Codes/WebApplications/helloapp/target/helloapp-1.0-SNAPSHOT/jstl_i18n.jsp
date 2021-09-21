<%@ page import="java.sql.Date" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/21
  Time: 20:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>JSTL I18N 标签库</title>
</head>
<body>

<%--创建一个中文 Locale 对象，保存在会话范围内--%>
<fmt:setLocale value="zh_CN" scope="session"/>
<%--获取客户端的 Locale 对象，保存在会话范围内--%>
<fmt:setLocale value="${header['accept-language']}" scope="session"/>

<%--创建 ResourceBundle 对象，保存在特定范围内，basename 属性指明资源文件名，var 属性为命名变量名
没有 var 属性时此对象为默认 ResourceBundle 对象--%>
<fmt:setBundle basename="resource" var="bundle" scope="session"/>


<%--设置两个 ResourceBundle 对象，第一个无 var 属性的为默认对象--%>
<fmt:setBundle basename="message"/>
<fmt:setBundle basename="resource" var="bundle" scope="session"/>

<%--获取默认 ResourceBundle 对象的内容--%>
<fmt:message key="app.login.user"/>


<fmt:bundle basename="resource" prefix="app.login.">
    <%--从 <fmt:bundle> 指定的 ResourceBundle 对象中获取内容--%>
    <fmt:message key="user"/>
    <fmt:message key="password"/>
</fmt:bundle>

<%--从命名变量为 bundle 的 ResourceBundle 对象中获取内容 --%>
<fmt:message bundle="${bundle}" key="app.login.user"/>

<fmt:message bundle="${bundle}" key="date">
    <%--填充第一个占位符--%>
    <fmt:param value="2020"/>
    <%--填充第二个占位符--%>
    <fmt:param value="3"/>
</fmt:message>

<%--设置 HTTP 请求正文的字符编码--%>
<fmt:requestEncoding value="gb2312"/>

<%--设置时区，并保存到特定范围中--%>
<fmt:setTimeZone value="GMT" var="myzone" scope="session"/>

<%----%>
<fmt:timeZone value="GMT+8">
    <fmt:formatDate value="<%=new java.util.Date()%>" type="both"/>
</fmt:timeZone>

</body>
</html>
