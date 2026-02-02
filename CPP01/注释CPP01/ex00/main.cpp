#include "Zombie.hpp"
#include <iostream>

/*
** main
** 作用：做一个不会卡住的简单测试
** 注意：不要用 cin 等输入，否则评审跑程序可能一直等输入
*/
int main(void)
{
    // 1) 栈对象测试：randomChump 内部创建，函数结束自动销毁
    randomChump("StackZombie");

    // 2) 堆对象测试：newZombie 返回指针，必须 delete
    Zombie* heapZombie = newZombie("HeapZombie");

    // 指针访问成员函数：用 -> （指针的点号）
    heapZombie->announce();

    // 释放堆对象：非常重要，否则内存泄漏
    delete heapZombie;

    std::cout << "Done." << std::endl;
    return 0;
}
