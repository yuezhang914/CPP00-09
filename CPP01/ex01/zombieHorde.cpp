#include "Zombie.hpp"

/*
** 只用 while，不用 for（按你的习惯）
*/
Zombie *zombieHorde(int count, const std::string &zombieName)
{
	if (count <= 0)
		return 0; // 0 表示空指针（C++98 常见写法）

	Zombie *zombieArray = new Zombie[count];

	// 改回（for 版）：更直观：index 从 0 到 count-1
	for (int index = 0; index < count; index++)
	{
		// 给每一个僵尸设置同样的名字
		zombieArray[index].setName(zombieName);
	}
	return zombieArray;
}
