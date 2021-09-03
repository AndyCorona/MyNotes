package com.design_pattern.www.Prototype.Version4;

import java.io.*;

/**
 * 原型对象的所有引用数据类型变量都必须实现 Serializable 接口
 */
class Reference implements Serializable {
}


class ConcretePrototype implements Serializable {

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
     * 通过序列化与反序列化实现深拷贝
     * 优点：可以解决套娃式的深拷贝问题
     *
     * @return Object 对象
     */
    @Override
    public ConcretePrototype clone() {
        ConcretePrototype concretePrototype = null;
        ByteArrayOutputStream bos = null;
        ObjectOutputStream oos = null;
        ObjectInputStream ois = null;
        ByteArrayInputStream bis = null;
        try {
            //序列化，将对象序列化为字节流
            bos = new ByteArrayOutputStream();
            oos = new ObjectOutputStream(bos);
            oos.writeObject(this);
            //反序列化，字节流反序列化为对象副本
            bis = new ByteArrayInputStream(bos.toByteArray());
            ois = new ObjectInputStream(bis);
            concretePrototype = (ConcretePrototype) ois.readObject();
        } catch (IOException e1) {
            e1.printStackTrace();
        } catch (ClassNotFoundException e2) {
            e2.printStackTrace();
        } finally {
            try {
                bos.close();
                bis.close();
                ois.close();
                oos.close();
            } catch (Exception e3) {
                e3.printStackTrace();
            }
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

        //基本数据类型为值传递
        clonePrototype.setField(2);
        System.out.println(prototype.getField() == clonePrototype.getField()); //false

        //引用数据类型为引用传递
        System.out.println(prototype.getReference() == clonePrototype.getReference()); //false
    }
}




