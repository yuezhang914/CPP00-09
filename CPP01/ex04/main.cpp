#include <fstream>
#include <iostream>
#include <string>

/*
** 把一行里的所有 from 子串，替换成 to
** 注意：题目禁止用 std::string::replace，所以我们用 “切片 + 拼接”
**
** 参数：
** - textLine：原始一行
** - from：要被替换的旧串（s1）
** - to：新串（s2）
**
** 返回值：替换后的新字符串
*/
static std::string replaceAll(const std::string &textLine,
                              const std::string &from,
                              const std::string &to)
{
    std::string result;
    std::string::size_type searchPos = 0;
    std::string::size_type foundPos = 0;

    // 只用 while
    while (true)
    {
        foundPos = textLine.find(from, searchPos);
        if (foundPos == std::string::npos)
        {
            // 后面再也找不到了：把剩余部分接上
            result += textLine.substr(searchPos);
            break;
        }

        // 1) 先把 “searchPos 到 foundPos 之间” 的原文接上
        result += textLine.substr(searchPos, foundPos - searchPos);

        // 2) 再接上替换后的新串
        result += to;

        // 3) 更新 searchPos：跳过这次匹配的 from
        searchPos = foundPos + from.size();
    }
    return result;
}

static int printError(const std::string &msg)
{
    std::cout << "Error: " << msg << std::endl;
    return 1;
}

/*
** 主程序用法（符合题目）：
** ./Sed <filename> <s1> <s2>
*/
int main(int argc, char **argv)
{
    if (argc != 4)
        return printError("usage: ./Sed <filename> <s1> <s2>");

    std::string inputFileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1 == "")
        return printError("s1 must not be empty");

    std::ifstream inputFile(inputFileName.c_str());
    if (!inputFile.is_open())
        return printError("cannot open input file");

    std::string outputFileName = inputFileName + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open())
        return printError("cannot create output file");

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceAll(line, s1, s2);
        if (!inputFile.eof())
            outputFile << std::endl;
    }

    return 0;
}
