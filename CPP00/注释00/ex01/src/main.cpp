#include "PhoneBook.hpp"

#include <iostream>  // cout
#include <string>    // string

/*
 * 这里的 trimSpaces/readTrimmedLine 和 PhoneBook.cpp 里类似，
 * 但它们是 main.cpp 自己的“私有工具函数”，互不影响。
 * 这样写的好处：main.cpp 不需要依赖 PhoneBook.cpp 的内部工具函数。
 */

static std::string trimSpaces(const std::string &text)
{
    size_t start;
    size_t end;

    start = text.find_first_not_of(" \t\v\f\r\n");
    if (start == std::string::npos)
        return "";
    end = text.find_last_not_of(" \t\v\f\r\n");
    return text.substr(start, end - start + 1);
}

static bool readTrimmedLine(std::string &outLine)
{
    std::string rawLine;

    if (!std::getline(std::cin, rawLine))
        return false;
    outLine = trimSpaces(rawLine);
    return true;
}

/*
 * 函数：main（程序入口）
 * 作用：
 *   实现题目要求的“读命令 -> 执行 -> 再读命令”的循环（read/eval loop）
 *
 * 命令：
 *   ADD：增加联系人
 *   SEARCH：搜索并显示
 *   EXIT：退出
 */
int main(void)
{
    PhoneBook   phoneBook;   // 创建电话本对象
    std::string command;     // 保存用户输入的命令

    // 无限循环：一直等用户输入命令
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

        // 读取命令（trim 后）
        // 如果读失败（EOF，比如 Ctrl+D），就退出程序
        if (!readTrimmedLine(command))
            break;

        // EXIT：结束循环，退出程序
        if (command == "EXIT")
            break;

        // ADD：让 phoneBook 自己处理添加流程
        if (command == "ADD")
            phoneBook.addContact();

        // SEARCH：打印表格 + 选 index + 打印详情
        else if (command == "SEARCH")
            phoneBook.searchAndPrint();

        // 空命令：用户直接回车，忽略即可（继续读下一次）
        else if (command.empty())
            continue;

        // 其它命令：题目说可以忽略，这里选择提示一下更友好
        else
            std::cout << "Unknown command. Please type ADD, SEARCH, or EXIT.\n";
    }
    return 0;
}
