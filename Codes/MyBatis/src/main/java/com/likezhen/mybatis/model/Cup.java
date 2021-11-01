package com.likezhen.mybatis.model;

public class Cup {
    private Integer id;

    private Integer size;

    private String color;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getSize() {
        return size;
    }

    public void setSize(Integer size) {
        this.size = size;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Cup{" +
                "id=" + id +
                ", size=" + size +
                ", color='" + color + '\'' +
                '}';
    }
}