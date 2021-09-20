package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

//读取请求参数，重定向至 ReceiveServlet 对象
@WebServlet(name = "RedirectServlet", value = "/redirect")
public class RedirectServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();

        //获取请求参数
        String username = request.getParameter("username");
        String message = null;
        if (username == null) {
            message = "Please input username";
        } else {
            message = "hello, " + username;
        }

        request.setAttribute("msg", message);

        //向客户端的响应结果和服务器的控制台上输出信息
        out.println("重定向之前client");
        System.out.println("重定向之前server");

//        out.close(); //在重定向之前响应结果已提交给客户端，sendRedirect() 方法会抛出 java.lang.IllegalStateException 异常

        response.sendRedirect("/helloapp/sub/receive?msg=" + message);
//        response.sendRedirect("http://www.baidu.com");

        //向客户端的响应结果和服务器的控制台上输出信息
        out.println("重定向之后client");
        System.out.println("重定向之后server");
    }

}
