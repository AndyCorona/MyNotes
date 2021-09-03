# 第三章 简单使用 Maven

### 3.1 pom 文件

Maven 项目的核心是 pom 文件。POM(项目对象模型)定义了项目的基本信息，用于描述项目如何构建，声明项目依赖。一个 Java 项目可以是一个 Maven 项目，项目中的一个模块也可以是 Maven 项目

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 			    http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.likezhen.bookstore</groupId>
    <artifactId>hello-world</artifactId>
    <version>1.0-SNAPSHOT</version>
    <name>Maven First Project</name>
</project>
```

第一行为 xml 文档声明
project 为 pom 文件根元素
modelVersion 指定当前 POM 模型版本，对于 Maven2 和 Maven 3 来说，只能为 4.0.0
groupId、artifactId 和 version 为必填元素，这三个元素定义了一个项目在 Maven 世界中的坐标

groupId 定义了当前项目属于哪个组。组一般指创建项目的组织或公司
artifactId 定义了当前 Maven 项目在组中的唯一 ID
version 定义了当前 Maven 项目的版本
name 定义了更友好的项目名称

### 3.2 主代码

项目主代码会被打包到库中（如 jar 包），测试代码不会被打包。Maven 约定项目主代码位于 src/main/java 目录下。在该目录下新建形式为 groupId.artifactId 的包名，进行编码
在根目录下运行命令 mvn clean compile 执行项目的清理和编译任务

### 3.3 测试代码

Maven 约定项目测试代码位于 src/test/java 目录下。在根目录下执行命令 mvn clean test 执行项目的清理和测试任务

### 3.4 打包和运行

项目测试编译之后，下一步就是打包。默认打包类型为 jar。执行命令 mvn clean package 进行打包
执行 mvn clean install 将项目输出的 jar 包安装到 Maven 本地仓库中，供其他项目引用使用

默认打包生成的 jar 包是不能运行的，因为该 jar 包里 META-INF 目录下 MAINFEST.MF 文件的Main-Class 属性没有属性值。若 Main-Class 属性值为带有 main 方法的全类名，在命令行可通过 java -jar xxx.jar 执行该 jar 包。

借助 maven-shade-plugin 插件，在其 xml 文件里配置 mainClass 标签内容，即可执行 jar 包

### 3.5 使用 Archetype 生成项目骨架

在根目录下放置 pom.xml 文件，在 src/main/java 中放置主代码，在 src/test/java 中放置测试代码，这些固定不变的基本目录结构和 pom.xml 文件称为项目的骨架。Maven 提供了 Archetype 用于快速搭建项目骨架。

在 Maven3 中运行 mvn archetype:generate 命令，选择需要的 Archetype，输入项目的 groupId、artifactId、version 以及包名 package 后即可创建一个项目的骨架。

### 3.6 配置优先级
局部配置优先于全局配置。pom.xml> user settings > global settings。如果这些文件同时存在，在应用配置时，会合并它们的内容，如果有重复的配置，优先级高的配置会覆盖优先级低的。



