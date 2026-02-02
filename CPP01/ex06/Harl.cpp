#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

/*
** 把等级文字转成数字：
** DEBUG->0 INFO->1 WARNING->2 ERROR->3
** 不匹配则返回 -1
*/
int Harl::levelToIndex(const std::string &level) const
{
	const char *levels[4];
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	// 改回（for 版）：把等级文字映射到数字 0~3
	for (int index = 0; index < 4; index++)
	{
		if (level == levels[index])
			return index; // 找到就返回对应编号
	}
	return -1; // 没找到：返回 -1 表示无效等级
}

void Harl::filter(const std::string &level)
{
	int idx = levelToIndex(level);

	switch (idx)
	{
	case 0:
		debug();
		// 不写 break：让它继续往下执行（fall-through）
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my burger." << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve extra bacon for free." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
