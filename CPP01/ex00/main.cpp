#include "Zombie.hpp"
#include <iostream>

/*
** main：做一个不会卡住的简单测试
** - 不用 cin，避免评审运行时等待输入
*/
int main(void)
{
    // 1) 栈上创建：函数结束自动销毁
    randomChump("StackZombie");

    // 2) 堆上创建：必须 delete
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "Done." << std::endl;
    return 0;
}
