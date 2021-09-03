package com.design_pattern.www.Facade;

/**
 * 复杂的子系统A，真正的实现功能，不知道 Facade 对象的存在
 * 不会调用 Facade 对象
 */
class SubsystemA {
    public void methodA() {
    }
}

/**
 * 复杂的子系统B
 */
class SubsystemB {
    public void methodB() {
    }

}

/**
 * Facade 知道并调用各个子系统，封装成更高层的接口，提供客户端需要的功能
 * 一般只需要一个门面，所有可以定义成单例模式
 */
class Facade {
    private Facade() {
    }

    public static void method() {
        SubsystemA subsystemA = new SubsystemA();
        subsystemA.methodA();
        SubsystemB subsystemB = new SubsystemB();
        subsystemB.methodB();
    }
}

/**
 * 客户端直接调用门面提供的功能，不需要直接调用多个复杂的子系统
 */
class Client {
    public static void main(String[] args) {
        Facade.method();
    }
}