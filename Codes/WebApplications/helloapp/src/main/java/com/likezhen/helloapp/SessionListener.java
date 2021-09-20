package com.likezhen.helloapp;

import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * 监听会话的 Servlet
 */
public class SessionListener implements HttpSessionListener, HttpSessionAttributeListener {
    @Override
    public void attributeAdded(HttpSessionBindingEvent event) {
        System.out.println("向会话中添加属性");
    }

    @Override
    public void attributeRemoved(HttpSessionBindingEvent event) {
        System.out.println("移除会话中的一个属性");
    }

    @Override
    public void attributeReplaced(HttpSessionBindingEvent event) {
        System.out.println("替换会话中的一个属性");
    }

    @Override
    public void sessionCreated(HttpSessionEvent se) {
        System.out.println("创建会话");
    }

    @Override
    public void sessionDestroyed(HttpSessionEvent se) {
        System.out.println("销毁会话");
    }
}

