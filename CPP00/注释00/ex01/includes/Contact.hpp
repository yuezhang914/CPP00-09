#ifndef CONTACT_HPP
#define CONTACT_HPP

// string：C++ 的字符串类型（比 C 的 char* 更安全好用）
#include <string>

/*
 * 类：Contact（联系人）
 * 作用：
 *   存储一个联系人需要的 5 个字段（名字、电话等），并负责打印自己：
 *   - 表格的一行（用于 SEARCH 的列表）
 *   - 完整信息（用于选中 index 后展示）
 *
 * 为什么要用 class？
 *   你可以把它理解成 C 语言的 struct + 一组专属函数，打包在一起。
 *
 * private / public 是什么？
 *   - private：外部不能直接改（保护数据，避免乱改导致错误）
 *   - public：外部能调用的“按钮/接口”
 */
class Contact
{
private:
    // ===== 5 个字段 =====
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    // hasValue：这个联系人“是否真的存过数据”
    // 因为 PhoneBook 会有固定数组 contacts[8]，
    // 数组一创建就会有 8 个 Contact 对象，
    // 但一开始它们是“空联系人”，用 hasValue 区分。
    bool        hasValue;

public:
    /*
     * 构造函数 Contact()
     * 作用：创建一个“空联系人”（字段为空、hasValue=false）
     * 参数：无
     * 返回：无
     */
    Contact(void);

    /*
     * 析构函数 ~Contact()
     * 作用：对象销毁时自动调用（这里没有特别资源要释放，所以是空的）
     * 参数：无
     * 返回：无
     */
    ~Contact(void);

    /*
     * isEmpty
     * 作用：判断这个联系人是否为空（还没保存过）
     * 参数：无
     * 返回：true 表示空；false 表示有数据
     *
     * const 的意思：
     *   这个函数保证不会修改 Contact 里的成员变量（只读）。
     */
    bool isEmpty(void) const;

    /*
     * setAll
     * 作用：一次性把 5 个字段都存进去，并标记 hasValue=true
     * 参数：
     *   newFirstName/newLastName/newNickname/newPhoneNumber/newDarkestSecret
     * 返回：无
     *
     * 为什么参数是 const std::string&？
     *   - & 表示引用：不复制一份大字符串，省时间省内存
     *   - const 表示我不会改传进来的字符串
     */
    void setAll(
        const std::string &newFirstName,
        const std::string &newLastName,
        const std::string &newNickname,
        const std::string &newPhoneNumber,
        const std::string &newDarkestSecret);

    /*
     * printTableRow
     * 作用：按题目要求打印“表格的一行”
     * 参数：
     *   index：这个联系人在电话本里的编号（0~7）
     * 返回：无
     *
     * 输出形式（大概）：
     * |         0|FirstName..| LastName..|  Nickname|
     */
    void printTableRow(int index) const;

    /*
     * printFull
     * 作用：打印该联系人的全部字段（选中 index 后展示详情）
     * 参数：无
     * 返回：无
     */
    void printFull(void) const;
};

#endif
