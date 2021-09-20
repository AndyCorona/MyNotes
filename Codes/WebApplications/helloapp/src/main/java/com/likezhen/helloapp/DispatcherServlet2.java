package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "DispatcherServlet2", value = "/sub/output")
public class DispatcherServlet2 extends GenericServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        String message = (String) req.getAttribute("msg");

        PrintWriter out = res.getWriter();
        out.println(message);
        out.close();
    }
}
