package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

//响应结果包含到 DispatcherServlet3 对象中
@WebServlet(name = "DispatcherServlet4", value = "/DispatcherServlet4")
public class DispatcherServlet4 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        out.println("from DispatcherServlet4.java");
        //不要在目标组件中关闭输出流，否则源组件的输出流也关闭，响应结果就直接返回给客户端
    }
}
