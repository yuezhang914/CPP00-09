#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("")
{
    // 默认构造不输出，避免刷屏
}

Zombie::~Zombie()
{
    if (_name != "")
        std::cout << _name << " is destroyed" << std::endl;
    else
        std::cout << "Unnamed zombie is destroyed" << std::endl;
}

void Zombie::setName(const std::string &zombieName)
{
    _name = zombieName;
}

void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
