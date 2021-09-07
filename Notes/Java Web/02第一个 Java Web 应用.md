# 第二章 第一个 Java Web 应用

### 2.1 Java Web 应用简介

Java Web 应用不仅可以在 Tomcat 中运行，还可以在其他符合 Servlet 规范的 Servlet 容器中运行。在 Java Web 应用中包含如下内容：
- Servlet 组件
标准 Servlet 接口的实现类。运行在服务器端，包含了被 Servlet 容器动态调用的程序代码。
- JSP 组件
包含 Java 代码的 HTML 文档。运行在服务端，当客户请求访问 JSP 文件时，Servlet 容器先把它编译成 Servlet 类，然后动态调用它的程序代码。
- 相关的 Java 类
开发人员自定义的与 Web 应用相关的 Java 类。
- 静态文档
存放在服务器的文件系统中，如 HTML 文件、图片、音频和视频等多媒体资源。当客户请求访问这些文件时，Servlet 容器从本地文件系统中读取这些文件，发送给客户端。
- 客户端脚本程序
由客户端运行的程序，JavaScript 是典型的客户端脚本程序。
- web.xml 文件
Web 应用的配置文件，必须位于 WEB-INF子目录下。

### 2.2 Web 应用目录结构
为了让 Servlet 容器能够顺利找到各种组件，Servlet 规范定义 Java Web 应用必须采用固定的目录结构。对于一个名为 helloapp 的 Java Web 应用，其目录结构如下：

| 目录                      | 描述                                                        |
| ------------------------- | ----------------------------------------------------------- |
| /helloapp                 | Web 应用根目录，所有 HTML 和 JSP 文件存放在此目录或子目录下 |
| /helloapp/src             | 存放所有 Java 类源代码                                      |
| /helloapp/WEB-INF         | 存放 web.xml 配置文件                                       |
| /helloapp/WEB-INF/classes | 存放各种 .class 文件，优先级最高                            |
| /helloapp/WEB-INF/lib     | 存放 Web 应用需要的 JAR 文件，优先级低于 classes 目录     |

浏览器不能请求访问 WEB-INF 目录下的文件，只有服务器端才能访问。

### 2.3 创建 Web 应用

#### 2.3.1 创建 HTML 

在 helloapp 根目录下加入 login.html 文件。
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>helloapp</title>
</head>
<body>
<form name="loginForm" method="post" action="dispatcher">
    <table>
        <tr>
            <td>
                <div align="right">User Name:</div>
            </td>
            <td><input type="text" name="username"></td>
        </tr>
        <tr>
            <td>
                <div align="right">Password:</div>
            </td>
            <td><input type="password" name="password"></input></td>
        </tr>
        <tr>
            <td><input type="submit" name="submit" value="submit"></td>
            <td><input type="reset" name="reset" value="reset"></td>
        </tr>
    </table>
</form>
</body>
</html>
```

#### 2.3.2 创建 Servlet 类
```java
package com.likzhen.helloapp;

import javax.servlet.*;
import java.io.IOException;

public class DispatcherServlet extends GenericServlet {
    private String target = "/hello.jsp";

    //响应客户端请求
    @Override
    public void service(ServletRequest request, ServletResponse response) throws ServletException, IOException {

        //读取表单中用户名和密码
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        //在 request 对象中添加 USER 和 PASSWORD 属性
        request.setAttribute("USER", username);
        request.setAttribute("PASSWORD", password);
        //把请求转发给 hello.jsp
        ServletContext context = getServletContext();
        RequestDispatcher dispatcher = context.getRequestDispatcher(target);
        dispatcher.forward(request, response);
    }
}
```
并将 .java 文件编译成 .class 文件。

#### 2.3.3 创建 JSP 文件

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>helloapp</title>
</head>
<body>
<b>Hello: <%= request.getAttribute("USER")%></b>
</body>
</html>
```

#### 2.3.4 创建 web.xml 文件
Servlet 容器在加载和启动 Web 应用时会读取它的 web.xml 文件。在 web.xml 文件可包含如下配置信息：
- Servlet 对象 的定义
- Servlet 对象 的初始化参数
- Servlet 对象 及 JSP 的映射
- 安全域配置参数
- welcome 文件清单
- 资源引用
- 环境变量的定义

在 web.xml 中为 DispatcherServlet 类加上 <servlet> 和 <setvlet-mapping> 元素。
```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    # 通过 DispatcherServlet 类创建一个 dispatcher 对象
    <servlet>
        <servlet-name>dispatcher</servlet-name> 指定 DispatcherServlet 名为 dispatcher
        <servlet-class>com.likzhen.helloapp.DispatcherServlet</servlet-class> 
    </servlet>
    # 访问 dispatcher Servlet 对象的 URL 为 http://localhost:8080/helloapp/dispatcher
    <servlet-mapping>
        <servlet-name>dispatcher</servlet-name>
        <url-pattern>/dispatcher</url-pattern>
    </servlet-mapping>
    <welcome-file-list>
        <welcome-file>login.html</welcome-file>
    </welcome-file-list>
</web-app>
```

### 2.4 在 Tomcat 中发布 Web 应用
1. 把 Web 应用的所有文件复制到 Servlet 容器的特定目录下。
2. 各种 Servlet 容器都会从 Web 应用的 web.xml 配置文件中读取有关 Web 组件的配置信息。
3. 许多 Servlet 容器还允许其他额外的配置，这与 Oracle 的 Servlet 规范无关。

#### 2.4.1 Tomcat 目录结构

| 目录     | 说明                                                       |
| -------- | ---------------------------------------------------------- |
| /bin     | 存放 Windows 和 Linux 平台上启动和关闭 Tomcat 的脚本文件   |
| /conf    | 存放 Tomcat 服务器的各种配置文件，如 server.xml            |
| /lib     | 存放 Tomcat 服务器及所有 Web 应用都可以访问的 JAR 文件     |
| /logs    | 存放 Tomcat 日志文件                                       |
| /webapps | 在 Tomcat 上发布 Web 应用时，默认把 Web 应用文件放于此目录 |
| /work    | Tomcat 把运行时生成的一些文件放于此目录下                  |

Tomcat 类加载器负责为 Tomcat 本身及 Web 应用加载相关的类。加载顺序为：
1. 在 Web 应用的 WEB-INF/classes 目录下查找 xxx.class 文件
2. 在 Web 应用的 WEB-INF/LIB 目录下查找 xxx.class 文件
3. 在 Tomcat 的 lib 子目录下直接查找 xxx.class 文件
4. 在 Tomcat 的 lib 子目录下的 JAR 文件中查找 xxx.class 文件
5. 抛出异常

#### 2.4.2 发布 Web 应用

在 Web 应用开发阶段，通常采用开放式的目录结构发布 Web 应用。直接将所有 Web 应用文件复制到 webapps 目录下。开发完毕，进入产品发布阶段，应该将整个 Web 应用打包为 WAR 文件再发布。
```dos
#进入 D:\helloaapp 目录，执行压缩命令，获得 WAR 包
jar cvf D:\helloapp.war * #压缩命令
jar xvf D:\helloapp.war #解压命令
```
将 WAR 包放入 webapps 目录下，Tomcat 启动后，会把所有 WAR 文件展开为开放式结构。
如果需要更灵活地发布 Web 应用，需要为 Web 应用配置 Tomcat 的 <Context> 元素。

