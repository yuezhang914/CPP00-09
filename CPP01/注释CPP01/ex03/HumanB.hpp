#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>  // std::string
#include "Weapon.hpp"

/*
** HumanB（可能没有武器的人）
**
** 题目要求：
** - HumanB 构造时不一定给武器
** - 以后可以再 setWeapon
**
** 初中生理解版：
** - HumanB 一开始可能空手
** - 所以我们必须允许“没有武器”的状态
**
** 因此用 Weapon*（指针）：
** - 指针可以是 0（空指针），表示“现在没有武器”
*/
class HumanB
{
public:
    /*
    ** 构造函数
    ** 作用：创建 HumanB，只设置名字，武器先为空
    ** 参数：
    ** - personName：人的名字
    */
    HumanB(const std::string &personName);

    ~HumanB();

    /*
    ** setWeapon
    ** 作用：给 HumanB 设置武器（从此不再空手）
    ** 参数：
    ** - personWeapon：传入一个武器对象（引用）
    ** 注意：
    ** - 我们内部保存它的地址 &personWeapon
    */
    void setWeapon(Weapon &personWeapon);

    /*
    ** attack
    ** 作用：输出攻击信息
    ** 注意：
    ** - 如果没有武器（_weaponPtr == 0），必须安全处理，不能崩溃
    */
    void attack(void) const;

private:
    std::string _name;  // 人名
    Weapon*     _weaponPtr; // 指针：可能是 0（没有武器）
};

#endif
