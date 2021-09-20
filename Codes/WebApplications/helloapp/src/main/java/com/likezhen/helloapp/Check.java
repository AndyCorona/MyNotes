package com.likezhen.helloapp;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * 使用会话的 Servlet 类
 */
@WebServlet(name = "checkServlet", value = "/checkout")
public class Check extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html; charset=gbk");
        PrintWriter ps = resp.getWriter();
        ps.println("<html><head><title>验证</title></head><body>");

        HttpSession session = req.getSession();

        String name = null;
        name = req.getParameter("username");
        if (name == null) {
            name = (String) session.getAttribute("username");
            if (name == null) {
                resp.sendRedirect("/login");
            }
        } else {
            session.setAttribute("username", name);
        }

        ps.println("<a href=\"login\">切换账号</a>\n" +
                "<a href=\"logout\">注销</a>\n" +
                "<p>当前用户为：" + name +
                "</p>\n" +
                "</body>\n" +
                "</html>");
    }
}
