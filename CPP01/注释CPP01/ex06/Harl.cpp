#include "Harl.hpp"
#include <iostream> // std::cout, std::endl

Harl::Harl()
{
}

Harl::~Harl()
{
}

/*
** levelToIndex
** 作用：把等级文字转换成数字，方便 switch
**
** 为什么需要它？
** - switch 在 C++98 里不能直接用 string
** - 所以我们用数字代替
**
** 做法：
** - 用一个固定数组 levels[4]
** - 遍历去找匹配的下标
*/
int Harl::levelToIndex(const std::string &level) const
{
    const char* levels[4];
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    for (int index = 0; index < 4; index++)
    {
        if (level == levels[index])
            return index;
    }
    return -1; // 不合法等级
}

/*
** filter
** 作用：
** - 把 level 转成 idx（0~3 或 -1）
** - 用 switch 根据 idx 决定从哪个等级开始输出
**
** 初中生理解版：
** - idx=2（WARNING）表示：
**   先输出 WARNING，再输出 ERROR
**
** 新概念：switch 的“贯穿”（fall-through）
** - 如果 case 里不写 break，它会继续执行下面的 case
** - 这题正好要“从某等级一直输出到最后”，所以故意不写 break
*/
void Harl::filter(const std::string &level)
{
    int idx = levelToIndex(level);

    switch (idx)
    {
        case 0:
            debug();
            // 不写 break：继续执行 case 1/2/3
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break; // 到最后一定要 break
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

/*
** 下面四个函数：输出四种等级信息
** 为了更像题目示例，这里加上 [ LEVEL ] 标题
*/
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout
        << "I love having extra bacon for my burger."
        << std::endl;
    std::cout << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout
        << "I cannot believe adding extra bacon costs more money."
        << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout
        << "I think I deserve extra bacon for free."
        << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
    std::cout << std::endl;
}
