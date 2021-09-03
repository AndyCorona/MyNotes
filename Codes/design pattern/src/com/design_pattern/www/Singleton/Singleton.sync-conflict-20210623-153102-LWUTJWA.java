package com.design_pattern.www.singleton;


/**
 * 单例模式（懒汉式&线程不安全）
 */
//public class Singleton {
//    //缓存实例
//    private static Singleton singleton;
//
//    //私有化构造器
//    private Singleton() {
//    }
//
//    //提供获取实例的唯一方法
//    public static Singleton getInstance() {
//        if (singleton == null) {
//            return singleton = new Singleton();
//        }
//        return singleton;
//    }
//}


/**
 * 单例模式（懒汉式&线程安全）
 * 通过同步方法解决线程安全问题
 */
//public class Singleton {
//    private static Singleton singleton;
//
//    private Singleton() {
//    }
//
//    public static synchronized Singleton getInstance() {
//        if (singleton == null) {
//            return singleton = new Singleton();
//        }
//        return singleton;
//    }
//}

/**
 * 单例模式（懒汉式&线程安全）
 * 通过同步代码块解决线程安全问题
 */
//public class Singleton {
//    private static Singleton singleton;
//
//    private Singleton() {
//    }
//
//    public static Singleton getInstance() {
//        synchronized (Singleton.class) {
//            if (singleton == null) {
//                return singleton = new Singleton();
//            }
//            return singleton;
//        }
//
//    }
//}

/**
 * 单例模式（懒汉式$线程安全）
 * 通过双重检查解决线程安全问题
 */
//public class Singleton {
//    //添加 volatile 关键字
//    private volatile static Singleton singleton;
//
//    private Singleton() {
//    }
//
//    public static Singleton getInstance() {
//        //先检查实例是否存在，不存在才进入同步代码块
//        if (singleton == null) {
//            synchronized (Singleton.class) {
//                /*
//                再次确认，第一个进来的线程可以创建实例
//                其他的线程无法再创建实例
//                 */
//                if (singleton == null) {
//                    singleton = new Singleton();
//                }
//                return singleton;
//            }
//        }
//        return singleton;
//    }
//}


/**
 * 单例模式（懒汉式&线程安全）
 *通过静态内部类解决线程安全问题
 */
//public class Singleton {
//
//    private Singleton() {
//    }
//
//    //调用此方法时，才加载静态内部类
//    public static Singleton getInstance() {
//        return SingletonHolder.singleton;
//    }
//
//    private static class SingletonHolder {
//        //静态初始化器，由 JVM 保证线程安全
//        private static Singleton singleton = new Singleton();
//    }
//}


//单例模式（饿汉式）
//public class Singleton {
//    //通过静态常量或静态代码块创建唯一实例
//    private static Singleton singleton = new Singleton();
//    //私有化构造器
//    private Singleton() {
//    }
//    //提供获取实例的唯一方法
//    public static Singleton getInstance() {
//        return singleton;
//    }
//}


//单例模式（枚举类&线程安全）
//public enum Singleton {
//    //枚举类的一个元素就代表一个实例
//    SINGLETON;
//}


//class Test {
//    public static void main(String[] args) {
//        Singleton singleton = Singleton.getInstance();
//        Singleton singleton1 = Singleton.getInstance();
//        if (singleton == singleton1) {
//            System.out.println("单例模式成功");
//        } else {
//            System.out.println("单例模式失败");
//        }
//    }
//}