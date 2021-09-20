package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;

/*处理上传文件请求的 Servlet 请求*/
@WebServlet(name = "UploadServlet", value = "/upload")
@MultipartConfig
public class UploadServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //设置响应头类型
        response.setContentType("text/plain");

        //设置保存文件路径
        String savePath = request.getServletContext().getRealPath("/resource");
        PrintWriter out = response.getWriter();
        //获取正文表单数据，放到 Part 对象集合中
        Collection<Part> parts = request.getParts();
        for (Part part : parts) {
            String type = part.getContentType();
            long size = part.getSize();
            String name = part.getName();
            String header = part.getHeader("content-disposition");
            //在 Tomcat 服务器上显示每个子部分的信息
            System.out.println("----Part----");
            System.out.println("type: " + type);
            System.out.println("size: " + size);
            System.out.println("name: " + name);
            System.out.println("header: " + header);

            //如果子部分为普通表单域，向客户端发送名字和取值
            if (type == null) {
                String value = request.getParameter(name);
                out.println(name + ":" + value + "\r\n");
                //如果子部分为 file1 和 file2 文件域，保存上传文件
            } else if (name.indexOf("file") != -1) {
                String filename = part.getSubmittedFileName();
                part.write(savePath + File.separator + filename);
                //保存完毕，向客户端发送反馈信息
                out.println(filename + " is saved.");
                out.println("The size of " + filename + " is " + size + " byte\r\n");
            }
        }
        out.close();
    }
}
