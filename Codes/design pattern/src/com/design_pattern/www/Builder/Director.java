package com.design_pattern.www.Builder;

/**
 * 指导者使用 Builder 接口，以一个统一的过程构建 Product 对象
 */
class Director {
    private Builder builder;

    public Director(Builder builder) {
        this.builder = builder;
    }

    public void construct() {
        builder.methodA();
        builder.methodB();
        builder.methodC();
    }
}

/**
 * 生成器接口，定义创建一个 Product 对象所需要的各个组件的操作
 */
interface Builder {
    void methodA();

    void methodB();

    void methodC();
}

/**
 * 具体的生成器实现。实现各个组件的创建，并负责组装 Product 对象的各个组件。
 * 同时提供一个让用户获取组装完成的对象的方法。
 */
class ConcreteBuilder implements Builder {
    private Product product;

    @Override
    public void methodA() {
        System.out.println("生产产品A的第一步");
    }

    @Override
    public void methodB() {
        System.out.println("生产产品A的第二步");
    }

    @Override
    public void methodC() {
        System.out.println("生产产品A的第三步");
    }

    public Product getProduct() {
        return new Product();
    }
}

class Client {
    public static void main(String[] args) {
        //创建具体的生成器
        ConcreteBuilder builder = new ConcreteBuilder();

        //创建指导者
        Director director = new Director(builder);

        //组装产品
        director.construct();

        //获取产品
        Product product = builder.getProduct();
    }
}

/**
 * 产品。表示被生成器构建的复杂对象。包含多个组件。
 */
class Product {
}
