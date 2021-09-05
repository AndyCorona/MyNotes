# 第六章 JSP 技术

JSP 是 Java Server Page 的缩写，它是 Servle 的扩展，目的是为了简化创建和维护动态网站的工作。

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

JSP 技术吸取 HTML 静态页面和 Servlet 地优点，摒弃两者的缺点。大大简化动态生成网页的工作。在传统的 HTML 文档中加入 Java 程序片段和 JSP 标记，就构成 JSP 文件。