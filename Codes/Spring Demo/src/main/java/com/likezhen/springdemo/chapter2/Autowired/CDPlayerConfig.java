package com.likezhen.springdemo.chapter2.Autowired;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan


//扫描 chapter1 包及其子包
//@ComponentScan("com.likezhen.springdemo.chapter1")
////扫描 chapter1 包及其子包，chapter2 包及其子包
//@ComponentScan(basePackages = {"com.likezhen.springdemo.chapter1","com.likezhen.springdemo.chapter2"})
////扫描 CD 类所在的包及其子包，C 类所在的包及其子包
//@ComponentScan(basePackageClasses = {CD.class, C.class})
public class CDPlayerConfig {
}
