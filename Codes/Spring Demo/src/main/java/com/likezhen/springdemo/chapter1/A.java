package com.likezhen.springdemo.chapter1;

public class A {

    private C c;

//    public A() {
//        c = new C();
//    }


    public A(C c) {
        this.c = c;
    }

    public void use() {
        c.method();
    }
}
