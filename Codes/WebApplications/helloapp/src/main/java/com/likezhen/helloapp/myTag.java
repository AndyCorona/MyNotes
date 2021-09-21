package com.likezhen.helloapp;

import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

/**
 * 自定义标签类
 */
public class myTag extends TagSupport {
    //标签的 username 属性
    private String username = null;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    @Override
    public int doEndTag() {
        JspWriter out = pageContext.getOut();

        try {
            if (username.equals("root")) {
                out.println("你好，管理员");
            } else {
                out.println("你好，" + username);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            return myTag.EVAL_PAGE;
        }
    }
}
