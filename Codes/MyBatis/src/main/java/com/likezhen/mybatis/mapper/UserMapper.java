package com.likezhen.mybatis.mapper;

import com.likezhen.mybatis.model.Role;
import com.likezhen.mybatis.model.User;

public interface UserMapper {

    public User getUserById(Integer id);

    public Role getRoleById(Integer id);

    public User getUserAndRoleById(Integer id);
}
