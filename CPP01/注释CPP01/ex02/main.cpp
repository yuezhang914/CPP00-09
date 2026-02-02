#include <iostream> // std::cout, std::endl
#include <string>   // std::string

/*
** main
** 作用：
** - 创建一个字符串变量 text
** - 创建一个指针 textPtr 指向 text
** - 创建一个引用 textRef 绑定 text
** - 打印三者的“地址”和“值”
**
** 参数：
** - argc/argv 这里不需要，用不到
** 返回：
** - 0 表示程序正常结束
**
** 初中生理解版：
** - 变量 text：像“本体”
** - 指针 textPtr：像“写着地址的纸条”，纸条上写着本体在哪
** - 引用 textRef：像“给本体起的小名”，叫小名=叫本体
*/
int main(void)
{
    // 1) 创建一个字符串变量（本体）
    std::string text = "HI THIS IS BRAIN";

    // 2) 指针：保存“text 的地址”
    // &text：取地址（你可以理解为“这个东西放在哪个房间”）
    std::string* textPtr = &text;

    // 3) 引用：给 text 起一个“别名”
    // 注意：引用必须在定义时就绑定一个对象，不能空着
    std::string& textRef = text;

    // ===== 打印地址 =====
    std::cout << "---- Addresses (地址) ----" << std::endl;

    // &text：text 这个变量本体的地址
    std::cout << "&text    = " << &text << std::endl;

    // textPtr：指针里保存的地址（应该和 &text 一样）
    std::cout << "textPtr  = " << textPtr << std::endl;

    // &textRef：引用其实就是 text 的别名，所以地址也应和 &text 一样
    std::cout << "&textRef = " << &textRef << std::endl;

    // ===== 打印值 =====
    std::cout << "---- Values (值) ----" << std::endl;

    // text：本体的值
    std::cout << "text     = " << text << std::endl;

    // *textPtr：解引用（从地址里把值取出来）
    std::cout << "*textPtr = " << *textPtr << std::endl;

    // textRef：引用的值（等同于 text）
    std::cout << "textRef  = " << textRef << std::endl;

    return 0;
}
