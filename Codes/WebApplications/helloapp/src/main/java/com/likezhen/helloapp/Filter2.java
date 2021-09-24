package com.likezhen.helloapp;

import javax.servlet.*;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * 串联过滤器2
 */
public class Filter2 implements javax.servlet.Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        Filter.super.init(filterConfig);
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {

        String username = request.getParameter("username");
        //拦截管理员用户
        if (username.equals("root")) {
            response.setContentType("text/html; charset=utf-8");

            PrintWriter out = response.getWriter();
            out.println("<html<head><title>友情提示</title></head></html><body>");
            out.println("管理员请从后台登录</body></html>");

            //强制返回响应结果
            out.close();
            //不再执行后续的请求转发
            return;
        }
        chain.doFilter(request, response);

        System.out.println("Service() 方法执行完毕");
    }
}

