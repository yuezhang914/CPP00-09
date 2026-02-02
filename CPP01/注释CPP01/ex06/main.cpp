#include "Harl.hpp"
#include <iostream> // std::cout, std::endl

/*
** main
** 作用：读取命令行的 level，然后让 Harl 进行过滤输出
**
** 用法示例：
**   ./harlFilter INFO
**
** 注意：
** - 如果参数数量不对，题目示例通常输出默认那句
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
