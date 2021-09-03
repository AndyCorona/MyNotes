package com.design_pattern.www.Bridge;

/**
 * 桥接模式连接了类的抽象层次结构和类的实现层次结构
 * 抽象层次结构：父类具有基本功能，子类增加新的功能
 * 实现层次结构：接口定义抽象方法，实现类实现抽象方法
 */

/**
 * 实现者。提供基本的操作，聚合到抽象类中
 */
interface Implementor {
    void methodA();

    void methodB();

    void methodC();
}

/**
 * 具体实现者，提供基本的具体操作
 */
class ConcreteImplementor implements Implementor {
    @Override
    public void methodA() {
        System.out.println("基本功能一");
    }

    @Override
    public void methodB() {
        System.out.println("基本功能二");
    }

    @Override
    public void methodC() {
        System.out.println("基本功能三");
    }
}


/**
 *抽象化。使用实现者提供的基本操作
 */
abstract class Abstraction {
    protected Implementor implementor;

    public Abstraction(Implementor implementor) {
        this.implementor = implementor;
    }

    public void operation1() {
        System.out.println("模块一需要：");
        implementor.methodA();
        implementor.methodB();
    }

    public void operation2() {
        System.out.println("模块二需要：");
        implementor.methodC();
    }
}

/**
 *增加新功能后的抽象化。
 */
class RefinedAbstraction extends Abstraction {
    public RefinedAbstraction(Implementor implementor) {
        super(implementor);
    }

    public void extendOperation() {
        System.out.println("扩展的模块");
    }
}

class Client {
    public static void main(String[] args) {
        Implementor impl = new ConcreteImplementor();
        Abstraction abstraction = new RefinedAbstraction(impl);
        abstraction.operation1();
    }
}