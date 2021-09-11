package com.likzhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ReceiveServlet", value = "/sub/receive")
public class ReceiveServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //读取 RedirectServlet 放在请求范围内的参数，但获取不到
        String message = (String) request.getAttribute("msg");
        PrintWriter out = response.getWriter();
        out.println("请求范围中的参数：" + message);

        //读取 msg 请求参数
        message = request.getParameter("msg");
        out.println("请求参数中：" + message);
        out.close();
    }

}
