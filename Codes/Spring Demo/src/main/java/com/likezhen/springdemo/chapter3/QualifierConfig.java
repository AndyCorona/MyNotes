package com.likezhen.springdemo.chapter3;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class QualifierConfig {


    @Qualifier("dev")
    @Bean
    public Development development() {
        return new Development();
    }

    @Bean
    public Production production() {
        return new Production();
    }

}
