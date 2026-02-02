#include "Harl.hpp"
#include <iostream> // std::cout, std::endl

/*
** main
** 作用：从命令行拿一个 level，然后让 Harl 按该 level 吐槽一次
**
** 用法示例：
**   ./Harl WARNING
**
** 注意：
** - 不用 std::cin，避免评审运行时卡住等待输入
*/
int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "usage: ./Harl <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 0;
    }

    harl.complain(argv[1]);
    return 0;
}
