package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Role;

import java.util.ArrayList;
import java.util.List;

public interface RoleMapper {
    public Role getRoleById(Integer id);

    public Role dynamicSql(Integer id);

    public Role dynamicSqlTrim(Integer id);

    public Role dynamicSqlChoose(Integer id);

    public ArrayList<Role> dynamicSqlForeach(List myList);

    public Role dynamicSqlBind(String roleName);

}
