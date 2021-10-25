package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Country;

import java.util.List;

public interface CountryMapper {
    public List<Country> selectAll();

    public Country selectOne(Integer id);
}
