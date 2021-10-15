package com.likezhen.springdemo.chapter4;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

@Configuration
@EnableAspectJAutoProxy
public class JavaConfigCtp4 {

    @Bean
    public MyLog getLog() {
        return new MyLog();
    }

    @Bean
    public MyTask getTask(){
        return new MyTask();
    }
}
