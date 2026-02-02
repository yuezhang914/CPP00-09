#include "PhoneBook.hpp"

#include <iostream>  // std::cout
#include <string>    // std::string
#include <cctype>    // 字符判断（这里主要是空白字符集合，不一定每次都用到）

/*
 * 构造函数：PhoneBook::PhoneBook
 * 作用：初始化电话本为空
 */
PhoneBook::PhoneBook(void)
{
    // 当前保存 0 个联系人
    this->savedCount = 0;

    // 下一次写入位置从 0 开始
    this->nextWriteIndex = 0;
}

/*
 * 析构函数：PhoneBook::~PhoneBook
 * 作用：销毁电话本（没有 new，不用手动释放）
 */
PhoneBook::~PhoneBook(void)
{
    return;
}

/*
 * 函数：getSavedCount
 * 作用：返回当前保存的联系人数量
 */
int PhoneBook::getSavedCount(void) const
{
    return (this->savedCount);
}

/*
 * 函数：isIndexValid
 * 作用：判断 index 是否有效
 * 规则：必须在 [0, savedCount-1]
 */
bool PhoneBook::isIndexValid(int index) const
{
    if (index < 0)
        return false;
    if (index >= this->savedCount)
        return false;
    return true;
}

/*
 * ====== 工具函数：trimSpaces ======
 * 作用：
 *   去掉字符串首尾的空格/制表符/换行等（trim）
 *
 * 为什么要 trim？
 *   用户可能输入 "   ADD   " 或者直接回车空行。
 *   如果不处理，后面逻辑判断会麻烦，甚至会出现越界崩溃。
 *
 * find_first_not_of / find_last_not_of：
 *   - 找到第一个/最后一个“不是空白字符”的位置
 *   - 如果全是空白，返回 npos（表示没找到）
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

/*
 * ====== 工具函数：readTrimmedLine ======
 * 作用：
 *   从标准输入读一整行（getline），并 trim，结果放到 outLine
 *
 * 为什么要返回 bool？
 *   getline 失败通常表示 EOF（End Of File）
 *   例如用户按 Ctrl+D（Linux/Mac）就会触发 EOF。
 *   评估时很喜欢测试你按 Ctrl+D 会不会崩溃。
 */
static bool readTrimmedLine(std::string &outLine)
{
    std::string rawLine;

    if (!std::getline(std::cin, rawLine))
        return false;

    outLine = trimSpaces(rawLine);
    return true;
}

/*
 * ====== 工具函数：askNonEmptyField ======
 * 作用：
 *   反复询问用户输入某个字段，直到用户输入“非空（trim 后不为空）”
 *
 * 参数：
 *   prompt：提示语，例如 "First name: "
 *   readOk：引用传入的一个“开关”
 *           如果读入过程中遇到 EOF，就把 readOk 设为 false，让上层停止 ADD
 *
 * 返回：
 *   返回用户输入的内容（非空）
 *   若 readOk 变 false，则返回空字符串（上层会直接 return）
 */
static std::string askNonEmptyField(const std::string &prompt, bool &readOk)
{
    std::string value;

    while (readOk)
    {
        std::cout << prompt;

        if (!readTrimmedLine(value))
        {
            // 读入失败（EOF），通知上层停止
            readOk = false;
            break;
        }

        // trim 后不为空，成功
        if (!value.empty())
            return value;

        // 否则继续询问
        std::cout << "Empty field is not allowed. Please try again.\n";
    }
    return "";
}

/*
 * 函数：addContact（对应命令 ADD）
 * 作用：
 *   读 5 个字段（不能为空），存入 contacts 数组。
 *   如果已经满 8 个，则覆盖最旧（环形覆盖）。
 */
void PhoneBook::addContact(void)
{
    bool        readOk;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    Contact     newContact;

    // readOk 用来记录：是否还能继续读取输入（是否遇到 EOF）
    readOk = true;

    // 依次询问 5 个字段（不能为空）
    firstName = askNonEmptyField("First name: ", readOk);
    lastName = askNonEmptyField("Last name: ", readOk);
    nickname = askNonEmptyField("Nickname: ", readOk);
    phoneNumber = askNonEmptyField("Phone number: ", readOk);
    darkestSecret = askNonEmptyField("Darkest secret: ", readOk);

    // 如果中途 EOF，直接返回，不保存半成品
    if (!readOk)
        return;

    // 把字段写入 Contact 对象，并标记 hasValue=true
    newContact.setAll(firstName, lastName, nickname, phoneNumber, darkestSecret);

    // 把新联系人放入数组指定位置
    this->contacts[this->nextWriteIndex] = newContact;

    // savedCount 最多 8
    if (this->savedCount < 8)
        this->savedCount = this->savedCount + 1;

    // 环形覆盖关键：下一次写入位置往后走一格，满了回到 0
    this->nextWriteIndex = (this->nextWriteIndex + 1) % 8;
}

/*
 * ====== 工具函数：parseSingleDigit ======
 * 作用：
 *   把用户输入的字符串解析成“一个数字”，只接受 1 位数字 '0'~'9'
 *   因为电话本最多 8 个，所以够用。
 *
 * 参数：
 *   text：用户输入
 *   numberOut：输出参数，成功则写入解析出的数字
 *
 * 返回：
 *   true：成功解析
 *   false：解析失败
 */
static bool parseSingleDigit(const std::string &text, int &numberOut)
{
    if (text.size() != 1)
        return false;
    if (text[0] < '0' || text[0] > '9')
        return false;

    numberOut = (int)(text[0] - '0');
    return true;
}

/*
 * 函数：searchAndPrint（对应命令 SEARCH）
 * 作用：
 *   1) 如果电话本为空，提示并返回
 *   2) 打印表格列表（index/first/last/nickname）
 *   3) 询问用户输入 index
 *   4) 输入合法则打印该联系人的完整信息
 *
 * const：
 *   SEARCH 不应该修改电话本，所以加 const。
 */
void PhoneBook::searchAndPrint(void) const
{
    int         i;
    std::string inputLine;
    int         chosenIndex;

    // 如果没有任何联系人
    if (this->savedCount == 0)
    {
        std::cout << "Your phone book is empty.\n";
        return;
    }

    // 打印表头（分隔线 + 列名）
    std::cout << "|-------------------------------------------|\n";
    std::cout << "|     Index|First name| Last name|  Nickname|\n";
    std::cout << "|-------------------------------------------|\n";

    // 打印每一个联系人（0 到 savedCount-1）
    i = 0;
    while (i < this->savedCount)
    {
        this->contacts[i].printTableRow(i);
        std::cout << "|-------------------------------------------|\n";
        i = i + 1;
    }

    // 反复让用户输入 index，直到输入合法或 EOF
    while (true)
    {
        std::cout << "Choose an index (0 to " << (this->savedCount - 1) << "): ";

        // 读取一行（trim 后）
        if (!readTrimmedLine(inputLine))
            return;

        // 解析并检查范围
        if (!parseSingleDigit(inputLine, chosenIndex) || !this->isIndexValid(chosenIndex))
        {
            std::cout << "Invalid index. Please try again.\n";
            continue;
        }

        // 合法：打印该联系人的完整信息
        this->contacts[chosenIndex].printFull();
        return;
    }
}
