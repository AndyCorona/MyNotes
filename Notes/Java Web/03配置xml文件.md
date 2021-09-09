# 第三章 配置 xml 文件

### 3.1 server.xml

Tomcat 服务器是由一系列可配置的组件构成，这些组件可以在 <CATAKINA_HOME>/conf/server.xml 文件中配置，每个组件和 xml 文件中的一种元素对应。官方介绍参考 <CATAKINA_HOME>/webapps/docs/config/index.html

在 server.xml 文件中，元素分为五类。
1. 顶层类元素
    <Server> 和 <Service> 元素位于整个配置文件顶层。
2. 连接器元素
    <Connector> 元素代表介于客户与服务器之间的通信接口，将客户请求发给服务器，将服务器响应发送给客户。
3. 执行类元素
    <Executor> 元素代表可以被 Tomcat 的其他组件共享的线程池。
4. 容器类元素
    处理客户请求并生成响应结果的组件，有四种容器类元素，分别为 <Engine>, <Host>, <Context>, <Cluster> 元素。Engine 组件为特定的 Service 组件处理所有客户请求，Host 组件为特定的虚拟主机处理所有客户请求。Context 组件为特定的 Web 应用处理所有客户请求，Cluster 组件为 Tomcat 集群服务管理器。
5. 嵌套类元素
    如 <Valve> 和 <Realm> 等可以加入到容器中的元素。

#### 3.1.1 配置 Server 元素

<Server> 代表整个 Servlet 容器，它是 Tomcat 的顶层元素，由 org.apache.catalina.Server 接口定义，不能作为其他任何元素的子元素。<Server> 元素中可以包含多个 <Service> 元素。
```xml
<Server port="8005" shutdown="SHUTDOWN"></Server>
```
| 属性      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| className | 指定实现 org.apache.catalina.Server 接口的类。默认值为 org.apache.catalina.core.StandardServer |
| port      | 指定 Tomcat 服务器监听 shutdown 命令的端口                   |
| shutdown  | 指定终止 Tomcat 服务器运行时，发给 Tomcat 服务器的 shutdown 监听端口的字符串 |

#### 3.1.2 配置 Service 元素

<Service> 元素由 org.apache.catalina.Service 接口定义，包含一个 <Engine> 元素和多个 <Connector> 元素，多个 <Connector> 元素共享一个 <Engine> 元素。

```xml
<Service name="Catalina"></Service>
<Service name="Apache"></Service>
```

| 属性      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| className | 指定实现 org.apache.catalina.Service 接口的类。默认值为 org.apache.catalina.core.StandardService |
| name      | 定义 Service 名字                                            |

#### 3.1.3 配置 Engine 元素

<Engine> 元素由 org.apache.catalina.Engine 接口定义，处理同一个 <Service> 中所有 <Connector> 元素接收到的客户请求。
```xml
<Engine name="Catalina" defaultHost="localhost"></Engine>
```

| 属性                                                        | 描述                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| className                                                   | 指定实现 org.apache.catalina.Engine 接口的类。默认值为 org.apache.catalina.core.StandardEngine |
| defaultHost                                                 | 指定处理客户请求的默认主机名                                 |
| name                                                        | 定义 Engine 名字                                             |

 <Engine> 元素可以包含 <Realm>、<Valve> 和 <Host> 等子元素。                                                           

#### 3.1.4 配置 Host 元素

<Host> 元素由 org.apache.catalina.Host 接口定义。一个 <Engine> 元素包含多个 <Host> 元素。每个 <Host> 元素定义一个虚拟主机，可包含多个 Web 应用。
```xml
<Host name="localhost" appBase="webapps" unpackWARs="true" autoDeploy="true"></Host>
```

| 属性            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| className       | 指定实现 org.apache.catalina.Host 接口的类。默认值为 org.apache.catalina.core.StandardHost |
| appBase         | 指定虚拟主机的目录，可以为绝对目录或相对于 <CATALINA_HOME> 的相对目录 |
| autoDeploy      | 当Tomcat 服务器运行时，是否监测 appBase 下的文件，并自动发布新加入的 Web 应用 |
| alias           | 指定虚拟主机的别名，可以有多个别名                           |
| deployOnStartup | Tomcat 服务器启动时会自动发布 appBase 目录下的所有 Web 应用。默认值为 true |
| name            | 定义虚拟主机名字                                             |

标准虚拟主机  org.apache.catalina.core.StandardHost 有专有属性。

| 专有属性   | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| unpackWARS | 是否将 WAR 文件展开为开放目录结构再运行                      |
| workDir    | 指定虚拟主机的工作目录。默认值为 <CATALINA_HOME>/work/，Context 元素的 workDir 属性会覆盖此属性 |
| deployXML  | Tomcat 是否解析 META-INF/context.xml 文件。默认值为 true。若设置为 false，可以在 <CATALINA_HOME>/conf/[enginename]/[hostname]/ 目录下设置 Context 元素 |

<Host> 元素可以包含 <Realm>、<Valve> 和 <Context> 等子元素。

#### 3.1.5 配置 Context 元素

<Context> 元素由 org.apache.catalina.Context 接口定义，每个 <Context> 元素代表运行在虚拟主机上的单个 Web 应用。一个 <Host> 上可包含多个 <Context>。
```xml
<Context path="/sample" docBase="sample" reloadable="true"></Context>
```

| 属性       | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| className  | 指定实现 org.apache.catalina.Context 接口的类。默认值为 org.apache.catalina.core.StandardContext |
| path       | 指定访问该 Web 应用的 URL 入口                               |
| docBase    | 指定 Web 应用的文件路径。可以是绝对路径或相对于 Host 的 appBase 的路径 |
| reloadable | 当Tomcat 服务器运行时，是否监测 WEB-INF/classes、WEB-INF/lib 和 WEB-INF/web.xml 文件的改动。若监测到改动，服务器会自动重新加载 Web 应用 |
| cookies    | 是否通过 Cookie 来维持会话，默认值为 true                    |

标准 Context 组件 org.apache.catalina.core.StandardContext 有专有属性。

| 专有属性    | 描述                                                      |
| ----------- | --------------------------------------------------------- |
| unloadDelay | 指定 Tomcat 等待 Servlet 卸载的毫秒数，默认值为 2000 毫秒 |
| workDir     | 指定 Web 应用的工作目录                                   |
| unpackWar   | 是否将 WAR 文件展开为开放目录结构再运行，默认值为 true    |

<Context> 元素可以包含 <Realm>、<Valve> 和 <Resource> 等子元素。

当 Tomcat 加载一个 Web 应用时，会按照以下顺序查找 Web 应用的 <Context> 元素：
1. 在 <CATALINA_HOME>/conf/context.xml 文件查找 <Context> 元素，适合于当前 Tomcat 服务器的所有 Web 应用。
2. 在 <CATALINA_HOME>/conf/[enginename]/[hostname]/context.xml.default 文件查找 <Context> 元素，适合于当前虚拟机的所有 Web 应用。
3. 在 <CATALINA_HOME>/conf/[enginename]/[hostname]/[contextpath].xml 文件查找 <Context> 元素，[contextpath] 为单个 Web 应用的 URL 入口，适合单个 Web 应用。
4. 在 Web 应用的 META-INF/context.xml 文件查找 <Context> 元素，适合当前 Web 应用。
5. 在 <CATALINA_HOME>/conf/server.xml 文件的 <Host> 元素中查找 <Context> 子元素，适合于单个 Web 应用。


#### 3.1.6 配置 Connector 元素

<Connector> 元素由 org.apache.catalina.Connector 接口定义，负责接收客户请求，并返回响应结果。
```xml
<Connector port="8080" protocol="HTTP/1.1"
	connectionTimeout="20000"
	redirectPort="8443" />
```

| 属性              | 描述                                                         |
| ----------------- | ------------------------------------------------------------ |
| enableLookups     | 是否支持域名反向解析，默认值为 false。调用 request.getRemoteHost() 方法将返回客户的主机名 |
| redirectPort      | 指定转发端口                                                 |
| port              | 指定 TCP 端口，默认值为 8080                                 |
| address           | 指定端口监听的 IP 地址，默认情况下，端口会监听服务器上所有 IP 地址 |
| protocol          | 指定 HTTP 协议，默认值 HTTP/1.1                              |
| maxThreads        | 指定处理客户请求的最大线程数，默认值 200                     |
| acceptCount       | 客户请求队列中存放等待被服务器处理的最大客户请求数。默认值 100，若队列已满，将拒绝新的客户请求 |
| connectionTimeout | 指定客户连接超时时间，-1 表示永不超时，默认值 60000 为 60 秒 |
| maxConnections    | 指定任何时刻服务器接收并处理的最大连接数，超过时新的连接将处于阻塞状态 |
| maxCookieCount    | 指定一个客户请求允许的最大 Cookie 数，默认值 200。负值表示没有限制 |
| maxHttpHeaderSize | 指定 HTTP 请求头和响应头的最大长度，默认值 8192 字节，即 8KB |
| maxSwallowSize    | 指定请求正文的最大长度，默认值 2097152 字节，即 2MB          |
| executor          | 指定所使用的执行器名字                                       |

#### 3.1.7 配置 Executor 元素

执行器类元素可能会被 <Connector> 元素引用，所以 <Executor> 元素必须放在 <Connector> 元素前面。
```xml
<Executor name="tomcatThreadPool" namePrefix="catalina-exec-maxThreads="150" minSpareThreads="4"/>
```

| 属性            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| className       | 指定执行器的实现类，默认值为 org.apache.catalina.core.StandardThreadExecutor |
| name            | 指定执行器的名字                                             |

标准虚拟主机  org.apache.catalina.core.StandardThreadExecutor 有专有属性。

| 专有属性        | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| threadPriority  | 指定线程池中线程的优先级别，默认值 5                         |
| daemon          | 指定线程池中的线程是否为后台线程，默认值 true                |
| namePrefix      | 指定线程池中的线程名字前缀，线程名字格式为 ”前缀+线程序号“   |
| maxThreads      | 指定最大线程数，默认值 200                                   |
| minSpareThreads | 指定线程池中处于空闲或运行状态的最小线程数，默认值 25        |
| maxIdleTime     | 指定一个线程的最长闲置时间，默认值 60000 毫秒。超过时间，服务器会关闭该线程 |
| maxQueneSize    | 指定任务队列中的最大任务数。                                 |

### 3.2 web.xml

web.xml 是 Web 应用的配置文件，与 Tomcat 容器完全独立。简要介绍几个元素：
1. <web-app>：Web 应用的根元素
2. <display-name>：Web 应用的名字
3. <discription>：Web 应用的描述
4. <filter>：定义过滤器
5. <filter-mapping>：为过滤器指定 URL 映射
6. <servlet>：定义 Servlet 对象
7. <servlet-mapping>：为 Servlet 对象 指定 URL 映射
8. <session-config>：配置 HTTP 会话
9. <welcome-file-list>：设置 Web 应用的 Welcome 文件清单
10. <taglib>：声明引用的标签库
11. <resource-ref>：声明引用的 JNDI 资源
12. <sercurity-constraint>：配置安全约束
13. <login-config>：配置安全验证登录界面
14. <security-role>：配置安全角色

在 web.xml 中定义的元素的先后顺序最好不要颠倒，否则 Tomcat 可能会报错。所有元素定义在 <web-app> 根元素内。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee
                      http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
  version="4.0"
  metadata-complete="true">

  <display-name>My Web Application</display-name>
  <description>this is my first web application</description>
  ...
</web-app>
```

#### 3.2.1 配置 Filter

对于 Servlet 容器收到的客户请求以及发出的响应结果，过滤器都能检查和修改其中的信息。当客户请求访问 http://localhost:8080/helloapp/sample.jsp 时，触发过滤器 SampleFilter，并由 com.likezhen.helloapp.SampleFilter 类完成具体过滤操作。
```xml
<filter>
	<filter-name>SampleFilter</filter-name> #定义过滤器名字，多个过滤器不能重名
	<filter-class>com.likezhen.helloapp.SampleFilter</filter-class> #实现过滤器的全类名
</filter>
<filter-mapping>
	<filter-name>SampleFilter</filter-name> #过滤器名，和 <filter> 中的 <filter-name> 同名
	<url-pattern>/sample.jsp</url-pattern> #相对于 Web 应用的 URL 路径
</filter-mapping>

```

#### 3.2.2 配置 Servlet

<servlet> 元素为 Servlet 对象定义一个名字，它的子元素如下。

| 子元素            | 说明                                                         |
| ----------------- | :----------------------------------------------------------- |
| <servlet-name>    | 指定 Servlet 对象的名字                                      |
| <servlet-class>   | Servlet 对象的完整类名                                       |
| <init-param>      | 定义 Servlet 对象 的初始化参数。可以存在多个 <init-param>。在 Servlet 对象 中通过 getInitParam(String name) 方法访问初始化参数 |
| <load-on-startup> | 指定当 Servlet 容器启动时，加载各个 Servlet 对象 的顺序。值大于等于零时，Servlet 容器先加载数值小的 Servlet 对象。如果此值为负值或未定义，客户端首次访问这个 Servlet 对象 时容器才加载它 |

SampleServlet 类创建两个 Servlet 对象，分别为 SampleServlet1 和 SampleServlet2。
```xml
<servlet>
	<servlet-name>SampleServlet1</servlet-name>
	<servlet-class>com.likezhen.helloapp.SampleServlet</servlet-class>
	<init-param>
		<param-name>color</param-name>
		<param-value>blue</param-value>
	</init-param>
	<load-on-startup>1</load-on-startup>
    
    <servlet-name>SampleServlet2</servlet-name>
	<servlet-class>com.likezhen.helloapp.SampleServlet</servlet-class>
</servlet>
```

#### 3.2.3 配置 Servlet 映射

<servlet-maapping> 元素用来设定客户访问某个 Servlet 对象 的 URL。它的子元素如下。

| 子元素       | 说明                                                         |
| ------------ | ------------------------------------------------------------ |
| servlet-name | 应该和 <servlet> 元素中的 <servlet-name> 一样                |
| url-pattern  | 指定访问此 Servlet 对象 的 URL。给出相对于整个 Web 应用的 URL 路径 |

给 SampleServlet 对象指定访问 URL 为 http://localhost:8080/helloapp/sample
```xml
<servlet-maapping>
	<servlet-name>SampleServlet</servlet-name>
	<url-pattern>/sample</url-pattern>
</servlet-mapping>
```

#### 3.2.4 配置 Session

<session-config> 元素设定 HTTP Session 的生命周期。

```xml
<session-config>
	<sessioin-timeout>30</session-timeout> #设定 Session 可以保持不活动状态的最长时间（秒）
</session-config>
```

#### 3.2.5 配置 Welcome 文件清单

当用户在浏览器中输入的 URL 不包含某个 Servlet 对象 或 JSP 页面时，<welcome-file-list> 元素可指定显示的默认文件。

```xml
<welcome-file-list>
	<welcome-file>login.jsp</welcome-file> #先返回 login.jsp 文件，若不存在，往下继续查找
	<welcome-file>index.html</welcome-file> #返回 index.html 文件
</welcome-file-list>
```

#### 3.2.6 配置 Tag Library

<taglib> 元素用来设置 Web 应用所引用的 Tag Library。
```xml
<taglib>
	<taglib-uri>/mytaglib</taglib-uri> #引用 mytaglib 标签库
	<taglib-location>/WEB-INF/mytaglib.tld</taglib-location> #对应的  TLD 文件位于 /WEB-INF/mytaglib.TLD
</taglib>
```

#### 3.2.7 配置资源引用

```xml
<resource-ref>
	<description>DB Connection</description> #对所引用资源的说明
	<res-ref-name>jdbc/sampleDB</res-ref-name> #所引用资源的 JNDI 名字
	<res-type>javax.sql.DataSource</res-type> #所引用资源的全类名
	<res-auth>Container</res-auth> #Container 表示由容器来创建和管理资源，Application 表示由 Web 应用来创建和管理资源
</resource-ref>
```

#### 3.2.8 配置安全约束

<security-constraint> 用来为 Web 应用定义安全约束。当用户访问该 Web 应用下所有资源时，必须具备 guest 角色，配置如下。

```xml
<security-constraint>
	<web-resource-collection> #声明受保护的 Web 资源
		<web-resource-name>sample application</web-resource-name> #指定受保护的 Web 资源的名字
		<url-pattern>/*</url-pattern> #指定受保护的 URL 路径
	</web-resource-collection>
	<auth-constraint>
		<role-name>guest</role-name> #guest 角色可以访问受保护的资源
	</auth-constaint>
</security-constraint>
```

#### 3.2.9 配置安全验证登录界面

<login-config> 元素指定当用户访问受保护的 Web 资源时，系统弹出的登录对话框类型。
```xml
<login-config>
	<auth-method>FORM</auth-method> #BASIC(基本验证)，DIGEST(摘要验证)，FORM(基于表单的验证)
	<realm-name>Form-based Authentication Area</realm-name> #设定安全域名称
	<form-login-config> #配置验证网页和出错网页
		<form-login-page>/login.jsp</form-login-page> #设定验证网页
		<form-error-page>/error.jsp</form-error-page> #设定出错网页
	</form-login-config>
</login-config>
```

#### 3.2.10 配置安全验证角色

<security-role> 元素指明这个 Web 应用定义的所有角色名字。

```xml
<security-role>
	<descripition>The role is required to log in to the sample application</description>
	<role-name>guest</role-name> #定义 guest 角色
</security-role>
```
#### 3.2.11 web.xml 配置参考

下面是一个全面的 web.xml 配置文件


```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://java.sun.com/xml/ns/j2ee"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:schemaLocation="http://java.sun.com/xml/ns/j2ee http://java.sun.com/xml/ns/j2ee/web-app_2_4.xsd"
        version="2.4">

        <!-- ========================================================== -->
        <!-- General -->
        <!-- ========================================================== -->
    
        <!-- Name the application -->
        <display-name>Example App</display-name>
        <description>An example application which is used to play with some of the features of Tomcat</description>
    
        <!-- This app is cluster-ready -->
        <distributable />
    
        <!-- Set timeout to 120 minutes -->
        <session-config>
                <session-timeout>120</session-timeout>
        </session-config>


        <!-- ========================================================== -->
        <!-- Custom Tag Libraries -->
        <!-- ========================================================== -->
    
        <!-- Taglib declarations are no longer required since JSP 2.0, see Removing taglib from web.xml -->
        <!-- The <taglib> did not need to be a child of <jsp-config> in earlier versions but is required as of Tomcat 7 -->
        <!-- Note that you can only have one <jsp-config> element per web.xml -->
        <!--
        <jsp-config>
                <taglib>
                        <taglib-uri>mytags</taglib-uri>
                        <taglib-location>/WEB-INF/jsp/mytaglib.tld</taglib-location>
                </taglib>
        </jsp-config>
        -->


        <!-- ========================================================== -->
        <!-- JSP Configuration -->
        <!-- ========================================================== -->
    
        <jsp-config>
                <jsp-property-group>
                        <url-pattern>*.jsp</url-pattern>
                        <include-prelude>/WEB-INF/jspf/prelude1.jspf</include-prelude>
                        <include-coda>/WEB-INF/jspf/coda1.jspf</include-coda>
                </jsp-property-group>
        </jsp-config>


        <!-- ========================================================== -->
        <!-- Context Parameters -->
        <!-- ========================================================== -->
    
        <context-param>
                <description>Enable debugging for the application</description>
                <param-name>debug</param-name>
                <param-value>true</param-value>
        </context-param>
        <context-param>
                <description>The email address of the administrator, used to send error reports.</description>
                <param-name>webmaster</param-name>
                <param-value>address@somedomain.com</param-value>
        </context-param>


        <!-- ========================================================== -->
        <!-- JNDI Environment Variables -->
        <!-- ========================================================== -->
    
        <env-entry>
                <env-entry-name>webmasterName</env-entry-name>
                <env-entry-value>Ms. W. Master</env-entry-value>
                <env-entry-type>java.lang.String</env-entry-type>
        </env-entry>
        <env-entry>
                <env-entry-name>cms/defaultUserSettings/recordsPerPage</env-entry-name>
                <env-entry-value>30</env-entry-value>
                <env-entry-type>java.lang.Integer</env-entry-type>
        </env-entry>
        <env-entry>
                <env-entry-name>cms/enableXMLExport</env-entry-name>
                <env-entry-value>false</env-entry-value>
                <env-entry-type>java.lang.Boolean</env-entry-type>
        </env-entry>
        <env-entry>
                <env-entry-name>cms/enableEmailNotifications</env-entry-name>
                <env-entry-value>true</env-entry-value>
                <env-entry-type>java.lang.Boolean</env-entry-type>
        </env-entry>


        <!-- ========================================================== -->
        <!-- Servlets -->
        <!-- ========================================================== -->
    
        <!-- Simple Servlet, provide a name, class, description and map to URL /servlet/SimpleServlet -->
        <servlet>
                <servlet-name>Simple</servlet-name>
                <servlet-class>SimpleServlet</servlet-class>
                <description>This is a simple Hello World servlet</description>
        </servlet>
        <servlet-mapping>
                <servlet-name>Simple</servlet-name>
                <url-pattern>/servlet/SimpleServlet</url-pattern>
        </servlet-mapping>
    
        <!-- CMS Servlet, responds to *.cms URL's -->
        <servlet>
                <!-- Identification -->
                <servlet-name>cms</servlet-name>
                <servlet-class>com.metawerx.servlets.ContentManagementSystem</servlet-class>
                <description>This servlet handles requests for the CMS (it is a controller in an MVC architecture)</description>
    
                <!-- This servlet has two parameters -->
                <init-param>
                        <param-name>debug</param-name>
                        <param-value>true</param-value>
                </init-param>
                <init-param>
                        <param-name>detail</param-name>
                        <param-value>2</param-value>
                </init-param>
    
                <!-- Load this servlet when the application starts (call the init() method of the servlet) -->
                <load-on-startup>5</load-on-startup>
                <!-- <run-at>0:00, 6:00, 12:00, 18:00</run-at> This tag is only valid for Resin -->
        </servlet>
    
        <!-- Map some URLs to the cms servlet (demonstrates *.extension mapping) -->
        <servlet-mapping>
                <!-- For any URL ending in .cms, the cms servlet will be called -->
                <servlet-name>cms</servlet-name>
                <url-pattern>*.cms</url-pattern>
        </servlet-mapping>
    
        <!-- Rewriter Servlet, responds to /content/* and /admin/RewriterStatistics URL's -->
        <!-- Define a servlet to respond to /content/* URL's -->
        <servlet>
                <servlet-name>rewriter</servlet-name>
                <servlet-class>com.metawerx.servlets.URLRewriter</servlet-class>
        </servlet>
    
        <!-- Map some URL's to the rewriter servlet (demonstrates /path/* and specific URL mapping) -->
        <servlet-mapping>
                <!-- For any URL starting with /content/, the rewriter servlet will be called -->
                <servlet-name>rewriter</servlet-name>
                <url-pattern>/content/*</url-pattern>
        </servlet-mapping>
        <servlet-mapping>
                <!-- The rewriter servlet can also be called directly as /admin/RewriterStatistics, to return stats -->
                <servlet-name>rewriter</servlet-name>
                <url-pattern>/admin/RewriterStatistics</url-pattern>
        </servlet-mapping>
    
        <!-- PathJSP Servlet, maps /shop/item/* URL's to a JSP file -->
        <!-- Define a JSP file to respond to /shop/item/* URL's -->
        <servlet>
                <servlet-name>pathjsp</servlet-name>
                <jsp-file>pathfinder.jsp</jsp-file>
        </servlet>
    
        <!-- Map some URL's to the pathjsp servlet (demonstrates /long/path/* URL mapping) -->
        <servlet-mapping>
                <!-- For any URL starting with /shop/item/, the pathjsp servlet will be called -->
                <servlet-name>pathjsp</servlet-name>
                <url-pattern>/shop/item/*</url-pattern>
        </servlet-mapping>


        <!-- ========================================================== -->
        <!-- Filters -->
        <!-- ========================================================== -->
    
        <!-- Example filter to set character encoding on each request (from Tomcat servlets-examples context) -->
        <filter>
                <filter-name>Set Character Encoding</filter-name>
                <filter-class>filters.SetCharacterEncodingFilter</filter-class>
                <init-param>
                        <param-name>encoding</param-name>
                        <param-value>EUC_JP</param-value>
                </init-param>
        </filter>
        <filter-mapping>
                <filter-name>Set Character Encoding</filter-name>
                <url-pattern>/*</url-pattern>
        </filter-mapping>
    
        <!-- Example filter to dump the HTTP request at the top of each page (from Tomcat servlets-examples context) -->
        <filter>
                <filter-name>Request Dumper Filter</filter-name>
                <filter-class>filters.RequestDumperFilter</filter-class>
        </filter>
        <filter-mapping>
                <filter-name>Request Dumper Filter</filter-name>
                <url-pattern>/*</url-pattern>
        </filter-mapping>


        <!-- ========================================================== -->
        <!-- Listeners -->
        <!-- ========================================================== -->
    
        <!-- Define example application events listeners -->
        <listener>
                <listener-class>com.metawerx.listener.ContextListener</listener-class>
        </listener>
        <listener>
                <listener-class>com.metawerx.listener.SessionListener</listener-class>
        </listener>


        <!-- ========================================================== -->
        <!-- Security -->
        <!-- ========================================================== -->
    
        <!-- Define roles -->
        <security-role>
                <role-name>admin</role-name>
        </security-role>
        <security-role>
                <role-name>cms_editors</role-name>
        </security-role>
        
        <!-- Define a constraint to restrict access to /private/* -->
        <security-constraint>
    
                <display-name>Security constraint for the /private folder</display-name>
    
                <web-resource-collection>
                        
                        <web-resource-name>Protected Area</web-resource-name>
                        <url-pattern>/private/*</url-pattern>
                        
                        <!-- If you list http methods, only those methods are protected. -->
                        <!-- Leave this commented out to protect all access -->
                        <!--
                        <http-method>DELETE</http-method>
                        <http-method>GET</http-method>
                        <http-method>POST</http-method>
                        <http-method>PUT</http-method>
                        -->
    
                </web-resource-collection>
    
                <auth-constraint>
                        <!-- Only only administrator and CMS editors to access this area -->
                        <role-name>admin</role-name>
                        <role-name>cms_editors</role-name>
                </auth-constraint>
    
        </security-constraint>
    
        <!-- FORM based authentication -->
        <!-- Leave this commented out, we will use BASIC (HTTP) authentication instead -->
        <!--
        <login-config>
                <auth-method>FORM</auth-method>
                <form-login-config>
                        <form-login-page>/login.jsp</form-login-page>
                        <form-error-page>/error.jsp</form-error-page>
                </form-login-config>
        </login-config>
        -->
        <!-- This application uses BASIC authentication -->
        <login-config>
                <auth-method>BASIC</auth-method>
                <realm-name>Editor Login</realm-name>
        </login-config>
    
        <!-- Define a constraint to force SSL on all pages in the application -->
        <security-constraint>
    
                <web-resource-collection>
                        <web-resource-name>Entire Application</web-resource-name>
                        <url-pattern>/*</url-pattern>
                </web-resource-collection>
    
                <user-data-constraint>
                        <transport-guarantee>CONFIDENTIAL</transport-guarantee>
                </user-data-constraint>
    
        </security-constraint>


        <!-- ========================================================== -->
        <!-- Error Handler -->
        <!-- ========================================================== -->
    
        <!-- Define an error handler for 404 pages -->
        <error-page>
                <error-code>404</error-code>
                <location>/error404.jsp</location>
        </error-page>
    
        <!-- Define an error handler for java.lang.Throwable -->
        <error-page>
                <exception-type>java.lang.Throwable</exception-type>
                <location>/errorThrowable.jsp</location>
        </error-page>


        <!-- ========================================================== -->
        <!-- Extra MIME types -->
        <!-- ========================================================== -->
    
        <!-- Set XML mime-mapping so spreadsheets open properly instead of being sent as an octet/stream -->
        <mime-mapping>
                <extension>xls</extension>
                <mime-type>application/vnd.ms-excel</mime-type>
        </mime-mapping>


        <!-- ========================================================== -->
        <!-- Locale -->
        <!-- ========================================================== -->
    
        <!-- Set Locale Encoding -->
        <locale-encoding-mapping-list>
                <locale-encoding-mapping>
                        <locale>ja</locale>
                        <encoding>Shift_JIS</encoding>
                </locale-encoding-mapping>
        </locale-encoding-mapping-list>


        <!-- ========================================================== -->
        <!-- Welcome Files -->
        <!-- ========================================================== -->
    
        <!-- Define, in order of preference, which file to show when no filename is defined in the path -->
        <!-- eg: when user goes to http://yoursite.com/ or http://yoursite.com/somefolder -->
        <!-- Defaults are provided in the server-wide web.xml file, such as index.jsp, index.htm -->
        <!-- Note: using this tag overrides the defaults, so don't forget to add them here -->
        <welcome-file-list>
                <!-- Use index.swf if present, or splash.jsp, otherwise just look for the normal defaults -->
                <welcome-file>index.swf</welcome-file>
                <welcome-file>splash.jsp</welcome-file>
                <welcome-file>index.html</welcome-file>
                <welcome-file>index.htm</welcome-file>
                <welcome-file>index.jsp</welcome-file>
        </welcome-file-list>

</web-app>
```

### 3.3 注解配置

从 Servlet 3 开始，可以不必在 web.xml 文件中配置 Web 组件，而是直接在相关类上使用注解标注，由 javax.servlet.annotation 包提供。

#### 3.3.1 @WebServlet

注解 @WebServlet 配置 Servlet 对象，它的属性如下。 

| 属性           | 类型           | 描述                                                         |
| -------------- | -------------- | ------------------------------------------------------------ |
| name           | String         | 等价于 <servlet-name> 元素，默认值为全类名                   |
| value          | String[]       | 等价于 <url-pattern> 元素                                    |
| urlPatterns    | String[]       | 等价于 <url-pattern> 元素，可以触发过滤器                    |
| loadOnStartup  | int            | 等价于 <load-on-startup> 元素                                |
| initParams     | WebInitParam[] | 等价于 <init-param> 元素                                     |
| asyncSupported | boolean        | 等价于 <asynx-supported> 元素，声明 Servlet 对象 是否支持异步处理模式 |
| description    | String         | 等价于 <description> 元素                                    |
| displayName    | String         | 等价于 <display-name> 元素                                   |

这是一个 web.xml 文件，里面包含对 SampleServlet 对象的配置。
```xml
<servlet>
	<servlet-name>SampleServlet</servlet-name>
	<servlet-class>com.likezhen.helloapp.SampleServlet</servlet-class>
	<discription>this is sample servlet</descripiton>
	<init-param>
		<param-name>color</param-name>
		<param-value>blue</param-value>
	</init-param>
	<load-on-startup>1</load-on-startup>
</servlet>
<servlet-mapping>
	<servlet-name>SampleServlet</servlet-name>
	<url-pattern>/sample</url-pattern>
</servlet-mapping>
```
改为注解配置，源代码如下

```java
@WebServlet(name = "SampleServlet",
        description = "this is sample servlet",
        urlPatterns = "/sample",
        initParams = {
            @WebInitParam(name = "color", value = "blue")
        },
        loadOnStartup = 1)
public class SampleServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
```

#### 3.3.2 其他注解

| 注解                  | 描述                                                         |
| --------------------- | ------------------------------------------------------------ |
| @WebInitParam         | 配置初始化参数                                               |
| @WebFilter            | 配置过滤器                                                   |
| @WebListener          | 配置监听器                                                   |
| @HandlesTypes         |                                                              |
| @HttpConstraint       |                                                              |
| @HttpMethodConstraint |                                                              |
| @MultipartConfig      | 配置的 Servlet 对象能够接收 "multipart/form-data " MIME 类型 |
| @ServletSecurity      | 配置安全约束                                                 |