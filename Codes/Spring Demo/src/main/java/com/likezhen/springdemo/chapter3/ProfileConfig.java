package com.likezhen.springdemo.chapter3;


import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

@Configuration
@Profile("myProfile")
public class ProfileConfig {

    @Bean
    @Profile("dev")
    public Development getDevelopment() {
        return new Development();
    }

    @Bean
    @Profile("prod")
    public Production getProduction() {
        return new Production();
    }

}
