<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/22
  Time: 16:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix="sql" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<html>
<head>
    <title>JSTL SQL 标签库</title>
</head>
<body>
<%--使用配置好的 JNDI 数据源或创建新的数据源--%>
<sql:setDataSource dataSource="jdbc/BookDB" var="pool" scope="application"/>
<sql:setDataSource url="jdbc:mysql://localhost:3306/BookDB" driver="com.mysql.cj.jdbc.Driver" user="root"
                   password="123456"/>

<%--
执行查询语句
sql 属性：指定要查询的 sql 语句
dataSource 属性：指定数据源
maxRows 属性：指定从原始查询结果中取出条目数上限
startRow 属性：指定从原始查询结果第几条开始取出记录
var 属性：查询结果的命名变量名
scope 属性：查询结果的存放范围
--%>
<sql:query var="books" sql="select * from books" dataSource="${pool}" scope="application" startRow="0" maxRows="6"/>
<%--获取查询结果的所有字段名和行数--%>
${books.columnNames}
${books.rowCount}

<%--填充预编译 sql 语句的占位符--%>
<sql:query var="books" sql="select * from books where id > ?">
    <sql:param>5</sql:param>
</sql:query>

<%--填充预编译 sql 语句中的日期或时间的占位符--%>
<fmt:parseDate value="202.01.25" type="date" var="pub_date"/>
<sql:query var="books" sql="SELECT * from books where PUB_DATE =? ">
    <sql:dateParam value="${pub_date}" type="date"/>
</sql:query>

<%--执行 SQL 增删改等操作--%>
<sql:update var="result" sql="delete from books where id > 6" dataSource="${pool}"/>

<%--声明事务，位于此标签内的所有 sql 位于同一个事务中--%>
<sql:transaction dataSource="${pool}" isolation="repeatable_read">
    <sql:query var="books" sql="select * from books where id > 5"/>
    <sql:update var="result" sql="delete from books where id > 6"/>
</sql:transaction>

</body>
</html>
