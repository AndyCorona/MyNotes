<%--
  Created by IntelliJ IDEA.
  User: Andy_PC
  Date: 2021/9/22
  Time: 17:19
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%--判断源字符串是否包含目标字符串--%>
${fn:contains("Tomcat", "cat")}

<%--判断源字符串是否包含目标字符串，忽略大小写--%>
${fn:containsIgnoreCase("Tomcat","CaT" )}

<%--判断源字符串是否以目标字符串开头--%>
${fn:startsWith("Tomcat", "Tom")}

<%--判断源字符串是否以目标字符串结尾--%>
${fn:endsWith("Tomcat", "cat")}

<%--返回源字符串第一次找到目标字符串的索引--%>
${fn:indexOf("Tomcat", "cat")}

<%--把源字符串中的一部分替换成目标字符串--%>
${fn:replace("Tomcat", "cat", "CAT")}

<%--切割指定范围的源字符串--%>
${fn:substring("Tomcat","0","3" )}

<%--获取源字符串中指定子字符串之前的字符串--%>
${fn:substringBefore("Tomcat", "at")}

<%--获取源字符串中指定子字符串之后的字符串--%>
${fn:substringAfter("Tomcat", "To")}

<%--按照指定分隔符将源字符串分割为字符数组--%>
${fn:split("www.xxx.yyy", ".")}

<%--按照指定分隔符连接字符串数组--%>
${fn:join(["www","xxx","yyyy"], ".")}

<%--源字符串转成小写状态--%>
${fn:toLowerCase("TOMCAT")}

<%--源字符串转成大写状态--%>
${fn:toUpperCase("tomcat")}

<%--删除字符串左右空格--%>
${fn:trim("   tomcat   ")}

<%--对特殊字符进行转义--%>
${fn:escapeXml("<p>hello</p>")}

<%--返回字符串字符个数--%>
${fn:length("tomcat")}
</body>
</html>
