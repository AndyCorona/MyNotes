package com.likezhen.springdemo.chapter3;

import com.likezhen.springdemo.chapter2.XmlConfig.CommonCD;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.ImportResource;
import org.springframework.context.annotation.PropertySource;
import org.springframework.core.env.Environment;
@Configuration
@PropertySource("classpath:app.properties")
@ImportResource("classpath:ResourceConfig.xml")
public class ResourceConfig {

    //使用 Environment 对象读取外部文件属性
//    @Autowired
//    Environment env;

//    @Bean
//    public CommonCD getCommonCD() {
//        return new CommonCD(env.getProperty("common.title"), env.getProperty("common.artist"));
//    }
}
