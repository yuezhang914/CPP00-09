#include <fstream>  // std::ifstream, std::ofstream（文件输入/输出流）
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

/*
** printError
** 作用：打印错误信息，并返回 1（表示程序失败）
** 参数：
** - message：错误提示文字
** 返回：
** - 1（常见习惯：非 0 表示出错）
** 注意：
** - 题目没规定错误输出必须用 cerr，这里用 cout 也能过
*/
static int printError(const std::string &message)
{
    std::cout << "Error: " << message << std::endl;
    return 1;
}

/*
** replaceAllInLine
** 作用：把一行 textLine 里的所有 oldText（s1）替换成 newText（s2），返回替换后的结果
**
** 参数：
** - textLine：原始一行内容
** - oldText：要被替换掉的文字（s1）
** - newText：替换成的新文字（s2）
**
** 返回：
** - 替换后的新字符串
**
** 注意（非常关键）：
** - 题目禁止使用 std::string::replace，所以我们用：
**   find（找到位置） + substr（切片） + 拼接
**
** 初中生理解版：
** - 你拿一条长纸带（textLine）
** - 每次找到一个“旧字串 oldText”
** - 就把旧字串前面的部分剪下来贴到 result
** - 再贴上新字串 newText
** - 然后继续从旧字串后面接着找
*/
static std::string replaceAllInLine(const std::string &textLine,
                                    const std::string &oldText,
                                    const std::string &newText)
{
    std::string result; // 最终要返回的新行内容
    std::string::size_type searchStart = 0; // 从这一位开始找（size_type 是无符号整数类型）
    std::string::size_type foundPos = 0;    // 找到 oldText 的位置

    /*
    ** 循环不断查找 oldText
    ** - 如果找不到：find 会返回 std::string::npos（not position，表示“没位置”）
    */
    while (true)
    {
        foundPos = textLine.find(oldText, searchStart);

        // 找不到了：把剩余部分全部接上，然后结束
        if (foundPos == std::string::npos)
        {
            // substr(searchStart)：从 searchStart 切到结尾
            result += textLine.substr(searchStart);
            break;
        }

        // 1) 把 oldText 前面的那一段原文接到 result
        // substr(start, length)：从 start 开始切 length 个字符
        result += textLine.substr(searchStart, foundPos - searchStart);

        // 2) 接上新的字符串（替换内容）
        result += newText;

        // 3) 更新 searchStart：跳过这次匹配到的 oldText
        // oldText.size() 是旧字符串长度
        searchStart = foundPos + oldText.size();
    }

    return result;
}

/*
** main
** 作用：
** - 从命令行拿 3 个参数：filename, s1, s2
** - 读取文件 filename
** - 生成新文件 filename.replace
** - 把所有出现的 s1 替换成 s2 再写入
**
** 参数：
** - argc：参数数量
** - argv：参数内容数组
**
** 返回：
** - 0：成功
** - 1：失败（参数不对、文件打不开等）
**
** 注意：
** - 题目禁止使用 C 的文件函数（fopen/fread/...），必须用 C++ 文件流 ifstream/ofstream
** - s1 为空字符串必须报错，否则 find 会无限匹配（逻辑会坏）
*/
int main(int argc, char **argv)
{
    // 题目要求：必须是 3 个参数，所以 argc 应该是 4（包含程序名）
    if (argc != 4)
        return printError("usage: ./Sed <filename> <s1> <s2>");

    std::string inputFileName = argv[1]; // 原文件名
    std::string s1 = argv[2];            // 要替换的旧串
    std::string s2 = argv[3];            // 替换成的新串

    // 如果 s1 是空串，find 会在同一个位置一直“找到空串”，会卡住
    if (s1 == "")
        return printError("s1 must not be empty");

    // 打开输入文件（读）
    std::ifstream inputFile(inputFileName.c_str());
    if (!inputFile.is_open())
        return printError("cannot open input file");

    // 输出文件名必须是 <filename>.replace
    std::string outputFileName = inputFileName + ".replace";

    // 打开输出文件（写）
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open())
        return printError("cannot create output file");

    /*
    ** 逐行读取文件：
    ** - std::getline(inputFile, line) 读一行到 line
    ** - 读到文件结束返回 false，循环结束
    */
    std::string line;
    while (std::getline(inputFile, line))
    {
        // 对这一行做替换
        std::string replacedLine = replaceAllInLine(line, s1, s2);

        // 写入输出文件
        outputFile << replacedLine;

        /*
        ** 为什么这里判断 eof 再写换行？
        ** - getline 读到的 line 不包含 '\n'
        ** - 我们想保持原文件行结构
        ** - 但不想在文件末尾多写一个额外换行（有时会被严格对比）
        */
        if (!inputFile.eof())
            outputFile << std::endl;
    }

    // 文件流对象离开作用域会自动关闭文件（析构自动做收尾）
    return 0;
}
