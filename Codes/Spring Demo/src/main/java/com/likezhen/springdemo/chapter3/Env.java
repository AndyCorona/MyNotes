package com.likezhen.springdemo.chapter3;

import org.springframework.beans.factory.annotation.Qualifier;

public class Env {
    private Development dev = null;
    private Production prod = null;

    //自定义限定符名
    @Qualifier("dev")
    public void setDev(Development dev) {
        this.dev = dev;
    }

    //默认限定符名
    @Qualifier("production")
    public void setProd(Production prod) {
        this.prod = prod;
    }
}
