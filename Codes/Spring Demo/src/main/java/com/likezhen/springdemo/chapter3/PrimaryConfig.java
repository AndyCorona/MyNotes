package com.likezhen.springdemo.chapter3;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

@Configuration
public class PrimaryConfig {
    @Primary
    @Bean
    public Development getDevelopment() {
        return new Development();
    }
}
