package com.likezhen.springdemo.chapter2;

import com.likezhen.springdemo.chapter2.Autowired.CD;
import com.likezhen.springdemo.chapter2.Autowired.CDPlayer;
import com.likezhen.springdemo.chapter2.JavaConfig.CDPlayerConfig;
import org.junit.Rule;
import org.junit.Test;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = CDPlayerConfig.class)
public class CDPlayerJavaConfigTest {

    @Rule
    public final SystemOutRule consoleLog = new SystemOutRule().enableLog();

    @Autowired
    private CD cd;

    @Autowired
    private CDPlayer cdPlayer;

    @Test
    public void cdShouldNotBeNull() {
        assertNotNull(cd);
    }

    @Test
    public void outPutShouldBeEqual() throws Exception {
        cdPlayer.play();
        assertEquals("Playing the myCD by band", consoleLog.getLog());
    }
}
