package com.likezhen.helloapp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

//asyncSupported = true 表示该 Servlet 对象支持异步处理
@WebServlet(name = "AsyncServlet", value = "/async", asyncSupported = true)
public class AsyncServlet extends HttpServlet {
    //创建线程池
    private static ThreadPoolExecutor executor = new ThreadPoolExecutor(100, 200, 50000L, TimeUnit.MILLISECONDS, new ArrayBlockingQueue<>(100));


    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/plain;charset=GBK");
        AsyncContext asyncContext = request.startAsync();
        //异步线程必须在 60 秒内完成任务
        asyncContext.setTimeout(60 * 1000);
        asyncContext.addListener(new AsyncListener() {

            @Override
            public void onComplete(AsyncEvent event) throws IOException {
                System.out.println("异步线程任务执行完毕");
            }

            @Override
            public void onTimeout(AsyncEvent event) throws IOException {
                System.out.println("异步线程执行任务已超时");
            }

            @Override
            public void onError(AsyncEvent event) throws IOException {
                System.out.println("异步线程执行任务出错");
            }

            @Override
            public void onStartAsync(AsyncEvent event) throws IOException {
                System.out.println("异步线程开始执行任务");
            }
        });

//        //方式一
        asyncContext.start(new AsyncTask(asyncContext));
//
//        //方式二
//        new Thread(new AsyncTask(asyncContext)).start();

        //方式三
//        executor.execute(new AsyncTask(asyncContext));

        System.out.println("主线程运行结束");

    }

    @Override
    public void destroy() {
        //销毁 AsyncServlet 时关闭线程池
        executor.shutdown();
    }
}
