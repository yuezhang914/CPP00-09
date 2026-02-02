#include "Harl.hpp"
#include <iostream> // std::cout, std::endl

/*
** LevelAction 结构体（struct）
** 作用：把“等级文字”和“对应要调用的函数”绑在一起
**
** 结构体里的两项：
** - levelText：等级文字，比如 "DEBUG"
** - action：成员函数指针，指向 Harl 的某个成员函数
**
** 新概念：成员函数指针
** - 普通函数指针（C 里）：void (*fp)()
** - 成员函数指针（C++ 类里）：void (Harl::*fp)()
**
** 为什么不一样？
** - 因为成员函数必须通过“某个对象”来调用（需要 this）
*/
struct LevelAction
{
    const char* levelText;
    void (Harl::*action)(void);
};

Harl::Harl()
{
}

Harl::~Harl()
{
}

/*
** complain
** 作用：查表（LevelAction table）找到匹配 level 的项，然后调用对应函数
**
** 参数：
** - level：外面传进来的等级字符串
**
** 关键点（初中生理解版）：
** - 我们准备一张表：每行是“文字 + 要做的动作”
** - 找到文字相同的一行，就执行那一行动作
*/
void Harl::complain(const std::string &level)
{
    // 准备一个固定大小为 4 的表（不用 vector，因为 module 01 禁 STL 容器）
    LevelAction table[4];

    // 逐项填充表：等级文字 + 对应成员函数地址
    table[0].levelText = "DEBUG";
    table[0].action = &Harl::debug;

    table[1].levelText = "INFO";
    table[1].action = &Harl::info;

    table[2].levelText = "WARNING";
    table[2].action = &Harl::warning;

    table[3].levelText = "ERROR";
    table[3].action = &Harl::error;

    /*
    ** 用 for 查找匹配项
    ** - index 从 0 到 3
    ** - 如果 level == table[index].levelText，就调用对应函数
    */
    for (int index = 0; index < 4; index++)
    {
        if (level == table[index].levelText)
        {
            /*
            ** 调用成员函数指针的语法（非常重要）：
            ** (this->*(table[index].action))();
            **
            ** 解释：
            ** - this：当前对象（当前这只 Harl）
            ** - table[index].action：指向某个成员函数（比如 &Harl::debug）
            ** - this->*：把“成员函数指针”绑定到当前对象
            ** - 最后 () 才是真正调用
            */
            (this->*(table[index].action))();
            return; // 找到并执行后就结束
        }
    }

    // 如果 level 不匹配任何一项：ex05 题目没强制输出什么，这里选择安静
}

/*
** debug/info/warning/error
** 作用：输出不同等级的吐槽
** 参数：无
** 返回：无
**
** 注意：
** - 这些文字是题目示例常用内容，你也可以输出你自己的句子
** - 但建议保持稳定、简单，避免评审对比时出意外
*/
void Harl::debug(void)
{
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!"
        << std::endl;
}

void Harl::warning(void)
{
    std::cout
        << "I think I deserve to have some extra bacon for free. I've been coming for years."
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}
