package com.design_pattern.www.relation;

public class Dependency {


}


class A {
}

class B {
}

class C {
}

class D {
}

class E {
    private A a; //成员变量

    public void setter(B b) {
    } //方法形参

    public C method1() {
        return null;
    } //返回值

    public void method2() {
        D d = new D(); //局部变量
    }
}