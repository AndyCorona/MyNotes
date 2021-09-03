package com.design_pattern.www.State;

/**
 * 状态接口，聚合上下文，其子类调用上下文的方法改变状态
 */
abstract class State {
    protected Context context;

    public abstract void methodA();

    public abstract void methodB();

    public State(Context context) {
        this.context = context;
    }
}

/**
 * 具体状态，表示各个不同且不可相互替换的状态
 */
class ConcreteStateA extends State {

    public ConcreteStateA(Context context) {
        super(context);
    }

    @Override
    public void methodA() {
        System.out.println("状态A完成功能A，变为状态B");
        //在内部修改状态
        context.changeState(new ConcreteStateB(context));
    }

    @Override
    public void methodB() {
        System.out.println("状态A完成功能B");
    }

}

class ConcreteStateB extends State {
    public ConcreteStateB(Context context) {
        super(context);
    }

    @Override
    public void methodA() {
        System.out.println("状态B完成功能A");
    }

    @Override
    public void methodB() {
        System.out.println("状态B完成功能B，变成状态A");
        context.changeState(new ConcreteStateA(context));
    }
}

/**
 * 上下文，通过聚合状态接口而持有具体的状态对象
 */
class Context {
    private State state;

    public Context() {
        //状态A为初始状态
        this.state = new ConcreteStateA(this);
    }

    public void changeState(State state) {
        this.state = state;

    }

    public State getState() {
        return this.state;
    }
}


class Client {
    public static void main(String[] args) {
        //创建上下文对象
        Context context = new Context();
        //客户端调用方法改变状态
        context.getState().methodA();
        context.getState().methodA();
        context.getState().methodB();
    }
}