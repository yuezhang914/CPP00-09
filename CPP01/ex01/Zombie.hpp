#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*
** ex01 的 Zombie 需要默认构造（因为要 new Zombie[N]）
** 然后再用 setName 给每个僵尸设置名字。
*/
class Zombie
{
public:
    Zombie();                         // 默认构造：先创建空名字僵尸
    ~Zombie();

    void setName(const std::string &zombieName); // 设置名字
    void announce(void) const;                   // 按固定格式输出

private:
    std::string _name;
};

/*
** zombieHorde：
** - 一次性 new Zombie[N]
** - 给每个 Zombie 设置相同名字
** - 返回数组首元素指针
**
** 注意：返回的是数组，所以释放要用 delete[]
*/
Zombie* zombieHorde(int count, const std::string &zombieName);

#endif
