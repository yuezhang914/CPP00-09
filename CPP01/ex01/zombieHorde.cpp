#include "Zombie.hpp"

/*
** 只用 while，不用 for（按你的习惯）
*/
Zombie* zombieHorde(int count, const std::string &zombieName)
{
    if (count <= 0)
        return 0; // 0 表示空指针（C++98 常见写法）

    Zombie* zombieArray = new Zombie[count];

    int index = 0;
    while (index < count)
    {
        zombieArray[index].setName(zombieName);
        index++;
    }
    return zombieArray;
}
