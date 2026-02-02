#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string> // std::string

/*
** Weapon（武器类）
** 作用：保存“武器类型”这段文字，比如 "crude spiked club"
**
** 初中生理解版：
** - 这就是一个“装着武器名字的盒子”
** - 盒子里有一张纸条 _type，写着武器是什么
*/
class Weapon
{
public:
    /*
    ** 构造函数
    ** 作用：创建武器时就给它一个初始类型
    ** 参数：
    ** - weaponType：武器类型文字
    */
    Weapon(const std::string &weaponType);

    /*
    ** 析构函数
    ** 作用：这题不需要释放资源，但还是写出来（保持规范）
    */
    ~Weapon();

    /*
    ** getType
    ** 作用：把武器类型拿出来给别人看（只读）
    ** 返回：
    ** - const std::string& ：“常量引用”
    **
    ** 为什么返回常量引用？
    ** 1) 不复制字符串：更快（省内存/省时间）
    ** 2) const：别人只能看，不能用这个返回值去修改内部 _type
    **
    ** 注意：函数末尾也加 const
    ** - 表示这个函数不会改 Weapon 自己的内部数据
    */
    const std::string& getType(void) const;

    /*
    ** setType
    ** 作用：修改武器类型
    ** 参数：
    ** - newType：新的武器类型文字
    */
    void setType(const std::string &newType);

private:
    // _type：武器类型文字（类内部成员变量）
    std::string _type;
};

#endif
