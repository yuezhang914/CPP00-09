#include "HumanA.hpp"
#include <iostream> // std::cout, std::endl

/*
** HumanA 构造函数
** 初始化列表里同时初始化 _name 和 _weapon
** - _weapon 是引用，必须在初始化列表里绑定，不能在函数体里再赋值
*/
HumanA::HumanA(const std::string &personName,
	Weapon &personWeapon) : _name(personName), _weapon(personWeapon)
{
}

HumanA::~HumanA()
{
}

/*
** attack
** 作用：打印攻击信息
** 注意：
** - _weapon 是引用，所以用点号：_weapon.getType()
*/
void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
