#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*
** Zombie 类：表示一个“僵尸”
** - 成员变量 _name：僵尸的名字
** - announce()：在终端说一句固定台词
**
** 说明（给零基础）：
** - class 类似 C 的 struct，但它把“数据 + 操作数据的函数”放一起。
** - private：外面不能直接改，必须通过 public 的函数来用。
*/
class Zombie
{
public:
    /*
    ** 构造函数：创建对象时自动执行
    ** 参数 zombieName：要设置的僵尸名字
    */
    Zombie(const std::string &zombieName);

    /*
    ** 析构函数：对象销毁时自动执行（离开作用域 或 delete）
    ** 用来打印调试信息，帮助你看到“什么时候对象真的被销毁”
    */
    ~Zombie();

    /*
    ** announce：打印 "<name>: BraiiiiiiinnnzzzZ..."
    */
    void announce(void) const;

private:
    std::string _name;
};

/*
** newZombie：
** - 在“堆(Heap)”上创建一个 Zombie，并返回指针
** - 堆对象不会自动销毁，所以你之后必须 delete
*/
Zombie* newZombie(const std::string &zombieName);

/*
** randomChump：
** - 在“栈(Stack)”上创建一个 Zombie（局部变量）
** - 让它 announce
** - 函数结束时自动析构，不需要 delete
*/
void randomChump(const std::string &zombieName);

#endif
