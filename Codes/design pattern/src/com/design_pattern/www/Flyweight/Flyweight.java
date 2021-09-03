package com.design_pattern.www.Flyweight;

import java.util.HashMap;
import java.util.Map;

/**
 * 享元模式关键在分离内部和外部状态
 * 内在状态：包含不变的、 可在许多对象中重复使用的成员变量。
 * 外在状态：包含每个对象各自不同的成员变量
 * 享元接口，可以传入外部状态供享元对象使用
 */
interface Flyweight {
    void operation(String uniqueFiled);
}

/**
 * 享元对象，储存着内在状态的对象。可以被重复使用。
 * 通过享元工厂创建
 */
class ConcreteFlyweight implements Flyweight {
    private String sharedField;

    public ConcreteFlyweight(String sharedField) {
        this.sharedField = sharedField;
    }

    @Override
    public void operation(String uniqueFiled) {
        System.out.println("内在状态：" + sharedField);
        System.out.println("外在状态：" + uniqueFiled);

    }
}

/**
 * 可选的非共享对象。每个对象储存着各自不同的外部状态。
 * 一般享元对象会聚合进来
 */
class UnsharedConcreteFlyweight implements Flyweight {
    private String uniqueFiled;
    private ConcreteFlyweight concreteFlyweight;

    public UnsharedConcreteFlyweight(String uniqueFiled, ConcreteFlyweight concreteFlyweight) {
        this.uniqueFiled = uniqueFiled;
        this.concreteFlyweight = concreteFlyweight;
    }

    @Override
    public void operation(String uniqueFiled) {
        concreteFlyweight.operation(uniqueFiled);
    }
}

/**
 * 享元工厂，只需一个。所以可设计成单例模式
 * 缓存享元对象。向客户端提供已有的享元对象或创建不存在的享元对象
 */
class FlyweightFactory {

    static Map<String, ConcreteFlyweight> map = new HashMap<>();

    //根据客户端的需要，提供或创建享元对象
    public static ConcreteFlyweight getConcreteFlyweight(String sharedFiled) {
        ConcreteFlyweight result = map.get(sharedFiled);
        if (result == null) {
            result = new ConcreteFlyweight(sharedFiled);
            map.put(sharedFiled, result);
        }
        return result;
    }

    public static int getSize() {
        return map.size();
    }
}

class Client {
    public static void main(String[] args) {
        Flyweight flyweightA = FlyweightFactory.getConcreteFlyweight("绿色的树");
        Flyweight flyweightB = FlyweightFactory.getConcreteFlyweight("绿色的树");
        System.out.println(FlyweightFactory.getSize()); //

        flyweightA.operation("3米的树");
        flyweightB.operation("5米的树");
        System.out.println(FlyweightFactory.getSize());
    }
}

