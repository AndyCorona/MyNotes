package com.likzhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "PushServlet", value = "/push")
public class PushServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=GBK");
        PushBuilder builder = request.newPushBuilder();
        PrintWriter out = response.getWriter();
        if (builder != null) {
            builder.path("helloapp/resource/correct.png");
            builder.push();
            out.println("<html><body><p>以上图片来自服务器推送</p></body></html>");
        } else {
            out.println("<html><body><p>当前 HTTP 协议不支持服务器推送</p></body></html>");
        }
        out.close();
    }
}
