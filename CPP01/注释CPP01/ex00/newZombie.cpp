#include "Zombie.hpp"

/*
** newZombie 实现
** 作用：在堆上创建 Zombie，并把指针返回出去
**
** 为什么要返回指针？
** - 因为堆上对象不会自动消失
** - 你把指针交给外面，外面才能继续使用它
*/
Zombie* newZombie(const std::string &zombieName)
{
    // zombiePtr：指向堆上新建 Zombie 的指针
    Zombie* zombiePtr = new Zombie(zombieName);

    // 返回给调用者
    return zombiePtr;
}
