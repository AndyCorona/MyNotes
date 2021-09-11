package com.likzhen.helloapp;

import javax.servlet.AsyncContext;

public class AsyncTask implements Runnable {
    private AsyncContext async;

    public AsyncTask(AsyncContext async) {
        this.async = async;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(2 * 1000);
            async.getResponse().getWriter().println("花费2秒完成处理");
            async.complete();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
