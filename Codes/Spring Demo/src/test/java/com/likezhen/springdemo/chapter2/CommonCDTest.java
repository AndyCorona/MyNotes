package com.likezhen.springdemo.chapter2;

import com.likezhen.springdemo.chapter2.Autowired.CD;
import com.likezhen.springdemo.chapter2.XmlConfig.CommonCD;
import com.likezhen.springdemo.chapter3.ResourceConfig;
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
@ContextConfiguration(classes = ResourceConfig.class)
public class CommonCDTest {

    @Rule
    public final SystemOutRule log = new SystemOutRule().enableLog();

    @Autowired
    CommonCD cd;

    @Test
    public void CDShouldNotBeNull() {
        assertNotNull(cd);
    }

    @Test
    public void outputShouldBeEquals() {
        cd.play();
        assertEquals("Playing the myCD by myBand",log.getLog());
    }
}
