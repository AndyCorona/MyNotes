package com.likezhen.helloapp;

import javax.servlet.http.HttpSessionActivationListener;
import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionBindingListener;
import javax.servlet.http.HttpSessionEvent;
import java.io.Serializable;

/**
 * 和会话绑定的属性
 */
public class MyData implements HttpSessionBindingListener, HttpSessionActivationListener, Serializable {
    String name;

    public MyData() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public void sessionWillPassivate(HttpSessionEvent se) {
        System.out.println("搁置会话");
    }

    @Override
    public void sessionDidActivate(HttpSessionEvent se) {
        System.out.println("激活会话");
    }

    @Override
    public void valueBound(HttpSessionBindingEvent event) {
        System.out.println("MyData 对象绑定到当前会话");
    }

    @Override
    public void valueUnbound(HttpSessionBindingEvent event) {
        System.out.println("MyData 对象和当前会话解绑");
    }
}
