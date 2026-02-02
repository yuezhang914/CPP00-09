#include "Zombie.hpp"
#include <iostream>

/*
** main
** 作用：测试 zombieHorde 是否正确
** 做法：
** - 创建一群僵尸
** - 让每个僵尸 announce
** - 最后 delete[] 释放整群僵尸
*/
int main(void)
{
    int count = 5;

    // 创建一群僵尸（堆上数组）
    Zombie* zombieArray = zombieHorde(count, "HordeZombie");

    // 如果返回 0，说明创建失败（例如 count<=0）
    if (zombieArray == 0)
    {
        std::cout << "count is not valid" << std::endl;
        return 0;
    }

    // 让每个僵尸都 announce 一次
    for (int index = 0; index < count; index++)
    {
        zombieArray[index].announce();
    }

    // 释放数组：必须 delete[]
    delete[] zombieArray;

    return 0;
}
