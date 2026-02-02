#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>  // std::string
#include "Weapon.hpp"

/*
** HumanA（一定有武器的人）
**
** 题目要求：
** - HumanA 在构造时就必须给武器
** - 所以 HumanA 永远“不会没有武器”
**
** 初中生理解版：
** - HumanA 一出生就拿着武器
** - 你不能让他“空手”
**
** 因此最合适的类型是 Weapon&（引用）：
** - 引用不能是空
** - 天然保证“有武器”
*/
class HumanA
{
public:
    /*
    ** 构造函数
    ** 作用：创建 HumanA，并设置名字和武器
    ** 参数：
    ** - personName：人的名字
    ** - personWeapon：这个人手里拿着的武器（引用）
    */
    HumanA(const std::string &personName, Weapon &personWeapon);

    ~HumanA();

    /*
    ** attack
    ** 作用：输出攻击信息
    ** 输出格式：
    **   "<name> attacks with their <weapon type>"
    */
    void attack(void) const;

private:
    std::string _name; // 人名
    Weapon&     _weapon; // 引用：一定存在，不能空
};

#endif
