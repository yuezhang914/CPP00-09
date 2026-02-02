// =========================
// 文件用途：
//   ex00 - Megaphone
//   把命令行参数（argv 里）全部输出成大写。
//   如果没有参数，就输出题目要求的一句固定文字。
// =========================

// iostream：C++ 的标准“输入输出库”
// 里面有 std::cout（往屏幕输出）、std::cin（从键盘输入）等
#include <iostream>

// cctype：C/C++ 的“字符处理库”
// 里面有 std::toupper（把字母变大写）等
#include <cctype>

/*
 * 函数：main（程序入口）
 * 作用：
 *   程序从这里开始执行。
 *   读取命令行参数，把它们逐字符转成大写并输出。
 *
 * 参数解释（和 C 语言一样）：
 *   argumentCount（常见写法 argc）：
 *     参数个数。至少为 1，因为 argv[0] 是程序名字。
 *
 *   argumentValues（常见写法 argv）：
 *     参数数组。每个元素都是一个“C 风格字符串”（以 '\0' 结尾）。
 *     - argv[0]：程序名，例如 "./megaphone"
 *     - argv[1]：第一个真正的参数
 *     - argv[2]：第二个参数……
 *
 * 返回值：
 *   0 表示程序正常结束（操作系统看到 0 一般认为成功）。
 */
int main(int argumentCount, char **argumentValues)
{
    // argIndex：用来遍历“第几个参数”
    // 我们从 1 开始，因为 0 是程序名，不算题目要处理的内容
    int argIndex;

    // 如果 argumentCount <= 1，说明用户没有输入任何额外参数
    // 题目要求此时输出固定句子
    if (argumentCount <= 1)
    {
        // std::cout：标准输出（往屏幕打印）
        // << ：把内容“送进输出流”
        // \n：换行（题目要求输出要以换行结尾）
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0; // 直接结束程序
    }

    // 从第 1 个参数开始处理（跳过程序名）
    argIndex = 1;

    // while 循环条件：只要 argIndex 还没到 argumentCount 就继续
    // 例如 argc=3，合法下标是 0、1、2，所以 argIndex < argc
    while (argIndex < argumentCount)
    {
        // charIndex：遍历当前参数字符串里的“第几个字符”
        int charIndex;

        // 从字符串第 0 个字符开始
        charIndex = 0;

        // argumentValues[argIndex] 是一个 C 字符串（char*）
        // 它以 '\0'（空字符）作为结尾标记。
        // 所以我们一直读到 '\0' 为止。
        while (argumentValues[argIndex][charIndex] != '\0')
        {
            // unsigned char：无符号字符（0~255）
            // 为什么要用它？
            //   因为 std::toupper 的参数范围要求更安全的做法是：
            //   先把 char 转成 unsigned char，避免 char 为负值时出错（未定义行为）。
            unsigned char ch;

            // 取出当前字符
            ch = (unsigned char)argumentValues[argIndex][charIndex];

            // std::toupper：把字母转成大写
            // - 如果 ch 是 'a'~'z'，会变成 'A'~'Z'
            // - 如果不是字母（比如空格、标点、数字），通常保持不变
            //
            // (char) 强转：因为 toupper 返回的是 int，我们想输出成字符
            std::cout << (char)std::toupper(ch);

            // 字符下标 +1，继续处理下一个字符
            charIndex = charIndex + 1;
        }

        // 参数下标 +1，继续处理下一个参数
        argIndex = argIndex + 1;
    }

    // 所有参数都输出完后，输出一个换行
    std::cout << '\n';

    // 正常结束
    return 0;
}
