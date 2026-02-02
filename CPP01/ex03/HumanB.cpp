#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &personName) : _name(personName), _weaponPtr(0)
{
    // _weaponPtr 初始化为 0，表示“现在没有武器”
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &personWeapon)
{
    _weaponPtr = &personWeapon;
}

void HumanB::attack(void) const
{
    if (_weaponPtr == 0)
    {
        // 题目说 HumanB 可能没有武器，所以这里必须安全处理
        std::cout << _name << " attacks with their fists" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weaponPtr->getType() << std::endl;
}
