#include "Contact.hpp"

#include <iostream>   // std::cout
#include <iomanip>    // std::setw（设置输出宽度）

/*
 * 构造函数：Contact::Contact
 * 作用：把联系人初始化为空
 * 参数：无
 * 返回：无
 */
Contact::Contact(void)
{
    // 把 5 个字段清空（空字符串）
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";

    // 标记为空联系人
    this->hasValue = false;
}

/*
 * 析构函数：Contact::~Contact
 * 作用：对象销毁时调用（这里没有 new 资源，所以不做事）
 */
Contact::~Contact(void)
{
    return;
}

/*
 * 函数：isEmpty
 * 作用：判断联系人是否为空
 * 参数：无
 * 返回：true=空；false=有数据
 */
bool Contact::isEmpty(void) const
{
    return (this->hasValue == false);
}

/*
 * 函数：setAll
 * 作用：把 5 个字段都保存，并标记 hasValue=true
 */
void Contact::setAll(
    const std::string &newFirstName,
    const std::string &newLastName,
    const std::string &newNickname,
    const std::string &newPhoneNumber,
    const std::string &newDarkestSecret)
{
    this->firstName = newFirstName;
    this->lastName = newLastName;
    this->nickname = newNickname;
    this->phoneNumber = newPhoneNumber;
    this->darkestSecret = newDarkestSecret;

    // 存入成功后不再是空联系人
    this->hasValue = true;
}

/*
 * 下面这个函数是“本文件私有的小工具”，外部看不到（static）。
 *
 * 函数：printColumn10
 * 作用：
 *   打印一个字符串列，要求“列宽 10”：
 *   - 如果长度 > 10：输出前 9 个字符 + '.'（总长度 10）
 *   - 如果长度 <=10：用 setw(10) 右对齐输出
 */
static void printColumn10(const std::string &text)
{
    if (text.size() > 10)
    {
        // substr(0, 9)：从第 0 位开始截取 9 个字符
        std::cout << text.substr(0, 9) << '.';
        return;
    }

    // setw(10)：设置“接下来一次输出”的宽度为 10（默认右对齐）
    std::cout << std::setw(10) << text;
}

/*
 * 函数：printTableRow
 * 作用：按题目表格要求打印一行：index/first/last/nickname
 */
void Contact::printTableRow(int index) const
{
    // index 列：宽 10
    std::cout << "|" << std::setw(10) << index << "|";

    // firstName 列：宽 10，超长截断
    printColumn10(this->firstName);
    std::cout << "|";

    // lastName 列
    printColumn10(this->lastName);
    std::cout << "|";

    // nickname 列
    printColumn10(this->nickname);
    std::cout << "|\n";
}

/*
 * 函数：printFull
 * 作用：打印联系人全部字段（用于 SEARCH 选中后展示）
 */
void Contact::printFull(void) const
{
    std::cout << "First name: " << this->firstName << "\n";
    std::cout << "Last name: " << this->lastName << "\n";
    std::cout << "Nickname: " << this->nickname << "\n";
    std::cout << "Phone number: " << this->phoneNumber << "\n";
    std::cout << "Darkest secret: " << this->darkestSecret << "\n";
}
