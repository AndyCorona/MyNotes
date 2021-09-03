# 第二章 安装 Maven

### 2.1 安装并配置 Maven

```echo %JAVA_HOME%``` 检测环境变量 JAVA_HOME 是否指向正确的 JDK 目录
```java -version``` 检测 Java 是否安装

官网下载 Maven 压缩包，解压之后
类似 JAVA_HOME 的配置，在 Maven 中 /bin 的上一层目录指定为 M2_HOME
给 Path 变量添加 %M2_HOME%\bin 
```mvn -v``` 检测 Maven 是否安装

### 2.2 安装目录分析

bin 目录下包含了 mvn 运行脚本。
	mvn 是 shell 脚本，mvn.cmd 是 Windows 的脚本，命令行输入任何 mvn 命令时，就是调用这两个脚本
	mvnDebug 和 mvnDebug.cmd 在 Maven 运行时开启 debug 
	mvn.conf 是 classworlds 的配置文件
boot
	plexus-classworlds-2.6.0.jar 是一个类加载器框架，相对于默认的 java 类加载器，提供了更丰富的语法。Maven 使用该框架加载自己的类库。
conf
	修改 settings.xml 能够全局定制 Maven 的行为
    一般将该文件复制到 ~/.m2 下，在用户范围定制 Maven 的行为
lib
	包含所有 Maven 运行时需要的 java 类库和第三方依赖
LICENSE 记录了 Maven 使用的软件许可证
NOTICE 记录了 Maven 包含的第三方软件
README.txt 关于 Maven 的简要介绍

### 2.3 ~/.m2

~ 表示用户家目录。默认情况下，Maven 本地仓库存放在这里

### 2.4 设置 HTTP 代理

编辑 settings.xml 文件里的 proxies 标签



