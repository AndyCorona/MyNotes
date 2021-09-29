package com.likezhen.springdemo.chapter2.Autowired;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class CDPlayer {

    private CD cd;

    @Autowired
    public CDPlayer(CD cd) {
        this.cd = cd;
    }

    public void play() {
        cd.play();
    }
}
