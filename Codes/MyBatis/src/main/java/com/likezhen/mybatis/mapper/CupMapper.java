package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Cup;
import java.util.List;

public interface CupMapper {
    int deleteByPrimaryKey(Integer id);

    int insert(Cup record);

    Cup selectByPrimaryKey(Integer id);

    List<Cup> selectAll();

    int updateByPrimaryKey(Cup record);
}