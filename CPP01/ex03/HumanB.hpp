#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

/*
** HumanB：可能没有武器的人
** - 用 Weapon*（指针）保存武器：因为指针可以是空(0)
*/
class HumanB
{
public:
    HumanB(const std::string &personName);
    ~HumanB();

    void setWeapon(Weapon &personWeapon);
    void attack(void) const;

private:
    std::string _name;
    Weapon*     _weaponPtr; // 指针：可能为 0
};

#endif
