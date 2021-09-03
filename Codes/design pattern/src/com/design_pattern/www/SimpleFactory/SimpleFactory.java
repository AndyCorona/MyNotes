package com.design_pattern.www.SimpleFactory;


interface Product {
    void method();
}


class ConcreteProductA implements Product {

    @Override
    public void method() {
        System.out.println("产品A");
    }
}

class ConcreteProductB implements Product {

    @Override
    public void method() {
        System.out.println("产品B");
    }
}

/**
 * 简单工厂，将创建对象的过程放在工厂里
 */
public class SimpleFactory {
    public Product createProduct(String str) {
        Product product = null;
        if (str == "A") {
            product = new ConcreteProductA();
        } else if (str == "B") {
            product = new ConcreteProductB();
        }
        return product;
    }
}

class Client {
    public static void main(String[] args) {
        SimpleFactory simpleFactory = new SimpleFactory();
        Product product = simpleFactory.createProduct("A");
        product.method();
    }
}


