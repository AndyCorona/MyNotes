package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Country;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface CountryMapper {
    /**
     * 查询所有数据
     *
     * @return Country 类型的集合
     */
    public List<Country> selectAll();

    /**
     * 插入一个数据
     *
     * @param country
     */
    public void insert(Country country);

    /**
     * 更改一个数据
     *
     * @param country
     */
    public void update(Country country);

    /**
     * 删除一个数据
     *
     * @param id
     */
    public void delete(Integer id);

    /**
     * 插入一个数据，获取自增主键值
     *
     * @param country
     */
    public void insertGetId(Country country);


    /**
     * 通过 id 查询数据
     *
     * @param id
     * @return
     */
    public Country selectOneById(Integer id);

    /**
     * 传入多个指定类型参数
     *
     * @param id
     * @param countryCode
     * @return
     */
    public Country selectOneByMultiParams(@Param("id") Integer id, @Param("countryCode") String countryCode);

    public Country selectOneByMultiParams(Country country);

}
