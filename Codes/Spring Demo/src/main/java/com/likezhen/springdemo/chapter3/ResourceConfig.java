package com.likezhen.springdemo.chapter3;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.ImportResource;
import org.springframework.context.annotation.PropertySource;

@Configuration
@PropertySource("classpath:ctp3/app.properties")
@ImportResource("classpath:ctp2/ResourceConfig.xml")
public class ResourceConfig {

    //使用 Environment 对象读取外部文件属性
//    @Autowired
//    Environment env;

//    @Bean
//    public CommonCD getCommonCD() {
//        return new CommonCD(env.getProperty("common.title"), env.getProperty("common.artist"));
//    }
}
