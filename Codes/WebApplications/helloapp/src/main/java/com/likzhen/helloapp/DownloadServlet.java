package com.likzhen.helloapp;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/*处理下载文件请求的 Servlet 类*/
@WebServlet(name="DownloadServlet", value = "/download")
public class DownloadServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        OutputStream out;
        InputStream in;
        String filename = request.getParameter("filename");

        if (filename == null) {
            out = response.getOutputStream();
            out.write("please input filename.".getBytes());
            out.close();
            return;
        }

        in = getServletContext().getResourceAsStream("/resource/" + filename);
        int length = in.available();

        response.setContentType("application/force-download");
        response.setHeader("Content-Length", String.valueOf(length));
        response.setHeader("Content-Disposition", "attachment;filename=\"" + filename + "\" ");

        out = response.getOutputStream();
        int bytesRead = 0;
        byte[] buffer = new byte[512];
        while ((bytesRead = in.read(buffer)) != -1) {
            out.write(buffer, 0, bytesRead);
        }
        in.close();
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
