#include "Weapon.hpp"

/*
** Weapon 构造函数
** 作用：把传入的 weaponType 保存到成员变量 _type
** 这里用初始化列表：创建时直接给 _type 赋值
*/
Weapon::Weapon(const std::string &weaponType) : _type(weaponType)
{
}

/*
** Weapon 析构函数
** 这题没有 new 的资源要释放，所以为空也可以
*/
Weapon::~Weapon()
{
}

/*
** getType
** 返回 _type 的“常量引用”
** 注意：return _type; 返回的是内部成员，不会复制（因为是引用）
*/
const std::string& Weapon::getType(void) const
{
    return _type;
}

/*
** setType
** 作用：把 _type 改成 newType
*/
void Weapon::setType(const std::string &newType)
{
    _type = newType;
}
