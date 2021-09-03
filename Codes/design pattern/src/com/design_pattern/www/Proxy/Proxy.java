package com.design_pattern.www.Proxy;

/**
 * 定义代理对象和被代理对象的共同接口
 * 在任何使用被代理对象的地方都可以使用代理对象
 */
interface Subject {
    void request();
}

/**
 * 代理对象，实现和被代理对象一样的接口，代替被代理对象
 * 被代理对象聚合进来，确保代理对象有需要时可以使用被代理对象，完成代理对象无法完成的工作
 */
class Proxy implements Subject {

    private RealSubject realSubject;

    public Proxy(RealSubject realSubject) {
        this.realSubject = realSubject;
    }

    @Override
    public void request() {
        System.out.println("代理开始");
        realSubject.request();
        System.out.println("代理结束");
    }
}

/**
 * 被代理对象，真正的实现功能
 * 在代理对象不能完成客户端的需求时出场
 */
class RealSubject implements Subject {
    @Override
    public void request() {
        System.out.println("被代理的对象实现的功能");
    }
}

/**
 * 客户端不关心使用代理对象还是被代理对象
 */
class Client {
    public static void main(String[] args) {
        Subject subject = new Proxy(new RealSubject());
        subject.request();
    }
}