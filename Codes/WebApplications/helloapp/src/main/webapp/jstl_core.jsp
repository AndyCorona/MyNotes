<%@ page import="java.util.HashSet" %><%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/21
  Time: 15:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <title>JSTL Core 标签库</title>
</head>
<body>
<%--将表达式结果打印到网页上--%>
<c:out value="${param.username}" default="unknown"/>

<%--为 String 类型的命令变量赋值--%>
<c:set var="user" value="Tom" scope="session"/>
<%pageContext.setAttribute("user", "Tom", PageContext.SESSION_SCOPE);%>

<%--为 JavaBean 命名变量的属性赋值--%>
<jsp:useBean id="mytag" class="com.likezhen.helloapp.myTag" scope="application"/>
<c:set target="${mytag}" property="username" value="root"/>

<%--删除特定范围内的命名变量--%>
<c:remove var="mytag" scope="application"/>

<%--把标签内容中的异常对象作为命名变量保存在页面范围内--%>
<c:catch var="ex">
    <%
        int a = 10 / 0;
    %>
</c:catch>

<%--把 test 属性中逻辑表达式的值存放在 var 属性指定的命名变量中--%>
<c:if test="${param.username == 'Tom'}" var="result" scope="session"/>
<%--只有当 test 属性中逻辑表达式的值为 true 才执行标签内容--%>
<c:if test="${param.username == 'Tom'}">
    yes, im Tom!
</c:if>

<%--实现 Java 中的 if - else if - else 语句--%>
<c:choose>
    <c:when test="${empty param.username}">
        no user
    </c:when>
    <c:when test="${param.username eq 'root'}">
        im root
    </c:when>
    <c:otherwise>
        im ${param.username}
    </c:otherwise>
</c:choose>

<%
    HashSet names = new HashSet();
    names.add("Tom");
    names.add("Mike");
    names.add("Andy");
    names.add("Likezhen");
%>
<%--遍历集合，重复执行标签内容，var 属性的命名变量存放每个取出来的元素，items 属性为待遍历的集合
varStatus 属性存放取出元素的信息，begin 属性为遍历的起始索引，end 属性为遍历的结束索引，step 属性为步长--%>
<c:forEach var="name" items="<%=names%>" varStatus="status" begin="1" end="3" step="2">
    ${status.count} <%--当前元素的序号，从 1 开始--%>
    ${status.index} <%--当前元素的索引，从 0 开始--%>
    ${status.first} <%--是否为第一个元素--%>
    ${status.last} <%--是否为最后一个元素--%>
</c:forEach>
<%--遍历 items 属性的字符串，分隔符为 ?--%>
<c:forTokens var="subst" items="Tom?Andy?Likezhen" delims="?">
    ${subst}
</c:forTokens>

<%--和 <jsp:include> 标签类似，区别在于 <c:import> 可以导入其他 Web 应用的资源或其他网站的资源--%>
<c:import url="login.jsp"/>

<%--将 value 属性的 URL 重写并放在 var 属性的命名变量中--%>
<c:url var="myURL" value="login.jsp" scope="session">
    <%--设置 URL 请求参数--%>
    <c:param name="username" value="Tom"/>
</c:url>

<%--将请求重定向到其他 Web 资源--%>
<c:redirect url="check.jsp">
    <c:param name="username" value="root"/>
</c:redirect>
</body>
</html>
