package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

//包含 greeting.html 和 DispatcherServlet4 对象的响应结果
@WebServlet(name = "DispatcherServlet3", value = "/main")
public class DispatcherServlet3 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println("<html><head><title>main</title></head>");
        out.println("<body>");

        ServletContext servletContext = request.getServletContext();
        //获取 RequestDispatcher 对象
        RequestDispatcher htmlDispatcher = servletContext.getRequestDispatcher("/greeting.html");
        RequestDispatcher servletDispatcher = servletContext.getRequestDispatcher("/DispatcherServlet4");

        //包含 greeting.html
        htmlDispatcher.include(request, response);
        out.println("<hr/>");
        //包含 DispatcherServlet4 对象响应结果
        servletDispatcher.include(request, response);
        out.println("<hr/>");
        //包含自身的响应结果
        out.println("<h5>Dispatcher3</h5>");
        out.println("</body></html>");
        out.close();
    }
}
