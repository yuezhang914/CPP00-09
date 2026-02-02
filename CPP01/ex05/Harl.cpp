#include "Harl.hpp"
#include <iostream>

/*
** 一个小结构体：用来把 “等级文字” 和 “对应函数” 放在一起
** - levelText：比如 "DEBUG"
** - action：指向成员函数的指针
**
** 成员函数指针类型：
** void (Harl::*)()
** 读法：指向 Harl 的成员函数，返回 void，参数为空
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

void Harl::complain(const std::string &level)
{
    LevelAction table[4];

    table[0].levelText = "DEBUG";
    table[0].action = &Harl::debug;
    table[1].levelText = "INFO";
    table[1].action = &Harl::info;
    table[2].levelText = "WARNING";
    table[2].action = &Harl::warning;
    table[3].levelText = "ERROR";
    table[3].action = &Harl::error;

    int index = 0;
    while (index < 4)
    {
        if (level == table[index].levelText)
        {
            // 调用成员函数指针：需要绑定到当前对象 this
            (this->*(table[index].action))();
            return;
        }
        index++;
    }
}

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

