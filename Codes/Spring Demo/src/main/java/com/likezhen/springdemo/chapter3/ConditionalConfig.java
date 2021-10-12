package com.likezhen.springdemo.chapter3;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Conditional;
import org.springframework.context.annotation.Configuration;

@Configuration
public class ConditionalConfig {
    @Conditional(MyCondition.class)
    @Bean
    public Development getDevelopment() {
        return new Development();
    }
}
