#ifndef USERMODEL_H
#define USERMODEL_H

#include "user.hpp"

//user表的数据操作类
class UserModel {
public:
    //User表的增加方法
    bool insert(User &user);
    
    //根据用户号码查询用户信息
    User query(int id);

    //更新用户的登陆状态信息
    bool updataState(User user);

    //重置用户登陆状态
    void resetState();

};






#endif