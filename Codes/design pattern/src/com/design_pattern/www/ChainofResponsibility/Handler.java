package com.design_pattern.www.ChainofResponsibility;

/**
 * 处理者。定义所有具体处理者的通用接口。
 * 包括设置链上下一个处理者的方法和处理抽象方法。
 */
abstract class Handler {
    protected Handler handler;

    public abstract void setNext(Handler handler);

    public abstract void handle(int money);
}

/**
 * 具体的处理者。可以设置下一个处理者
 */
class ConcreteHandleA extends Handler {
    @Override
    public void setNext(Handler handler) {
        this.handler = handler;
    }

    @Override
    public void handle(int money) {
        if (money <= 500) {
            //属于自己的职责范围可以处理
            System.out.println("处理完毕");
        } else {
            //不属于自己的职责范围，寻找下一个处理者，调用其处理方法
            if (this.handler != null) {
                System.out.println("无法处理，提交给上级处理");
                this.handler.handle(money);
            }
        }
    }
}

class ConcreteHandleB extends Handler {
    @Override
    public void setNext(Handler handler) {
        this.handler = handler;
    }

    @Override
    public void handle(int money) {
        if (money > 500) {
            System.out.println("处理完毕");
        } else {
            if (this.handler != null) {
                this.handler.handle(money);
            }
        }
    }
}

class Client {
    public static void main(String[] args) {
        //创建具体处理者
        Handler handlerA= new ConcreteHandleA();
        Handler handlerB = new ConcreteHandleB();

        //组装职责链
        handlerA.setNext(handlerB);

        //进行处理
        handlerA.handle(1000);
    }
}