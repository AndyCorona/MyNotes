package com.design_pattern.www.Composite;

import java.util.ArrayList;
import java.util.List;

/**
 *抽象的组件类或组件接口。供客户端使用
 * 是整体和部分的父类，使它们具有一致性
 */
abstract class Component {
    public abstract void operation();

    //定义一些默认方法而不是抽象方法，因为叶子节点不支持这些方法
    public void add(Component component) {
        throw new UnsupportedOperationException("叶子节点不支持此功能");
    }

    public void remove(Component component) {
        throw new UnsupportedOperationException("叶子节点不支持此功能");
    }
}

/**
 *叶子节点类。定义行为，不再包含其他子节点。
 * 是一个部分
 */
class Leaf extends Component {
    @Override
    public void operation() {
        System.out.println("子节点的功能");
    }
}

/**
 *组合类。通常会储存其他子节点（包括叶子节点）
 * 是一个整体
 */
class Composite extends Component {
    private List<Component> list = null;

    //使用组合类的功能时，就是遍历其所有子节点并执行所有子节点的功能
    @Override
    public void operation() {
        if (list != null) {
            for (Component component : list) {
                component.operation();
            }
        }
    }

    @Override
    public void add(Component component) {
        if (list == null) {
            list = new ArrayList<Component>();
        }
        list.add(component);
    }

    @Override
    public void remove(Component component) {
        if (list != null) {
            list.remove(component);
        }
    }
}

class Client {
    public static void main(String[] args) {
        //创建叶子节点
        Component leaf1 = new Leaf();
        Component leaf2 = new Leaf();
        //创建组合
        Component composite = new Composite();
        composite.add(leaf1);
        //进行操作
        composite.add(leaf2);
        composite.operation();
    }

}