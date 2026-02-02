#include "HumanB.hpp"
#include <iostream> // std::cout, std::endl

/*
** HumanB 构造函数
** 重点：_weaponPtr 必须初始化为 0
** 否则它会是“随机值”（野指针），一用就崩
*/
HumanB::HumanB(const std::string &personName) : _name(personName), _weaponPtr(0)
{
	// 0 表示：现在没有武器
}

HumanB::~HumanB()
{
}

/*
** setWeapon
** 作用：把传入武器的地址保存起来
** - &personWeapon：取地址
** - _weaponPtr 保存这个地址
*/
void HumanB::setWeapon(Weapon &personWeapon)
{
	_weaponPtr = &personWeapon;
}

/*
** attack
** 作用：输出攻击信息
** 分两种情况：
** 1) 没武器：用拳头攻击（避免崩溃）
** 2) 有武器：输出武器类型
*/
void HumanB::attack(void) const
{
	// 如果 _weaponPtr 是 0，说明没武器
	if (_weaponPtr == 0)
	{
		std::cout << _name << " attacks with their fists" << std::endl;
		return ;
	}

	// 指针访问成员用 -> （箭头）
	std::cout << _name << " attacks with their " << _weaponPtr->getType() << std::endl;
}
