package com.design_pattern.www.Mediator;

/**
 * 同事抽象类。实现具体同事类的公共功能。
 * 比如每个同事类都应该持有中介者
 */
abstract class Colleague {
    private Mediator mediator;

    public Colleague(Mediator mediator) {
        this.mediator = mediator;
    }

    public Mediator getMediator() {
        return mediator;
    }
}

/**
 * 具体同事类A。实现自己的业务。
 * 在需要与其他同事通信时，不直接找其他同事而是通知中介者，中介者负责和其他同事通信。
 */
class ConcreteColleagueA extends Colleague {
    public ConcreteColleagueA(Mediator mediator) {
        super(mediator);
    }

    //完成功能A后，通知中介者调用同事B的功能B
    public void operationA() {
        System.out.println("操作A完成，需要调用操作B");
        this.getMediator().change(this);
    }
}

class ConcreteColleagueB extends Colleague {
    public ConcreteColleagueB(Mediator mediator) {
        super(mediator);
    }

    public void operationB() {
        System.out.println("操作B完成");
        this.getMediator().change(this);
    }
}

/**
 * 中介者接口。提供公共的通信方法。
 *
 */
interface Mediator {
    void change(Colleague colleague);
}

/**
 * 具体的中介者。持有所有具体的同事类，并且负责协调同事之间的交互关系。
 */
class ConcreteMediator implements Mediator {

    private ConcreteColleagueA colleagueA;
    private ConcreteColleagueB colleagueB;

    public void setColleagueA(ConcreteColleagueA colleagueA) {
        this.colleagueA = colleagueA;
    }

    public void setColleagueB(ConcreteColleagueB colleagueB) {
        this.colleagueB = colleagueB;
    }

    @Override
    public void change(Colleague colleague) {
        if (colleague == colleagueA) {
            colleagueB.operationB();
        }
    }
}


class Client {
    public static void main(String[] args) {
        //创建中介者
        ConcreteMediator mediator = new ConcreteMediator();

        //创建同事类
        ConcreteColleagueA colleagueA = new ConcreteColleagueA(mediator);
        ConcreteColleagueB colleagueB = new ConcreteColleagueB(mediator);

        //让中介者知道所有同事类
        mediator.setColleagueA(colleagueA);
        mediator.setColleagueB(colleagueB);

        //同事类A完成方法A后，通知中介者，中介者调用同事B的方法B
        colleagueA.operationA();

    }
}