package com.design_pattern.www.Adapter.Version1;

/**
 * 对象适配器：定义客户端使用的适配器抽象类，且被适配的类会聚合到具体的适配器子类里。
 */

/**
 * 适配器抽象类。给客户端使用
 */
abstract class Target {
    public abstract String request();
}

/**
 * 被适配的类
 */
class Adaptee {
    public String method() { return "被适配前";}
}

/**
 * 具体 的适配器子类。被适配的类聚合到这里
 * 将被适配的类 Adaptee 转换成适配器抽象类 Target
 */
class Adapter extends Target {
    private Adaptee adaptee;

    public Adapter(Adaptee adaptee) {
        this.adaptee = adaptee;
    }

    //实现具体的适配过程
    @Override
    public String request() {
        String str = adaptee.method();
        return str.replace("前", "后");
    }
}

class Client {
    public static void main(String[] args) {
        Adaptee adaptee = new Adaptee();
        Target target = new Adapter(adaptee);
        System.out.println(target.request());
    }
}