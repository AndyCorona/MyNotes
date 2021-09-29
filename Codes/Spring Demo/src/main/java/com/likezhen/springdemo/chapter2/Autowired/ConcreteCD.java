package com.likezhen.springdemo.chapter2.Autowired;

import org.springframework.stereotype.Component;

//bean ID 默认为类名的首字母小写形式
@Component("firstBean")
public class ConcreteCD implements CD {

    private String title = "myCD";
    private String artist = "band";

    @Override
    public void play() {
        System.out.print("Playing the " + title + " by " + artist);
    }
}
