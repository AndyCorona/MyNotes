package com.likezhen.helloapp;

import javax.servlet.*;
import java.io.IOException;
import java.io.PrintWriter;

/*
串联过滤器1
 */
public class Filter1 implements javax.servlet.Filter {
    private FilterConfig config = null;
    private String value = null;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        //获取 FilterConfig 对象，读取设定好的过滤初始参数
        this.config = filterConfig;
        value = config.getInitParameter("username");
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {

        //获取客户请求参数中的用户名
        String username = request.getParameter("username");

        //拦截指定用户名
        if (username.contains(value)) {

            response.setContentType("text/html; charset=utf-8");

            PrintWriter out = response.getWriter();
            out.println("<html<head><title>拒绝服务</title></head></html><body>");
            out.println("对不起，服务器无法为您提供服务</body></html>");

            //强制返回响应结果
            out.close();
            //不再执行后续的请求转发
            return;
        }

        //请求转发给后续过滤器或 Web 组件
        chain.doFilter(request, response);

        System.out.println("所有串联过滤器已执行完毕");
    }
}

