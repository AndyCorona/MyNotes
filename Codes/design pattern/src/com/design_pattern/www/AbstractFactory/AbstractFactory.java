package com.design_pattern.www.AbstractFactory;


/**
 * 抽象产品接口，构成一组不同但相关的产品系列  ProductA，如 CPU。
 */
interface ProductA {
    void methodA();
}

/**
 * 具体产品是抽象产品的多种不同类型实现，如 Intel CPU 和 AMD CPU。
 */
class ConcreteProductA1 implements ProductA {
    @Override
    public void methodA() {
        System.out.println("产品A1");
    }
}

class ConcreteProductA2 implements ProductA {
    @Override
    public void methodA() {
        System.out.println("产品A2");
    }
}

interface ProductB {
    void methodB();
}

class ConcreteProductB1 implements ProductB {
    @Override
    public void methodB() {
        System.out.println("产品B1");
    }
}

class ConcreteProductB2 implements ProductB {
    @Override
    public void methodB() {
        System.out.println("产品B2");
    }
}

/**
 * 抽象工厂 接口声明了一组创建各种抽象产品的方法。
 */
interface AbstractFactory {
    ProductA createProductA();

    ProductB createProductB();
}

/**
 * 具体工厂实现抽象工厂的创建方法。每个具体工厂都对应一个产品簇。
 */
class ConcreteFactory1 implements AbstractFactory {
    @Override
    public ProductA createProductA() {
        return new ConcreteProductA1();
    }

    @Override
    public ProductB createProductB() {
        return new ConcreteProductB1();
    }
}

class ConcreteFactory2 implements AbstractFactory {
    @Override
    public ProductA createProductA() {
        return new ConcreteProductA2();
    }

    @Override
    public ProductB createProductB() {
        return new ConcreteProductB2();
    }
}

/**
 * 对不同类型的产品进行组装。
 */
class Application {
    private ProductA pa;
    private ProductB pb;

    public Application(AbstractFactory factory) {
        pa = factory.createProductA();
        pb = factory.createProductB();
    }

    public void operation() {
        pa.methodA();
        pb.methodB();
    }
}

class Client {

    private Application appt;
    private ConcreteFactory1 factory1;

    public static void main(String[] args) {
        Application app = new Application(new ConcreteFactory1());
        app.operation();
    }
}