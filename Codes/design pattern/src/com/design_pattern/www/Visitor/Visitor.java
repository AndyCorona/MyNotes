package com.design_pattern.www.Visitor;

import java.util.ArrayList;
import java.util.Collection;

/**
 * 访问者接口，为每个元素对象添加 visit 方法
 */
interface Visitor {

    void visit(ConcreteElementA e);

    void visit(ConcreteElementB e);
}

/**
 * 元素对象接口，即被访问者接口。是访问者所访问的对象。
 */
interface Element {
    //声明接受访问者的 accept 方法
    void accept(Visitor visitor);
}

/**
 * 具体的元素对象。
 */
class ConcreteElementA implements Element {
    //回调访问者对象的 visit 方法
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    //元素对象A已有的功能
    public void operationA() {
        System.out.println("操作A");
    }

}

class ConcreteElementB implements Element {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    public void operationB() {
        System.out.println("操作B");
    }
}

/**
 * 具体的访问者对象
 */
class ConcreteVisitor implements Visitor {
    //访问元素对象A时，需要执行的功能
    @Override
    public void visit(ConcreteElementA e) {
        System.out.println("开始访问");
        e.operationA();
        System.out.println("访问结束");
    }

    @Override
    public void visit(ConcreteElementB e) {
        System.out.println("开始访问");
        e.operationB();
        System.out.println("访问结束");
    }
}

/**
 * 对象结构，元素对象的集合。通常对元素对象遍历，让访问者能访问到所有元素
 */
class ObjectStructure {
    private Collection<Element> collection = new ArrayList<Element>();

    public void handleRequest(Visitor visitor) {
        for (Element e : collection) {
            e.accept(visitor);
        }
    }

    public void add(Element e) {
        this.collection.add(e);
    }
}

/**
 * 客户端调用时，第一次分发发生在 accept 方法，第二次分发发生在 visit 方法，最后执行的是具体访问者里的 visit 方法。
 * 在不改变被访问对象的情况下，给其添加新功能。具体的处理都在具体的访问者里，不用修改具体的元素对象
 */
class Client {
    public static void main(String[] args) {
        //创建对象结构
        ObjectStructure objectStructure = new ObjectStructure();
        //创建被访问的元素对象
        Element e1 = new ConcreteElementA();
        Element e2 = new ConcreteElementB();
        //被访问者加入对象结构中
        objectStructure.add(e1);
        objectStructure.add(e2);
        //创建访问者
        Visitor visitor = new ConcreteVisitor();
        //调用业务处理的方法
        objectStructure.handleRequest(visitor);
    }
}