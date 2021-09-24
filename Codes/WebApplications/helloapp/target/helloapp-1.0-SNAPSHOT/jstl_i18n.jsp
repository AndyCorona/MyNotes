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

<%--设置标签内容所使用的时区--%>
<fmt:timeZone value="GMT+8">
    <fmt:formatDate value="<%=new java.util.Date()%>" type="both"/>
</fmt:timeZone>

<%--
对数字进行格式化
value 属性：待格式化的数字
type 属性：数字类型，有数字（number）、货币（currency）和百分数（percent）
pattern 属性：自定义的格式化样式，具体参考 java.text.DecimalFormat 类 API 文档
currencyCode 属性：指定货币类型的数字的货币代码
currencySymbol 属性：指定货币类型的数字的货币符号
gtoupingUsed 属性：是否对数字进行逗号分隔
mxaIntegerDigits 属性：指定整数部分的位数上限
minIntegerDigits 属性：指定整数部分的位数下限
maxFractionDigits 属性：指定小数部分的位数上限
minFractionDigits 属性：指定小数部分的位数下限
var 属性：指定命名变量名
scope：格式化后数字字符串的保存范围
--%>
<fmt:formatNumber value="12345" groupingUsed="false"/>

<%--
解析字符串形式的数字，和格式化相反
value 属性：待解析的字符串
type 属性：按照指定类型解析，有数字（number）、货币（currency）和百分数（percent）
pattern 属性：指明自定义的格式化样式，用于决定如何进行解析
parseLocale 属性：按照哪个 Locale 对象解析，默认为上下文环境使用的 Locale
integerOnly 属性：是否只解析整数部分
var 属性：指定命名变量名
scope：解析后数字的保存范围
--%>
<fmt:parseNumber value="$123,456" type="currency" parseLocale="en_US"/>

<%--
格式化日期和时间
value 属性：待格式化的日期或时间
type 属性：指定格式化日期（date）还是时间（time）或两者兼具（both）
dateStyle 属性：日期的格式化样式，默认为 default。具体参考 java.text.DateFormat 类 API 文档
timeStyle 属性：时间的格式化样式，默认为 default。具体参考 java.text.DateFormat 类 API 文档
pattern 属性：自定义格式化日期和时间的样式。具体参考 java.text.SimpleDateFormat 类 API 文档
timeZone 属性：指定使用的时区
var 属性：指定命名变量名
scope：格式化后日期和时间字符串的保存范围
--%>
<fmt:formatDate value="<%=new java.util.Date()%>" type="both"/>

<%--
解析字符串形式的日期和时间，转换成 jaa.util.Date 日期类型
value 属性：待解析的日期或时间
type 属性：按照指定类型解析，有日期（date）、时间（time）和两者兼具（both）
dateStyle 属性：日期的格式化样式，用于决定如何进行解析
timeStyle 属性：时间的格式化样式，用于决定如何进行解析
pattern 属性：指明自定义的格式化样式，用于决定如何进行解析
parseLocale 属性：按照哪个 Locale 对象解析，默认为上下文环境使用的 Locale
timeZone 属性：指定使用的时区
var 属性：指定命名变量名
scope：解析后的日期和时间的保存范围
--%>
<fmt:parseDate value="2021-10-19 11:15:32" pattern="yyyy-MM-dd" parseLocale="zh_CN" type="date" />

</body>
</html>
