#include "Zombie.hpp"
#include <iostream>

/*
** 这里用“初始化列表”给 _name 赋值：
** - 写法：Zombie::Zombie(...) : _name(...)
** - 好处：更直接、更符合 C++ 风格
*/
Zombie::Zombie(const std::string &zombieName) : _name(zombieName)
{
    // 构造函数里一般不强制输出；这里保持安静更稳
}

Zombie::~Zombie()
{
    // 调试信息：只要名字 + 简单说明，避免 emoji 影响对比输出
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
