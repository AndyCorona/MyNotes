package chatter.web;

import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.HandlerExceptionResolver;

import javax.servlet.Filter;
import javax.servlet.ServletContext;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.*;
import java.util.UUID;

@Controller
public class UploadAndDownload {

    @GetMapping("/download")
    public String download(HttpServletRequest request, HttpServletResponse response) throws IOException {

        ServletContext servletContext = request.getServletContext();

        //获取查询参数中的文件名
        String filename = request.getParameter("filename");
        //获取文件在服务器上的真实路径
        String realPath = servletContext.getRealPath("WEB-INF/classes/static/" + filename);
        //获取文件输入流
        FileInputStream is = new FileInputStream(realPath);
        //获取文件大小
        int fileLength = is.available();

        //设置响应头
        response.setContentType("application/octet-stream");
        response.setHeader("Content-Length", String.valueOf(fileLength));
        response.setHeader("Content-Disposition", "attachment;filename=\"" + filename + "\"");

        //获取响应对象的输出流
        ServletOutputStream out = response.getOutputStream();

        int length = 0;
        byte[] buff = new byte[512];
        while ((length = is.read(buff)) != -1) {
            out.write(buff, 0, length);
        }

        is.close();
        out.close();

        return "uploadAndDownload";
    }

    @PostMapping("/upload")
    public String upload(@RequestParam("uploadFile") MultipartFile multipartFile, HttpSession session) throws IOException {

        ServletContext servletContext = session.getServletContext();
        String realPath = servletContext.getRealPath("/WEB-INF/classes/static");

        //获取文件名字
        String name = multipartFile.getOriginalFilename();

        //创建文件最终存放路径
        String finalPath = realPath + File.separator + name;
        File file = new File(finalPath);

        //文件保存至指定位置
        multipartFile.transferTo(file);

        return "uploadAndDownload";
    }

}
