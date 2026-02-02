#include "Harl.hpp"
#include <iostream>

/*
** 用法：
** ./harlFilter WARNING
*/
int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    harl.filter(argv[1]);
    return 0;
}
