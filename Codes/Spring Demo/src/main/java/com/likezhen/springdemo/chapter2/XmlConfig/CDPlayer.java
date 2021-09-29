package com.likezhen.springdemo.chapter2.XmlConfig;

import com.likezhen.springdemo.chapter2.Autowired.CD;

public class CDPlayer {

    private CD cd;

    public void setCd(CD cd) {
        this.cd = cd;
    }

    public void play() {
        cd.play();
    }
}
