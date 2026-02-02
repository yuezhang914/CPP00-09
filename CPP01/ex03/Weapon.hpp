#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

/*
** Weapon：武器类
** - _type：武器类型字符串，比如 "crude spiked club"
*/
class Weapon
{
public:
    /*
    ** 构造函数：创建武器时就给它一个类型
    */
    Weapon(const std::string &weaponType);

    ~Weapon();

    /*
    ** getType：返回“常量引用”
    ** - const std::string& ：不复制字符串，效率更高
    ** - const：保证外面拿到后不能改内部 _type
    */
    const std::string& getType(void) const;

    /*
    ** setType：修改武器类型
    */
    void setType(const std::string &newType);

private:
    std::string _type;
};

#endif
