#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int count = 5;
	Zombie *zombieArray = zombieHorde(count, "HordeZombie");

	if (zombieArray == 0)
	{
		std::cout << "count is not valid" << std::endl;
		return 0;
	}

	// 改回（for 版）：逐个打印每个僵尸的 announce
	for (int index = 0; index < count; index++)
	{
		zombieArray[index].announce();
	}

	delete[] zombieArray;
	return 0;
}
