package com.design_pattern.www.FactoryMethod;

public class FactoryMethod {
}

/**
 * 定义工厂方法所创建的对象的接口
 */
interface Product {
    void method();
}

/**
 * Product 接口的具体实现类 ConcreteProductA
 */
class ConcreteProductA implements Product {
    @Override
    public void method() {
        System.out.println("产品A");
    }
}

/**
 * Product 接口的具体实现类 ConcreteProductA
 */
class ConcreteProductB implements Product {
    @Override
    public void method() {
        System.out.println("产品B");
    }
}

/**
 *创建者声明抽象的工厂方法 createProduct()。 该方法的返回对象类型必须与产品接口相匹配。
 * 创建者最主要的职责不是创建产品。创建者包含一些与产品相关的核心业务逻辑，如 operation()。
 */
abstract class Creator {

    //创建对象的工厂方法，客户端一般不直接调用此方法
    protected abstract Product createProduct();

    //客户端一般使用这些方法
    public void operation() {
        Product product = createProduct();
        product.method();
    }
}

/**
 * 创建者子类 ConcreteCreatorA，返回 ConcreteProductA 对象
 * 类似于简单工厂模式中的 SimpleFactory 方法
 */
class ConcreteCreatorA extends Creator {
    @Override
    protected Product createProduct() {
        return new ConcreteProductA();
    }
}

/**
 * 创建者子类 ConcreteCreatorB，返回 ConcreteProductB 对象
 */
class ConcreteCreatorB extends Creator {
    @Override
    protected Product createProduct() {
        return new ConcreteProductB();
    }
}

class Client {
    public static void main(String[] args) {
        Creator creator = new ConcreteCreatorA();
        creator.operation();
    }
}

