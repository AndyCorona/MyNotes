package com.design_pattern.www.relation;

public class Composition {
}

class Hand {
}

class Body {
    Hand hand;

    public Body() {
        this.hand = new Hand(); //构造方法中直接实例化被组合类
    }
}