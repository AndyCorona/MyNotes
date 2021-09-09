# 第六章 JSP 技术

JSP 是 Java Server Page 的缩写，它是 Servle 的扩展，本质上还是 Servlet，目的是为了简化创建和维护动态网站的工作。JSP API 主要由 javax.servlet.jsp 包及其子包提供。

### 6.1 HTML、Servlet 和 JSP

静态 HTML 文档、Servlet 和 JSP 都能返回 HTML 页面给客户端。

#### 6.1.1 HTML 静态页面

当浏览器请求访问 http://localhost:8080/helloapp/hello.html 时，Web 服务器会读取本地文件系统中的 hello.html 中的数据，把它作为响应正文发送给浏览器。

#### 6.1.2 Servlet 动态生成 HTML 页面

在 web.xml 中为 HelloServlet 类映射 URL “/hello"。当浏览器请求访问 http://localhost:8080/helloapp/hello 时，Web 服务器调用 HelloServlet 类的服务方法 doXXX()，在该方法内，通过 PrintWriter 对象一行一行地打印 HTML 文档，麻烦且繁琐。

```xml
public class HelloServlet extends HtpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException{
	PrintWriter out = response.getPrintWriter();
	out.println("<html><head><title>helloApp</title></head>");
	out.println("<body>");
	out.println("Hello Servlet");
	out.println("</body></html>");
	out.close();
	}
}
```

#### 6.1.3 JSP 动态生成 HTML 页面

JSP 技术吸取 HTML 静态页面和 Servlet 地优点，摒弃两者的缺点。大大简化动态生成网页的工作。在传统的 HTML 文档中加入 Java 程序片段和 JSP 标记，就构成 JSP 文件。当 Servlet 容器接收到客户端要求访问特定 JSP 文件的请求时，将按照以下流程处理：
1. 查找与 JSP 文件对应的 Servlet，如果已经存在，就调用其服务方法。
2. 如果首次调用 JSP 文件，与 JSP 文件对应的 Servlet 不存在，就解析文件系统中的 JSP 文件，把它翻译成 Servlet 源文件，Servlet 源文件被编译成 Servlet 类，再初始化 Servlet 并调用其服务方法。

JSP 翻译编译后自动生成的 Servlet 继承 org.apache.jasper.runtime.HttpJspBase 类，HttpJspBase 类实现了 javax.servlet.jsp.HttpJspPage 接口，该接口继承 javax.servlet.JspPage 接口，JspPage 接口继承 Servlet API 中的 javax.servlet.Servlet 接口。omcat 把由 JSP 生成的 Servlet 源文件和 .class 文件放在 <CATALINA_HOME>/work 目录下。

### 6.2 JSP 语法

虽然 JSP 本质上就是 Servlet，但 JSP 有着不同于 Java 编程语言的专门的语法，该语法的特点是尽可能用标记来取代 Java 程序代码，使得整个 JSP 文件看上去像标记文档而不是 Java 程序代码。JSP 文件中可以包含以下内容：
- 纯文本或 HTML 文本（模板文本）
- JSP 指令
- JSP 声明
- Java 程序片段
- Java 表达式
- JSP 隐含对象

#### 6.2.1 JSP 指令

JSP 指令用来设置和整个 JSP 网页相关的属性，如网页的编码方式和脚本语言等。指令的一般语法形式为：
```<%@ 指令名 属性="值" %>```

1. **page 指令**

page 指令可以指定和页面相关的设置。

```<%@ page 属性1="值1" 属性2="值2" %>```

| page 指令的属性    | 描述                                                         | 举例                                              |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------- |
| buffer             | 指定 out 对象使用缓冲区的大小                                | <%@ page buffer="8kb" %>                          |
| autoFlush          | 控制 ou t对象的缓存区                                        | <%@ page autoFlush="true" %>                      |
| contentType        | 指定当前 JSP 页面的 MIME 类型和字符编码，仅第一次设置有效    | <%@ page contentType="text/html;charset=UTF-8" %> |
| errorPage          | 指定当前 JSP 页面发生异常时需要转发到的其他可以处理错误的页面 | <%@ page errorPage="index.html"                   |
| isErrorPage        | 指定当前页面是否可以作为另一个 JSP 页面的错误处理页面        | <%@ page isErrorPage="true" %>                    |
| extends            | 指定 servlet 的父类                                          | <%@ page extends="javax.servlet.jsp.\*"           |
| import             | 导入要使用的 Java 类，可设置多次                             | <%@ page import="java.io.\*" %>                   |
| info               | 定义 JSP 页面的描述信息                                      | <@% page info="temp jsp file" %>                  |
| isThreadSafe       | 指定对 JSP 页面的访问是否为线程安全                          | <@% page isThreadSafe="true" %>                   |
| language           | 定义 JSP 页面所用的脚本语言，Java 是唯一默认值和有效值，仅第一次设置有效 | <%@ page language="java" %>                       |
| session            | 指定 JSP 页面是否使用 session                                | <%@ page session="true" %>                        |
| isELIgnored        | 指定是否执行 EL 表达式                                       | <%@ page isELIgnored="false" %>                   |
| isScriptingEnabled | 指定能否使用脚本元素                                         | <%@ page isScriptingEnabled="true" %>             |
2. **include 指令**

include 指令用来包含其他 JSP 文件或 HTML 文件。把多数网页都相同的内容单独方法一个文件中，其他 JSP 文件通过 include 指令将这个文件包含进来。

```<%@ include file="目标组件的绝对 URL 或相对 URL" %>```

#### 6.2.2 JSP 声明

JSP 声明与 JSP 对应的 Servlet 类的成员变量和方法，只在当前 JSP 文件中有效。语法格式为：
```<%! declaration;[declaration;] ... %>```

```jsp
<%! int v1=0; %>
<%! public void print(){
	System.out.println("hello");
	}
%>
```

#### 6.2.3 Java 程序片段

也称为 Scriptlet，为嵌入在 JSP 文件中的有效的 Java 程序代码。程序片段默认是属于 Servlet 类中的 service() 方法中的代码。语法格式为：
```<% Java 代码 %>```

```jsp
<%
String gender = "female";
if (gender.equals("female")) {
%>
She is a girl
<% } else { %>
He is a boy
<% } %>
```
以上 JSP 代码等价于以下 Servlet 的 service() 方法：
```	java
public void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        String gender = "female";
        if (gender.equals("female")) {
            out.println("She is a girl");
        } else {
            out.println("He is a boy");
        }
```

#### 6.2.4 Java 表达式

获得 Java 程序中变量的值或方法的返回值，在网页上打印出来或做为某些 JSP 标签属性的值。语法格式为：
```<%= 变量名 %>```
```jsp
<%! int temp = 1;%>
the value is <%= temp %>
```

#### 6.2.5 隐含对象

Servlet 中可以访问由 Servlet 容器提供的 ServletContext、ServletRequest 和 ServletResponse 等对象。在 JSP 程序片段中，这些对象称为隐含对象，每个对象被固定的引用变量引用，这些引用变量在 JSP 翻译成的 Servlet 源文件中定义。

| 引用变量    | 隐含对象                          |
| ----------- | --------------------------------- |
| request     | javax.servlet.HttpServletRequset  |
| response    | javax.servlet.HttpServletResponse |
| pageContext | javax.servlet.PageContext         |
| application | javax.servlet.ServletContext      |
| out         | javax.servlet.jsp.JspWriter       |
| config      | javax.servlet.ServletConfig       |
| page        | javax.lang.Object                 |
| session     | javax.servlet.http.HttpSession    |
| exception   | java.lang.Exception               |

```jsp
<%
String username = request.getParameter("username"); <%-- 用 request 引用变量引用 HttpServletRequest 隐含对象--%>
%>
```
<%-- JSP 注释 --%>

### 6.3 JSP 生命周期

JSP 与 Servlet 的一个区别在于，Servlet 容器必须先把 JSP 编译成 Servlet 类，然后才能运行它。JSP 的生命周期包含以下阶段：
- 解析阶段：Servlet 容器解析 JSP 文件的代码，如果有语法错误，向客户端返回错误信息。
- 翻译阶段：Servlet 容器把 JSP 文件翻译成 Servlet 源文件。
- 编译阶段：Servlet 容器编译 Servlet 源文件，生成对应的 .class 文件。
- 初始化阶段：加载与 JSP 对应的 Servlet 类，创建其实例，调用其初始化方法 \_jspInit()。
- 运行时阶段：调用与 JSP 对应的 Servlet 对象的服务方法 \_jspService()。
- 销毁阶段：调用与 JSP 对应的 Servlet 对象的销毁方法 \_jspDestory()，然后销毁该对象。

开发人员可以实现 jspInit() 方法和 jspDestory() 方法，jspService() 方法一般由容器根据 JSP 文件自动翻译生成。

解析、翻译和编译是 JSP 生命周期中特有的阶段，这三个阶段发生在以下情况：
- JSP 文件被客户端首次请求访问。
- JSP 文件被更新。
- 与 JSP 文件对应的 Servlet 类的 .class 文件被手工删除。