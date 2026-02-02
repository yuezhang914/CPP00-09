#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

/*
** HumanA：永远有武器的人
** - 用 Weapon&（引用）保存武器：保证“不能为空”
*/
class HumanA
{
public:
    HumanA(const std::string &personName, Weapon &personWeapon);
    ~HumanA();

    void attack(void) const;

private:
    std::string _name;
    Weapon&     _weapon; // 引用：必须初始化，永远存在
};

#endif
