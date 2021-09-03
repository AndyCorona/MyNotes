package com.design_pattern.www.Prototype.Version3;

/**
 * 原型对象的所有引用数据类型变量都必须实现 Cloneable 接口
 * 使用 Object 类的 clone 方法
 */
class Reference implements Cloneable {
    @Override
    protected Object clone() {
        Object obj = null;
        try {
            obj = super.clone();
        } catch (
                CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return obj;
    }
}


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
     * 实现深拷贝
     * 缺点：繁琐，所有递归的引用数据类型都要重写 clone 方法
     *
     * @return Object 对象
     */
    @Override
    protected Object clone() {
        ConcretePrototype concretePrototype = null;
        try {
            concretePrototype = (ConcretePrototype) super.clone();

            //调用引用数据类型成员变量的 clone 方法实现深拷贝
            concretePrototype.setReference((Reference) this.reference.clone());
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
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

        //引用数据类型为引用传递
        System.out.println(prototype.getReference() == clonePrototype.getReference()); //false
    }
}




