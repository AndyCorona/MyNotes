package com.design_pattern.www.Decorator;


/**
 * 组件接口，包含装饰者和被装饰者共同拥有的通用方法
 * 聚合到装饰者抽象类中
 */
interface Component {
    void methodA();

    void methodB();
}

/**
 * 具体的组件类，也是被装饰者。定义了被装饰者的一些基础行为
 */
class ConcreteComponent implements Component {
    @Override
    public void methodA() {
        System.out.println("方法A被装饰前");
    }

    @Override
    public void methodB() {
        System.out.println("方法B被装饰前");
    }
}

/**
 * 装饰者抽象类，实现了组件接口
 */
abstract class Decorator implements Component {
    protected Component component;

    public Decorator(Component component) {
        this.component = component;
    }
}

/**
 * 具体的装饰者。调用被装饰者原有的行为进行装饰
 */
class ConcreteDecorator extends Decorator {

    public ConcreteDecorator(Component component) {
        super(component);
    }

    //具体的装饰过程
    @Override
    public void methodA() {
        component.methodA();
        decorate();
    }

    @Override
    public void methodB() {
        component.methodB();
        decorate();
    }

    public void decorate() {
        System.out.println("完成装饰");
    }
}


class Client {
    public static void main(String[] args) {

        //创建被装饰者
        ConcreteComponent component = new ConcreteComponent();
        //创建装饰者，并装饰被装饰者
        ConcreteDecorator decorator = new ConcreteDecorator(component);

        //使用装饰后的功能
        decorator.methodA();
        decorator.methodB();
    }
}