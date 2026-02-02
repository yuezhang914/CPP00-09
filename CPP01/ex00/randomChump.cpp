#include "Zombie.hpp"

/*
** 在栈上创建：Zombie zombieObj(...)
** - 这是“局部变量”，函数结束会自动析构
** - 不需要 delete
*/
void randomChump(const std::string &zombieName)
{
    Zombie zombieObj(zombieName);
    zombieObj.announce();
}
