package com.likezhen.helloapp;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "LogoutServlet", value = "/logout")
public class Logout extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        resp.setContentType("text/html; charset=gbk");
        PrintWriter ps = resp.getWriter();
        ps.println("<html><head><title>注销</title></head><body>");

        HttpSession session = req.getSession();

        String name = (String) session.getAttribute("username");

        session.invalidate();

        ps.println("<p>再见，" + name + "</p>\n" +
                "<a href=\"login\">重新登录</a>\n" +
                "\n" +
                "</body>\n" +
                "</html>");

    }

}
