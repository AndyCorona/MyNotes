package com.design_pattern.www.TemplateMethod;

/**
 *抽象父类，包含多步抽象方法和算法骨架
 */
abstract class AbstractClass {
    //抽象方法，需要子类实现
    public abstract void step1();

    public abstract void step2();

    //钩子方法，空的默认实现，子类按需重写
    public void optionalStep() {
    }

    //模板方法，即算法骨架。使用多步抽象方法，final 修饰不允许子类重写
    protected final void templateMethod() {
        System.out.println("开始执行");
        step1();
        step2();
        optionalStep();
        System.out.println("执行结束");
    }

}

/**
 *具体子类A。实现父类的抽象方法，实现钩子方法
 * 无法重写模板方法
 */
class ConcreteClassA extends AbstractClass {
    @Override
    public void step1() {
        System.out.println("类A的第一步");
    }

    @Override
    public void step2() {
        System.out.println("类A的第二步");
    }

    @Override
    public void optionalStep() {
        System.out.println("额外的步骤");
    }
}

/**
 *具体子类B。实现父类的抽象方法，不实现钩子方法
 */
class ConcreteClassB extends AbstractClass {
    @Override
    public void step1() {
        System.out.println("类B的第一步");
    }

    @Override
    public void step2() {
        System.out.println("类B的第一步");
    }
}


class Client {
    public static void main(String[] args) {
        //创建具体子类对象
        AbstractClass concreteClassA = new ConcreteClassA();
        //调用父类的模板方法
        concreteClassA.templateMethod();

        System.out.println("-------------------------------");
        AbstractClass concreteClassB = new ConcreteClassB();
        concreteClassB.templateMethod();
    }
}