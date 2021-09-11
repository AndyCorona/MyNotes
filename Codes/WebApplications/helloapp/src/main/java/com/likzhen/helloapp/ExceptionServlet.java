package com.likzhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ExceptionServlet", value = "/excep")
public class ExceptionServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String condition = request.getParameter("condition");
        if (condition == null) condition = "ok";
        if (condition.equals("1")) {
            throw new ServletException("condition1");
        } else if (condition.equals("2")) {
            //ExceptionServlet 在 2 秒内不能被访问
            throw new UnavailableException("condition2", 2);
        } else if (condition.equals("3")) {
            //ExceptionServlet 不能被访问，除非重启 Web 应用
            throw new UnavailableException("condition3");
        }
        PrintWriter out = response.getWriter();
        out.println("it's ok");
        out.close();
    }


}
