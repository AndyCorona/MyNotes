package com.likezhen.springdemo.chapter2.JavaConfig;

import com.likezhen.springdemo.chapter2.Autowired.CD;
import com.likezhen.springdemo.chapter2.Autowired.CDPlayer;
import com.likezhen.springdemo.chapter2.Autowired.ConcreteCD;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class CDPlayerConfig {

    @Bean(name = "firstBean")
    public CD getCD() {
        return new ConcreteCD();
    }

    @Bean
    public CDPlayer cdPlayer(CD cd) {
        return new CDPlayer(cd);
    }
}
