#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*
** Zombie 类（class）
** 你可以把它理解成“升级版 struct”：
** - 里面有数据（名字 _name）
** - 还有操作数据的函数（announce）
**
** private / public 是“权限”：
** - private：外面不让直接碰（更安全）
** - public：外面能用的接口（像遥控器按钮）
*/
class Zombie
{
public:
    /*
    ** 构造函数（constructor）
    ** 作用：创建 Zombie 对象时，给它设置名字
    ** 参数：
    ** - zombieName：僵尸的名字（字符串）
    ** 注意：
    ** - 构造函数名字必须和类名一样
    ** - 没有返回值类型
    */
    Zombie(const std::string &zombieName);

    /*
    ** 析构函数（destructor）
    ** 作用：Zombie 对象要被销毁时自动运行
    ** 这里我们用它打印一行调试信息，帮你观察对象什么时候“真的消失”
    ** 注意：
    ** - 析构函数名字是 ~类名
    ** - 也没有返回值
    */
    ~Zombie();

    /*
    ** announce
    ** 作用：输出固定格式：
    **   "<name>: BraiiiiiiinnnzzzZ..."
    ** 注意：
    ** - 末尾加 const：表示这个函数不会修改对象内部数据
    **   （只读，不改名字）
    */
    void announce(void) const;

private:
    /*
    ** _name：僵尸名字
    ** 前面加下划线只是习惯：提醒这是“类内部成员变量”
    */
    std::string _name;
};

/*
** newZombie（题目要求的函数）
** 作用：在“堆(Heap)”上创建一个 Zombie，并返回指针
** 参数：
** - zombieName：僵尸名字
** 返回：
** - Zombie*：指向新建 Zombie 的指针
** 注意：
** - 用 new 出来的东西不会自动消失
** - 你必须在外面用 delete 释放它
*/
Zombie* newZombie(const std::string &zombieName);

/*
** randomChump（题目要求的函数）
** 作用：在“栈(Stack)”上创建一个 Zombie，立刻让它 announce
** 参数：
** - zombieName：僵尸名字
** 返回：无
** 注意：
** - 栈上的对象函数结束会自动析构（自动消失）
** - 不需要 delete
*/
void randomChump(const std::string &zombieName);

#endif
