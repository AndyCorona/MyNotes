package com.design_pattern.www.Stragety;

/**
 * 策略接口。约束一系列具体的策略算法
 * 上下文使用此接口调用具体的策略算法
 */
interface Strategy {
    void execute();
}

/**
 * 具体的策略实现，表示不同且可相互替换的策略
 */
class ConcreteStrategyA implements Strategy {
    @Override
    public void execute() {
        System.out.println("算法A");
    }
}

class ConcreteStrategyB implements Strategy {
    @Override
    public void execute() {
        System.out.println("算法B");
    }
}

/**
 * 上下文。通过聚合策略接口而持有具体的策略实现对象，可以根据客户端传入的参数选择指定的策略
 */
class Context {
    private Strategy strategy;

    public Context(Strategy strategy) {
        this.strategy = strategy;
    }

    public void doSomething() {
        strategy.execute();
    }

    public void setStrategy(Strategy strategy) {
        this.strategy = strategy;
    }
}

class Client {
    public static void main(String[] args) {
        //创建策略对象
        Strategy strategyA = new ConcreteStrategyA();
        Strategy strategyB = new ConcreteStrategyB();
        //创建上下文对象
        Context context = new Context(strategyB);
        //根据传入的策略实现功能
        context.doSomething();

        System.out.println("更换策略中……");
        context.setStrategy(strategyA);
        context.doSomething();


    }
}

