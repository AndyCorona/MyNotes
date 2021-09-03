package com.design_pattern.www.Prototype.Version2;


class Reference {
}

/**
 * Java 中的 Cloneable 就是原型接口
 * 实现了 Cloneable 接口就不用再自定义原型接口
 */
class ConcretePrototype implements Cloneable {

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
     * 实现 Cloneable 接口，使用 Object 类的 clone 方法实现浅拷贝
     *
     * @return Object对象
     */
    @Override
    protected Object clone() {
        Object obj = null;
        try {
            obj = super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return obj;
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




