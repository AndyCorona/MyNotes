package com.design_pattern.www.Prototype.Version1;

/**
 * 原型接口，一般只有一个 clone 方法
 */
interface Prototype {
    Prototype clone();
}

/**
 * 引用数据类型，作为原型对象的成员变量，为了说明深拷贝和浅拷贝的区别
 * 浅拷贝：基本数据类型和引用数据类型都是值传递
 * 深拷贝：基本数据类型值传递，引用数据类型引用传递
 */
class Reference {
}

/**
 * 实现克隆功能的原型对象
 */
class ConcretePrototype implements Prototype {

    private int field;
    private Reference reference;

    public int getField() {
        return field;
    }

    public void setField(int field) {
        this.field = field;
    }

    public Reference getReference() {
        return reference;
    }

    public void setReference(Reference reference) {
        this.reference = reference;
    }

    /**
     * 手写 clone方法实现原型模式浅拷贝
     */
    @Override
    public Prototype clone() {
        ConcretePrototype concretePrototype = new ConcretePrototype();
        concretePrototype.setField(this.field);
        concretePrototype.setReference(this.reference);
        return concretePrototype;
    }
}

class Client {
    public static void main(String[] args) {

        //先创建一个原型对象
        ConcretePrototype prototype = new ConcretePrototype();
        prototype.setField(1);
        prototype.setReference(new Reference());

        //通过原型对象的 clone 方法创建克隆对象
        ConcretePrototype clonePrototype = (ConcretePrototype) prototype.clone();

        //基本数据类型和 String 类为值传递
        clonePrototype.setField(2);
        System.out.println(prototype.getField() == clonePrototype.getField()); //false

        //克隆对象只拷贝了引用数据类型的地址
        System.out.println(prototype.getReference() == clonePrototype.getReference()); //true
    }
}




