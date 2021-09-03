package com.design_pattern.www.Interpreter;

import jdk.nashorn.internal.runtime.regexp.joni.exception.SyntaxException;


/**
 * 抽象表达式。定义了语法树节点的共同接口
 */
abstract class AbstractionExpression {

    public abstract void interpreter(Context context);
}

/**
 * 终结符表达式。类似组合模式中的叶子对象。
 * 在抽象语法树的叶子节点上。
 */
class TerminalExpression extends AbstractionExpression {

    @Override
    public void interpreter(Context context) {
        if (!check(context)) {
            throw new SyntaxException("语法错误");
        }
    }

    //定义语法规则，start 代表程序开始，end 代表程序结束。
    public boolean check(Context context) {
        if (context.getStr()[0] != "start")
            return false;
        if (context.getStr()[2] != "end")
            return false;
        return true;
    }
}

/**
 * 非终结符表达式。在抽象语法树的非叶子节点上。
 */
class NonterminalExpression extends AbstractionExpression {

    //根据 start 和 end 之间的中文数字，返回对应的阿拉伯数字。
    @Override
    public void interpreter(Context context) {
        String str = context.getStr()[1];
        switch (str) {
            case "一":
                System.out.println(1);
                break;
            case "二":
                System.out.println(2);
                break;
            case "三":
                System.out.println(3);
                break;
            case "四":
                System.out.println(4);
                break;
            case "五":
                System.out.println(5);
                break;
        }
    }
}

/**
 * 上下文对象。保存解释器解析语法时需要的数据。
 */
class Context {
    private String[] str;

    public String[] getStr() {
        return str;
    }

    public void setStr(String[] str) {
        this.str = str;
    }

}

class Client {
    public static void main(String[] args) {
        //创建上下文对象
        Context context = new Context();

        //传入待解释的表达式
        context.setStr(new String[]{"start", "二", "end"});

        AbstractionExpression terminalExpression = new TerminalExpression();
        AbstractionExpression nonterminalExpression = new NonterminalExpression();

        //通过终结符表达式和非终结符表达式对表达式进行解释
        terminalExpression.interpreter(context);
        nonterminalExpression.interpreter(context);
    }
}