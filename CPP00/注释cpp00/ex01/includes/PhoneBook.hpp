#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/*
 * 类：PhoneBook（电话本）
 * 作用：
 *   - 存储最多 8 个联系人（题目要求，且禁止 new 动态分配）
 *   - 支持 ADD / SEARCH 两个命令对应的功能
 *
 * 核心数据结构（非常重要）：
 *   contacts[8]      : 固定数组，最多 8 个
 *   savedCount       : 当前已经保存了多少个（0~8）
 *   nextWriteIndex   : 下一次 ADD 写到哪个格子（0~7，环形）
 *
 * 环形覆盖（题目要求第 9 个覆盖最老）怎么做？
 *   每次 ADD：
 *     contacts[nextWriteIndex] = 新联系人
 *     nextWriteIndex = (nextWriteIndex + 1) % 8
 *   这样写满后会回到 0，从最早的位置开始覆盖。
 */
class PhoneBook
{
private:
    Contact contacts[8];
    int     savedCount;
    int     nextWriteIndex;

public:
    /*
     * PhoneBook()
     * 作用：初始化一个空电话本
     * 参数：无
     * 返回：无
     */
    PhoneBook(void);

    /*
     * ~PhoneBook()
     * 作用：销毁电话本（这里不需要手动释放，因为没用 new）
     * 参数：无
     * 返回：无
     */
    ~PhoneBook(void);

    /*
     * addContact
     * 作用：
     *   交互式读取 5 个字段（不能为空），创建联系人并保存进数组。
     *   如果满了（8 个），会覆盖最老的。
     * 参数：无
     * 返回：无
     */
    void addContact(void);

    /*
     * searchAndPrint
     * 作用：
     *   先打印表格列表（index/first/last/nickname），再让用户输入 index，
     *   如果合法就打印该联系人的完整信息。
     * 参数：无
     * 返回：无
     *
     * const：
     *   SEARCH 不应该修改电话本，所以这是只读函数。
     */
    void searchAndPrint(void) const;

    /*
     * getSavedCount
     * 作用：返回当前保存了多少个联系人（0~8）
     */
    int  getSavedCount(void) const;

    /*
     * isIndexValid
     * 作用：判断 index 是否有效（必须在 [0, savedCount-1]）
     */
    bool isIndexValid(int index) const;
};

#endif
