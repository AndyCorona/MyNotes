package com.design_pattern.www.Iterator;

/**
 * 迭代器接口。定义遍历集合的常用方法。
 * 如获取第一个、当前和下一个元素，判断是否到集合末尾等方法
 */
interface Iterator {

    void first();

    void next();

    boolean isDone();

    Object currentElement();
}

/**
 * 具体的迭代器类。不同的集合有不同的迭代器。
 */
class ConcreteIterator implements Iterator {
    //将数组聚合到数组迭代器内
    private ConcreteAggregate aggregate;
    private int index = -1;

    public ConcreteIterator(ConcreteAggregate aggregate) {
        this.aggregate = aggregate;
    }

    @Override
    public void first() {
        index = 0;
    }

    @Override
    public void next() {
        if (index < aggregate.size()) {
            index++;
        }
    }

    @Override
    public boolean isDone() {
        return index == aggregate.size();
    }

    @Override
    public Object currentElement() {
        return this.aggregate.get(index);
    }
}

/**
 * 聚合抽象类。定义创建迭代器的接口。
 */
abstract class Aggregate {
    public abstract Iterator createIterator();
}

/**
 * 具体的聚合对象。
 */
class ConcreteAggregate extends Aggregate {
    private int[] array;

    public ConcreteAggregate(int[] array) {
        this.array = array;
    }

    @Override
    public Iterator createIterator() {
        return new ConcreteIterator(this);
    }

    public Object get(int index) {
        Object obj = null;
        if (index < array.length) {
            obj = array[index];
        }
        return obj;
    }

    public int size() {
        return this.array.length;
    }
}

class Client {
    public static void main(String[] args) {
        //创建集合对象
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        ConcreteAggregate aggregate = new ConcreteAggregate(array);

        //通过集合对象创建迭代器对象
        Iterator iterator = aggregate.createIterator();
        iterator.first();
        while (!iterator.isDone()) {
            //遍历集合中的每一个元素
            Object obj = iterator.currentElement();
            System.out.println(obj);
            iterator.next();
        }
    }
}