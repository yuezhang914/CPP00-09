#include <iostream>
#include <string>

/*
** 目标：
** - 让你看到“变量/指针/引用”的地址和值到底是什么
*/
int main(void)
{
    std::string text = "HI THIS IS BRAIN";

    // 指针：保存“地址”
    std::string* textPtr = &text;

    // 引用：给同一个变量起一个“别名”
    std::string& textRef = text;

    std::cout << "---- Addresses (地址) ----" << std::endl;
    std::cout << "&text    = " << &text << std::endl;
    std::cout << "textPtr  = " << textPtr << std::endl;
    std::cout << "&textRef = " << &textRef << std::endl;

    std::cout << "---- Values (值) ----" << std::endl;
    std::cout << "text     = " << text << std::endl;
    std::cout << "*textPtr = " << *textPtr << std::endl;
    std::cout << "textRef  = " << textRef << std::endl;

    return 0;
}
