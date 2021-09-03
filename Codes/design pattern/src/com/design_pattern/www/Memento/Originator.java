package com.design_pattern.www.Memento;

/**
 * 原发器。包含一个备忘录对象内部类，用来保存或恢复原发器某个时刻的状态
 * 原发器不对外暴露状态
 */
class Originator {
    private String state;

    public Memento save() {
        return new MementoImp(state);
    }

    public void restore(Memento memento) {
        MementoImp mementoImp = (MementoImp) memento;
        this.state = mementoImp.getState();
    }

    public void init() {
        this.state = "初始状态";
    }

    public void run() {
        this.state = "运行状态";
    }

    public void printState() {
        System.out.println(this.state);
    }

    //备忘录内部类。保存原发器的内部状态。原发器外部不能访问备忘录对象。
    private class MementoImp implements Memento {
        private String state;

        private MementoImp(String state) {
            this.state = state;
        }

        private String getState() {
            return this.state;
        }
    }
}

/**
 * 备忘录窄接口。供备忘录管理者使用
 */
interface Memento {
}

/**
 * 备忘录管理者。保存多个不同的备忘录对象
 * 但不能操作备忘录对象的内容
 */
class CareTaker {
    private Memento history;

    public void save(Memento memento) {
        this.history = memento;
    }

    public Memento undo() {
        return this.history;
    }
}

class Client {
    public static void main(String[] args) {
        //创建原发器
        Originator originator = new Originator();
        //初始化，此时状态为初始状态
        originator.init();
        originator.printState();

        //创建备忘录管理者，将原发器状态保存到备忘录里，交给管理者
        CareTaker careTaker = new CareTaker();
        careTaker.save(originator.save());

        //原发器状态改变
        originator.run();
        originator.printState();

        //通过管理者恢复原发器之前保存的初始状态
        originator.restore(careTaker.undo());

        originator.printState();


    }
}
