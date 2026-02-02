#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    int count = 5;
    Zombie* zombieArray = zombieHorde(count, "HordeZombie");

    if (zombieArray == 0)
    {
        std::cout << "count is not valid" << std::endl;
        return 0;
    }

    int index = 0;
    while (index < count)
    {
        zombieArray[index].announce();
        index++;
    }

    delete[] zombieArray;
    return 0;
}
