#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*
** ex01 的重点：一次性创建 N 个 Zombie（数组）
**
** 当你写 new Zombie[N] 时，
** C++ 会先创建 N 个 Zombie 对象。
** 所以 Zombie 必须有“默认构造函数”（不带参数也能创建）
*/
class Zombie
{
public:
    /*
    ** 默认构造函数
    ** 作用：创建一个“暂时没有名字”的 Zombie
    ** 为什么需要？
    ** - new Zombie[N] 需要每个元素都能被“默认创建”
    */
    Zombie();

    /*
    ** 析构函数：销毁时打印调试信息
    */
    ~Zombie();

    /*
    ** setName
    ** 作用：给 Zombie 设置名字
    ** 参数：
    ** - zombieName：新名字
    */
    void setName(const std::string &zombieName);

    /*
    ** announce
    ** 作用：按固定格式输出一句话
    */
    void announce(void) const;

private:
    std::string _name;
};

/*
** zombieHorde（题目要求的函数）
** 作用：
** - 一次性在堆上创建 count 个 Zombie（数组）
** - 给每个 Zombie 设置同样的名字
** 参数：
** - count：要创建多少个 Zombie
** - zombieName：每个 Zombie 的名字
** 返回：
** - Zombie*：数组首元素指针
** 注意：
** - 返回的是“数组指针”，释放必须用 delete[]
** - 如果 count <= 0，返回 0（空指针）
*/
Zombie* zombieHorde(int count, const std::string &zombieName);

#endif
