package com.design_pattern.www.Observer;

import java.util.ArrayList;
import java.util.List;

/**
 * 发布者或被观察者。可以注册和删除观察者，通知所有已注册的观察者
 */
class Subject {
    private List<Observer> observers = new ArrayList<>();

    public void attach(Observer observer) {
        observers.add(observer);
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    //通知所有观察者
    protected void notifyObserver() {
        for (Observer observer : observers) {
            observer.update(this);
        }
    }
}

/**
 * 具体的发布者。当自身改变时，通知所有观察者
 */
class ConcreteSubject extends Subject {
    private String subjectContent;

    public String getSubjectContent() {
        return subjectContent;
    }

    //发布者自身改变
    public void setSubjectContent(String subjectState) {
        this.subjectContent = subjectState;
        //通知所有观察者
        notifyObserver();
    }
}

/**
 * 观察者接口。传入发布者进行更新
 */
interface Observer {
    void update(Subject subject);
}

/**
 * 具体的观察者。
 */
class ConcreteObserver implements Observer {
    @Override
    public void update(Subject subject) {
        //更新后的被观察者内容
        String str = ((ConcreteSubject) subject).getSubjectContent();
        System.out.println("已更新，收到" + str);
    }
}

class Client {
    public static void main(String[] args) {
        //创建发布者
        ConcreteSubject subject = new ConcreteSubject();

        //创建观察者
        Observer observer1 = new ConcreteObserver();
        Observer observer2 = new ConcreteObserver();

        //注册观察者
        subject.attach(observer1);
        subject.attach(observer2);

        //发布者发布新内容，观察者进行更新
        subject.setSubjectContent("第一期内容");

        //发布者发布新内容，观察者进行更新
        subject.setSubjectContent("第二期内容");


    }
}