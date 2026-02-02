#include "Zombie.hpp"
#include <iostream>

/*
** Zombie 构造函数实现
** 作用：把传进来的名字保存到成员变量 _name
**
** 这里用“初始化列表”：
**   Zombie::Zombie(...) : _name(zombieName) {}
** 你可以理解成：对象刚出生时就直接把名字写进身份证上，
** 而不是出生后再拿笔去改（更标准、更高效）。
*/
Zombie::Zombie(const std::string &zombieName) : _name(zombieName)
{
    // 这里不强制输出，避免刷屏
}

/*
** Zombie 析构函数实现
** 作用：对象销毁时打印一行，方便你观察生命周期
** 什么时候会触发析构？
** - 栈对象：离开作用域自动触发
** - 堆对象：delete 时触发
*/
Zombie::~Zombie()
{
    std::cout << _name << " is destroyed" << std::endl;
}

/*
** announce 实现
** 作用：按题目要求格式输出一句话
*/
void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
