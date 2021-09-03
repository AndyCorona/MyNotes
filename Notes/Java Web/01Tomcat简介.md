# 第一章 Tomcat 简介

### 1.1 Tomcat 概述

为了能让 Web 服务器与 Web 应用之间协作，应该制定 Web 服务器与 Web 应用通讯的标准接口。Servlet 是其中最主要的一个接口。Servlet 规范把能够发布和运行 Java Web 应用的 Web 服务器称为 Servlet 容器。

Tomcat 完全由 Java 编写，是 Apache 开源软件组织的一个软件项目。Servlet 规范规定 Servlet 容器响应客户请求访问特定 Servlet 的流程如下：
1. 客户发出访问特定 Servlet 的请求。
2. Servlet 容器接收到请求，对其解析。
3. Servlet 容器创建一个 ServletRequest 对象，包含请求信息。
4. Servlet 容器创建一个 ServletResponse 对象。
5. .Servlet 容器调用客户所请求的 Servlet 的 service() 方法，把 ServletRequest 和 ServletResponse 对象作为参数传入。
6. Servlet 从 ServletRequest 对象获得请求信息。
7. Servlet 用 ServletResponse 对象生成响应结果。
8. Servlet 容器把 Servlet 生成的响应结果发给客户端。

### 1.2 Tomcat 组成

Tomcat 本身由一系列可配置的组件构成。核心组件是 Servlet 容器组件。在<CATAKINA_HOME>/conf/server.xml 文件中配置。
```xml
<Server>
	<Service>
		<Connector/>
		<Engine>
			<<Host>
				<Context>
				</Context>
			</Host>
		</Engine>
	</Service>
</Server>
```
在以上 XML 文件中，每一个元素都代表一种 Tomcat 组件，这些元素分为四类
1. 顶层类元素
<Server> 和 <Service> 元素位于整个配置文件顶层。
2. 连接器元素
<Connector> 元素代表介于客户与服务器之间的通信接口，将客户请求发给服务器，将服务器响应发送给客户。
3. 容器类元素
处理客户请求并生成响应结果的组件，有四种容器类元素，分别为 <Engine>, <Host>, <Context>, <Cluster> 元素。Engine 组件为特定的 Service 组件处理所有客户请求，Host 组件为特定的虚拟主机处理所有客户请求。Context 组件为特定的 Web 应用处理所有客户请求，Cluster 组件为 Tomcat 集群服务。
4. 嵌套类元素
如 <Valve> 和 <Realm> 等元素。

<Server> 代表整个 Servlet 容器，它是 Tomcat 的顶层元素，可以包含多个 <Service> 元素。
<Service> 元素包含一个 <Engine> 元素和多个 <Connector> 元素，多个 <Connector> 元素贡献那个一个 <Engine> 元素。
<Engine> 元素处理同一个 <Service> 中所有 <Connector> 元素接收到的客户请求。
<Host> 元素定义虚拟主机，一个 <Engine> 元素包含多个 <Host> 元素。
<Context> 元素代表运行在虚拟主机上的单个 Web 应用。一个 <Host> 上可包含多个 <Context>。
Tomcat 的 server.xml 中已经配置了 <Server>、<Service>、<Connector>、<Engine>、<Host> 等组件。
```xml

<Server port="8005" shutdown="SHUTDOWN">
  <Listener className="org.apache.catalina.startup.VersionLoggerListener" />
  <Listener className="org.apache.catalina.core.AprLifecycleListener" SSLEngine="on" />
  <Listener className="org.apache.catalina.core.JreMemoryLeakPreventionListener" />
  <Listener className="org.apache.catalina.mbeans.GlobalResourcesLifecycleListener" />
  <Listener className="org.apache.catalina.core.ThreadLocalLeakPreventionListener" />
  <GlobalNamingResources>
    <Resource name="UserDatabase" auth="Container"
              type="org.apache.catalina.UserDatabase"
              description="User database that can be updated and saved"
              factory="org.apache.catalina.users.MemoryUserDatabaseFactory"
              pathname="conf/tomcat-users.xml" />
  </GlobalNamingResources>
  <Service name="Catalina">
    <Connector port="8080" protocol="HTTP/1.1"
               connectionTimeout="20000"
               redirectPort="8443" />
    <Engine name="Catalina" defaultHost="localhost">
      <Realm className="org.apache.catalina.realm.LockOutRealm">
        <Realm className="org.apache.catalina.realm.UserDatabaseRealm"
               resourceName="UserDatabase"/>
      </Realm>
      <Host name="localhost"  appBase="webapps"
            unpackWARs="true" autoDeploy="true">

        <Valve className="org.apache.catalina.valves.AccessLogValve" directory="logs"
               prefix="localhost_access_log" suffix=".txt"
               pattern="%h %l %u %t &quot;%r&quot; %s %b" />
      </Host>
    </Engine>
  </Service>
</Server>

```

### 1.3 Tomcat 工作模式

1. 独立的 Servlet 容器
    和其他 Java 程序一样，需要启动 Java 虚拟机来运行 Tomcat。
2. 其他 Web 服务器进程内的 Servlet 容器
3. 其他 Web 服务器进程外的 Servlet 容器

### 1.4 Tomcat 版本

| Tomcat 版本 | JDK 版本          | Servlet/JSP 规范 |
| ----------- | ----------------- | ---------------- |
| 9.x         | JDK8 或更高版本   | 4.0/2.3          |
| 8.x         | JDK87或更高版本   | 3.1/2.3          |
| 7.x         | JDK6 或更高版本   | 3.0/2.3          |
| 6.x         | JDK5 或更高版本   | 2.5/2.1          |
| 5.5.x       | JDK1.4 或更高版本 | 2.4/2.0          |
| 5.0.x       | JDK1.4 或更高版本 | 2.4/2.0          |
| 4.1.x       | JDK1.3 或更高版本 | 2.3/1.2          |
| 3.3.1a      | JDK1.3 或更高版本 | 2.2/1.1          |

