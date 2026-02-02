#include "Zombie.hpp"

/*
** randomChump 实现
** 作用：在栈上创建一个 Zombie，立即 announce
**
** 重点：
** - 这里不用 new
** - 因为我们只想“用一下就结束”
** - 函数结束时 zombieObj 会自动析构
*/
void randomChump(const std::string &zombieName)
{
    // zombieObj 是局部变量：存在栈上
    Zombie zombieObj(zombieName);

    // 让它说话
    zombieObj.announce();

    // 函数结束后，zombieObj 自动销毁（析构函数自动运行）
}
