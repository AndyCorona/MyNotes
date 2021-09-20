package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.awt.*;
import java.io.IOException;

@WebServlet(name = "SampleServlet",
        description = "this is sample servlet",
        urlPatterns = "/sample",
        initParams = {
                @WebInitParam(name = "color", value = "blue")
        },
        loadOnStartup = 1)
public class SampleServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
