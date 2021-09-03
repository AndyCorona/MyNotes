# 第三章 Servlet 技术（上）

### 3.1 Servlet API
Servlet API 主要由两个 java 包组成：javax.servlet 和 javax.servlet.http。
javax.servlet 包中定义了 Servlet 接口以及相关的通用接口和类，如接口 ServletConfig、ServletContext、RequsetDispatcher、ServletRequest、ServletResponse、Servlet 和 Generic Servlet。
javax.servlet.http 包中定义了与 HTTP 协议相关的 HttpServlet 类、HttpServletRequest 和 HttpServletResponse 接口。

### 3.2 Servlet 接口

所有 Servlet 类都必须实现 javax.servlet.Servlet 接口。此接口定义了 5 个方法，其中有 3 个由 Servlet 容器调用，容器会在 Servlet 生命周期的不同阶段调用特定方法：
1. init(ServletConfig config) 方法负责初始化 Servlet 对象。容器在创建好 Servlet 对象之后，就会调用该方法。
2. service(ServletRequest req, ServletResponse res) 方法负责响应客户的请求，为客户提供相应的服务。容器接收到客户端要求访问特定 Servlet 对象的请求时，就会调用该 Servlet 对象的 service 方法。
3. destory() 方法负责释放 Servlet 对象占用的资源。当 Servlet 对象结束生命周期时，容器会调用此方法。

还有 2 个返回 Servlet 信息的方法。Web 应用中的代码可以调用 Servlet 的这两个方法。
1. getServletConfig() 返回一个 ServletConfig 对象，该对象包含 Servlet 初始化参数信息。
2. getServletInfo() 返回一个字符串包含 Servlet 的创建者、版本和版权等信息。

在 Servlet API 中，javax.servlet.GenericServlet 抽象类实现了 Servlet 接口，javax.servlet.http.HttpServlet 抽象类是 GenericServlet 的子类。当用户开发自己的 Servlet 类时，可以选在 GenericSerlvet 或 HTTPServlet 抽象类。

### 3.3 GenericServlet 抽象类

GeneticServlet 抽象类实现了 Servlet、ServletConfig 和 Serializable 接口。它与任何网络应用层协议无关。

### 3.4 HttpServlet 抽象类

是 GenericServlet 类的子类。为 Servlet 接口提供了与 HTTP 协议相关的实现。在开发 Web 应用时，自定义的 Servlet 类一般都继承 HttpServlet 类。
针对不同的客户请求，HttpServlet 类提供了对应的服务方法，如 doGet()、doPost()、doPut()、doDelete() 等方法。默认实现为向客户端返回一个错误：
- 如果客户与服务器之间采用 HTTP1.1 协议通信，则返回错误HttpServletResponse.SC_METHOD_NOT_ALLOWED(响应状态码 405)
- 如果客户端与服务器之间不是采用 HTTP1.1 协议通信，返回错误 HttpServletResponse.SC_BAD_REQUEST(响应状态码 400)

对于 HttpServlet 类的具体子类，一般会针对客户端的请求方法，重写 HttpServlet 中对应的 doXXX() 方法。

### 3.5 ServletRequest 接口

Servlet 接口的 service(ServletRequest req, ServletResponse res) 方法中有一个 ServletRequest 类型的参数，表示来自客户端的请求。当 Servlet 容器接收客户端访问特定 Servlet
的请求时，容器先解析客户端的原始请求数据，把它包装成一个 ServletRequest 对象，并传入 service() 方法中。
ServletRequest 接口提供了一系列用于读取客户端请求数据的方法：
- getContentLength()：返回请求正文长度。若长度未知，返回-1。
- getContentType()：返回请求正文的 MIME 类型，若类型未知，返回 null。
- getInputStream()：返回用于读取请求正文的输入流。
- getLocalAddr()：返回服务器端的 IP 地址。
- getLocalName()：返回服务器端的主机名。
- getLocalPort()：返回服务器端的 FTP 端口号。
- getParameter(String name)：根据给定的请求参数名，返回客户请求中对应的请求参数值。
- getProtoclo()：返回客户端与服务器通信所用的协议名称及版本号
- getReader()：返回读取字符串形式的请求正文的 BufferedReader 对象。
- getRemoteAddr()：返回客户端的 IP 地址。
- getRemoteHost()：返回客户端主机名。
- getRemoteHost()：返回客户端的 FTP 端口号。
- setAttribute(String name, java.lang.Object object)：在请求范围内保存一个属性，name 为属性名，object 为属性值。
- getAttribute(String name)：根据 name 参数返回请求范围内匹配的属性值。
- removeAttribute(String name)：从请求范围内删除一个属性。

### 3.6 HttpServletRequest 接口

是 ServletRequest 接口的子接口，提供了用于读取 HTTP 请求中相关信息的方法：
- getContextPath()：返回客户端所请求的 Web 应用的 URL 入口。
- getCookies()：返回 HTTP 请求中的所有 Cookie。
- getHeader(String name)：返回 HTTP 请求头部的特定项。
- getHeaderNames()：返回一个 Enumeration 对象，包含 HTTP 请求头部的所有项目名。
- getMethod()：返回 HTTP 请求方式。
- getRequestURI()：返回 HTTP 请求头第一行的 URI。
- getQueryString()：返回 HTTP 请求的查询字符串（请求参数）。

### 3.7 ServletResponse 接口

Servlet 接口的 service(ServletRequest req, ServletResponse res) 方法中有一个 ServletRespinse 类型的参数，表示服务器生成的响应结果。当 Servlet 容器接收客户端访问特定 Servlet 的请求时，容器会创建一个 ServletResponse 对象，传入 service() 方法中。
ServletResponse 接口定义了一系列与生成响应结果相关的方法：
- getCharacterEncoding(String charset)：设置响应正文的字符编码。默认编码为 ISO-8859-1。
- setContentLength(int len)：设置响应正文的长度。
- setContentTType(String type)：设置响应正文的 MIME 类型。
- getCharacterEncoding()：返回响应正文的字符编码。
- getContentType()：返回响应正文的 MIME 类型。
- setBufferSize(int size)：设置用于存放响应正文数据的缓冲区大小。
- getBufferSize()：获取缓冲区大小。
- reset()：清空缓冲区的正文数据、响应状态码和响应头。
- resetBuffer()：仅仅清空缓冲区的正文数据，不清空响应状态码和响应头。
- flushBuffer()：强制把缓冲区的响应正文数据发送到客户端。
- isCommiiitted()：返回缓冲区的数据是否已经提交给客户端。
- getOutputStream()：返回一个 ServletOutputStream 对象，输出二进制的响应结果正文数据。
- getWriter()：返回一个 PrintWriter 对象，输出字符串形式的响应结果正文数据。

以下几种情况，缓冲区的数据会被发送给客户端：
1. 缓冲区数据已满，ServletOutputStream 或 PrintWriter 会自动把缓冲区内的数据发送给客户端，并清空缓冲区。
2. Servlet 调用 ServletResponse 对象的 flushBuffer() 方法。
3. Servlet 调用 ServletOutputStream 或 PrintWriter 对象的 flush() 或 close() 方法。

在 Tomcat 中，如果 Servlet 的 service() 方法没有调用 ServletOutputStream 或 PrintWriter 的 close() 方法。在调用完 service() 方法后，会关闭 ServletOutputStream 或 PrintWriter 对象，确保 Servlet 输出的所有数据提交给客户端。

### 3.8 HttpServletResponse 接口

是 ServletResponse 接口的子接口，提供了与 HTTP 协议相关的一些方法。
- addHeader(String name, String value)：向 HTTP 响应头中加入一项内容。
- sendError(int sc)：向客户端发送一个代表特定错误的 HTTP 响应状态码。
- sendError(int sc, String msg)：向客户端发送一个 HTTP 响应状态码和具体错误信息。
- setHeader(String name, String value)：设置 HTTP 响应头的一项内容，会覆盖已存在内容。
- setStatus(int sc)：设置 HTTP 响应状态码。
- addCookie(Cookie cookie)：向 HTTP 响应中加入一个 Cookie。

此接口还定义了表示 HTTP 响应状态码的静态常量：
HttpServletResponse.SC_BAD_REQUEST 表示响应状态码 400。
HttpServletResponse.SC_FOUND 表示响应状态码 302。
HttpServletResponse.SC_METHOD_NOT_ALLOWED 表示响应状态码 405。
HttpServletResponse.SC_NON_AUTHORITATIVE_INFORMATION 表示响应状态码 203。
HttpServletResponse.SC_FORBIDDEN 表示响应状态码 403。
HttpServletResponse.SC_NOT_FOUND 表示响应状态码 404。
HttpServletResponse.SC_OK 表示响应状态码 200。

### 3.9 ServletConfig 接口

Servlet 接口的 init(ServletConfig config) 方法有一个