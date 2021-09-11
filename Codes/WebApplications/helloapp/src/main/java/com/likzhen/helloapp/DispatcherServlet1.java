package com.likzhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

//读取请求参数，并转发给 DispatcherServlet2
@WebServlet(name = "DispatcherServlet1", value = "/check")
public class DispatcherServlet1 extends HttpServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        String username = req.getParameter("username");
        String message = null;
        if (username == null) {
            message = "please input username";
        } else {
            message = "hello, " + username;
        }

        req.setAttribute("msg", message);

        //方式一
//        ServletContext servletContext = req.getServletContext();
//        RequestDispatcher dispatcher = servletContext.getRequestDispatcher("/sub/output");
        //方式二
//        RequestDispatcher dispatcher = req.getRequestDispatcher("/sub/output");
        //方式三
        RequestDispatcher dispatcher = req.getRequestDispatcher("sub/output");

        PrintWriter out = res.getWriter();

        //向客户端的响应结果和服务器的控制台上输出信息
        out.println("转发之前client");
        System.out.println("转发之前server");

//        out.close(); //在请求转发之前响应结果已提交给客户端，forward() 方法会抛出 java.lang.IllegalStateException 异常
        dispatcher.forward(req, res);

        //向客户端的响应结果和服务器的控制台上输出信息
        out.println("转发之后client");
        System.out.println("转发之后server");
    }
}
