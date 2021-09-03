# 第八章 使用 Maven 进行测试

### 8.1 maven-surefire-plugin

Maven 本身不是一个单元测试框架，Maven 只是在执行到 default 生命周期的 test 阶段时，通过插件来执行 JUnit 或 TestNG 的测试用例，即 maven-surefire-plugin 插件的 test 目标与 test 阶段绑定。
在默认情况下， maven-surefire-plugin 插件的 test 目标会自动执行测试代码路径下（默认为 src/test/java/）下所有符合一组命名模式的测试类（可以修改）。这组模式为：
1）\*\*/Test\*.java        任何子目录下所有以 Test 开头的 Java 类
2）\*\*/\*Test.java        任何子目录下所有以 Test 结尾的 Java 类
3）\*\*/\*TestCase.java        任何子目录下所有以 TestCase 结尾的 Java 类

### 8.2 跳过测试

命令行输入插件参数skipTests=true 或在  maven-surefire-plugin 的 pom 文件配置 configuration 标签即可跳过执行测试代码。插件参数 maven.test.skip=true 跳过编译测试代码和执行测试代码
```mvn install -DskipTests=true```

```xml
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-surefire-plugin</artifactId>
    <version>2.5</version>
    <configuration>
        <skipTests>true</skipTests>
    </configuration>
</plugin>
```

### 8.3 运行指定测试用例
插件参数 test=xxx 可以只运行指定测试用例

mvn test -Dtest=RandomTest,ForTest        只运行 RandomTest 和 ForTest 测试类  
mvn test -Dtest=Random\*Test        只运行以 Random开头，Test 结尾命名的测试类  

### 8.4 包含与排除测试用例

虽然不建议修改，但 maven-surefire-plugin 提供了修改命名模式的方法。
```xml
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-surefire-plugin</artifactId>
    <version>2.5</version>
    <configuration>
        <includes>
            <include>**/*Tests.java</include>
        </includes>
        <excludes>
            <exclude>**/*TempTest.java</exclude>
        </excludes>
    </configuration>
</plugin>
```
include 标签指定 Maven 会自动执行测试代码子目录下所有以 Tests 结尾的 Java 类，并用 exclude 标签排除了子目录下所有以 TempTest 结尾的 Java 类

### 8.5 测试报告

默认情况下，maven-surefire-plugin 会在项目的 target/surefire-reports 目录下生成两种错误报告，报告说明哪个测试方法失败、哪个断言失败以及具体的堆栈信息。
1）简单文本格式
2）XML 格式
通过 cobertura-maven-plugin 插件还可以查看测试覆盖率报告。

### 8.6 重用测试代码

默认情况下，测试代码不会被打包，配置 maven-jar-plugin，可以将测试代码打包。test-jar 插件目标默认绑定生命周期阶段为 package。
```xml
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-jar-plugin</artifactId>
    <version>2.2</version>
    <executions>
        <execution>
            <goals>
                <goal>test-jar</goal>
            </goals>
        </execution>
    </executions>
</plugin>
```
在其他模块便可以依赖此测试用例 jar 包，重用测试代码
```xml
<dependency>
    <groupId>xxxxxxxx</groupId>
    <artifactId>xxxxxxx</artifactId>
    <version>1.0.0-SNAPSHOT</version>
    <type>test-jar</type>
    <scope>test</scope>
</dependency>
```
主要导入测试代码的 jar 包时，类型是 test-jar 而不是 jar

























