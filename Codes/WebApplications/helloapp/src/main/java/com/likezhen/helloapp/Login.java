package com.likezhen.helloapp;

import javax.naming.Name;
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
@WebServlet(name = "loginServlet", value = "/login")
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html;charset=gbk");
        PrintWriter ps = resp.getWriter();
        ps.println("<html><head><title>登录</title></head><body>");

        //获取 HttpSession 对象
        HttpSession session = req.getSession();

        String name = "";
        if (!session.isNew()) {
            name = (String) session.getAttribute("username");
            if (name == null) name = "";
        }

        ps.println("<p>欢迎光临，请登录</p>\n" +
                "<p>SessionID: " + session.getId() + "</p>\n" +
                "\n" +
                "<form name=\"loginForm\" action=\"checkout\" method=\"post\">\n" +
                "    <table>\n" +
                "        <tr>\n" +
                "            <td>用户名：</td>\n" +
                "            <td><input type=\"text\" name=\"username\" value=\"" + name + "\" autofocus required></td>\n" +
                "        </tr>\n" +
                "        <tr>\n" +
                "            <td>密码：</td>\n" +
                "            <td><input type=\"text\" name=\"password\" value=\"\" required></td>\n" +
                "        </tr>\n" +
                "        <tr>\n" +
                "            <td><input type=\"submit\" name=\"submit\" value=\"提交\"></td>\n" +
                "        </tr>\n" +
                "    </table>\n" +
                "</form>\n" +
                "</body>\n" +
                "</html>");
    }
}
