package com.likezhen.springdemo.chapter4;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;

import java.io.Serializable;

//@Aspect
public class MyLog {

//    @Pointcut("execution(* com.likezhen.springdemo.chapter4.MyTask.run())")
//    public void markRun() {}
//
//    @Before("markRun()")
    public void printBefore() {
        System.out.println("开始记录......");
    }
//
//    @After("execution(* com.likezhen.springdemo.chapter4.MyTask.stop(..))")
    public void printAfter() {
        System.out.println("停止记录......");
    }
//
//    @AfterReturning("markRun()")
    public void printReturning() {
        System.out.println("返回，继续记录......");
    }
//
//    @AfterThrowing("markRun()")
    public void printThrowing() {
        System.out.println("报错，停止记录......");
    }

//
//    @Pointcut("execution(* com.likezhen.springdemo.chapter4.MyTask.run(..))")
//    public void isRun() {
//    }
//
//    @Around("isRun()")
//    public void logPrint(ProceedingJoinPoint jp) {
//        try {
//            System.out.println("开始记录......");
//            jp.proceed();
//            System.out.println("返回，继续记录......");
//        } catch (Throwable e) {
//            System.out.println("报错，停止记录......");
//        }
//    }

//
//    @Pointcut("execution(* com.likezhen.springdemo.chapter4.MyTask.setTask(int)) && args(num)")
//    public void setNumber(int num) { }
//
//    @Before("setNumber(num)")
//    public void doBeforeSet(int num){
//        System.out.println(num);
//    }

//    @DeclareParents(value = "com.likezhen.springdemo.chapter4.MyTask+", defaultImpl = commonAddIn.class)
//    public addIn addIn;
}
