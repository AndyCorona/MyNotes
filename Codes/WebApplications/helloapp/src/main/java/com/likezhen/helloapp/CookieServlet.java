package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

//读写 Cookie 的 Servlet 类
@WebServlet(name = "CookieServlet", value = "/cookie")
public class CookieServlet extends HttpServlet {
    int count = 0;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/plain");
        PrintWriter out = response.getWriter();

        //获取 HTTP 请求中的所有 Cookie
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (int i = 0; i < cookies.length; i++) {
                out.println("cookie name: " + cookies[i].getName());
                out.println("cookie value: " + cookies[i].getValue());
                out.println("max age: " + cookies[i].getMaxAge());
            }
        } else {
            out.println("no cookie");
        }

        //向客户端写一个 Cookie
        response.addCookie(new Cookie("cookie" + String.valueOf(count), String.valueOf(count)));
        count++;
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
