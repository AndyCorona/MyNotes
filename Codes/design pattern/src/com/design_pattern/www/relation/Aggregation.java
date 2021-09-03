package com.design_pattern.www.relation;


public class Aggregation {
}


class Engine {
}

class Car {
    private Engine engine;

    public Car(Engine engine) { //构造方法中
        this.engine = engine;
    }

    public void setter(Engine engine) { //setter 方法中
        this.engine = engine;
    }
}

