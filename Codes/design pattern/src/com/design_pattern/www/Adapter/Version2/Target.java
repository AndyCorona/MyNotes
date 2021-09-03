package com.design_pattern.www.Adapter.Version2;

/**
 * 类适配器：定义客户端使用的适配器接口，且具体的适配器子类会继承被适配的类
 */

/**
 * 适配器接口。给客户端使用
 */
interface Target {
    String request();
}

/**
 * 被适配的类
 */
class Adaptee {
    public String method() {
        return "被适配前";
    }
}

/**
 * 具体 的适配器子类。将继承被适配的类并实现适配器接口
 * 将被适配的类 Adaptee 转换成适配器抽象类 Target
 */
class Adapter extends Adaptee implements Target {
    //实现具体的适配过程
    @Override
    public String request() {
        String str = super.method();
        return str.replace("前", "后");
    }
    
}

class Client {
    public static void main(String[] args) {
        Adaptee adaptee = new Adaptee();
        Target target = new Adapter();
        System.out.println(target.request());
    }
}