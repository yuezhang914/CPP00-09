#include "Zombie.hpp"
#include <iostream>

/*
** 默认构造函数
** 作用：让 _name 先变成空字符串
** 说明：
** - 这样每个 Zombie 都能被 new Zombie[N] 先创建出来
*/
Zombie::Zombie() : _name("")
{
}

/*
** 析构函数
** 作用：打印销毁信息
** 说明：
** - 即使你 delete[] 一个数组，也会对每个元素调用一次析构函数
*/
Zombie::~Zombie()
{
    if (_name != "")
        std::cout << _name << " is destroyed" << std::endl;
    else
        std::cout << "Unnamed zombie is destroyed" << std::endl;
}

/*
** setName
** 作用：把成员变量 _name 改成传进来的名字
*/
void Zombie::setName(const std::string &zombieName)
{
    _name = zombieName;
}

/*
** announce
** 作用：输出固定格式的台词
*/
void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
