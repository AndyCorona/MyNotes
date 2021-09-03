package com.design_pattern.www.Command;

/**
 * 命令接口。声明执行命令的方法
 */
interface Command {
    void execute();
}

/**
 * 具体命令对象。持有一个接收者。执行命令时，实际执行的是接收者的方法。
 */
class ConcreteCommand implements Command {
    private Receiver receiver;

    public ConcreteCommand(Receiver receiver) {
        this.receiver = receiver;
    }

    @Override
    public void execute() {
        receiver.action();
    }
}

/**
 * 接收者。实现具体的业务逻辑。
 */
class Receiver {
    public void action() {
        System.out.println("执行命令A");
    }
}

/**
 * 触发者。持有命令对象供客户端使用。调用命令对象的命令。
 */
class Invoker {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void runCommand() {
        command.execute();
    }
}

class Client {
    public static void main(String[] args) {

        //创建接收者
        Receiver receiver = new Receiver();

        //创建命令对象，设置接收者
        Command command = new ConcreteCommand(receiver);

        //创建触发者，设置命令对象
        Invoker invoker = new Invoker();
        invoker.setCommand(command);

        //执行触发者的方法
        invoker.runCommand();


    }
}