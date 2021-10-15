package com.likezhen.springdemo.chapter4;

import org.junit.Rule;
import org.junit.Test;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import static org.junit.jupiter.api.Assertions.assertEquals;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = JavaConfigCtp4.class)
public class TaskTest {

    @Rule
    public final SystemOutRule log = new SystemOutRule().enableLog();

    @Autowired
    private MyTask task;

    @Test
    public void testOutput() {
        task.run();
        assertEquals("开始记录......\r\n返回，继续记录......\r\n", log.getLog());
    }

    @Test
    public void testAround() {
        task.run();
    }
    @Test
    public void testArgs(){
        task.setTask(5);
    }

    @Test
    public void testAdd() {
        addIn obj = (addIn) task;
        obj.add();
    }
}
