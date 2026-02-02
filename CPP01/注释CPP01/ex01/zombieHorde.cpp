#include "Zombie.hpp"

/*
** zombieHorde
** 作用：一次性创建 count 个 Zombie，并设置名字
**
** “一次性分配”是什么意思？
** - 不是 new 一个、再 new 一个……
** - 而是只写一次：new Zombie[count]
** 这样系统会给你一整段连续空间，里面放 count 个 Zombie。
*/
Zombie* zombieHorde(int count, const std::string &zombieName)
{
    // count 不合法：直接返回空指针，表示失败
    if (count <= 0)
        return 0;

    // 一次性创建 count 个 Zombie（在堆上）
    Zombie* zombieArray = new Zombie[count];

    // 用 for 循环给每个 Zombie 设置名字
    // 条件：index < count，表示从 0 到 count-1
    for (int index = 0; index < count; index++)
    {
        zombieArray[index].setName(zombieName);
    }

    // 返回数组首元素指针
    return zombieArray;
}
