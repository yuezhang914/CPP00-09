// =========================
// 文件用途：
//   实现 Account.hpp 里声明的所有函数。
//   目标：让 tests.cpp 输出（除时间戳外）匹配题目给的 log。
// =========================

#include "Account.hpp"

// iostream：用 std::cout 输出（题目禁止 printf）
#include <iostream>

// iomanip：用 std::setw / std::setfill 做“补零”与固定宽度输出（时间戳会用）
#include <iomanip>

// ctime：获取当前时间（time/localtime/tm）
#include <ctime>

// ====== 静态成员变量的“定义” ======
// 头文件里只是“声明”，真正分配内存并初始化必须在某个 .cpp 里做。
// 否则会出现链接错误（undefined reference）。
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// 私有默认构造（题目不让外部用，但为了类完整可以实现）
Account::Account(void)
{
    return;
}

/*
 * 构造函数：Account::Account(int initial_deposit)
 * 作用：
 *   创建一个账户对象，并：
 *   1) 给它一个编号（index）
 *   2) 设置初始余额
 *   3) 更新“全局统计”（静态变量）
 *   4) 按 log 格式打印 "created" 行
 *
 * 参数：
 *   initial_deposit：初始存款金额（余额起点）
 */
Account::Account(int initial_deposit)
{
    // 给新账户编号：用当前总账户数作为 index（例如第一个是 0）
    this->_accountIndex = Account::_nbAccounts;

    // 设置余额为初始存款
    this->_amount = initial_deposit;

    // 新账户刚创建时，存取次数都是 0
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    // ===== 更新全局统计（所有账户共享的那份数据）=====
    // 账户总数 +1
    Account::_nbAccounts = Account::_nbAccounts + 1;

    // 全部账户总金额 += 这个新账户的余额
    Account::_totalAmount = Account::_totalAmount + this->_amount;

    // 打印时间戳（形如：[20260202_153012] ）
    Account::_displayTimestamp();

    // 按题目 log 的格式打印 created 行
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";created\n";
}

/*
 * 析构函数：Account::~Account()
 * 作用：
 *   对象销毁时打印 "closed" 行。
 * 注意：
 *   subject 里提醒：析构调用顺序可能因实现不同而不同。
 */
Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed\n";
}

/*
 * 静态函数：getNbAccounts
 * 作用：返回当前账户总数（全局共享）
 */
int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

/*
 * 静态函数：getTotalAmount
 * 作用：返回所有账户余额总和
 */
int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

/*
 * 静态函数：getNbDeposits
 * 作用：返回所有账户存款次数总和
 */
int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

/*
 * 静态函数：getNbWithdrawals
 * 作用：返回所有账户取款次数总和
 */
int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

/*
 * 静态函数：displayAccountsInfos
 * 作用：
 *   打印全局信息：accounts/total/deposits/withdrawals
 *   格式必须对齐 log（除时间戳）
 */
void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

/*
 * 成员函数：displayStatus（const）
 * 作用：
 *   打印当前账户对象的状态（index/amount/deposits/withdrawals）
 * const：
 *   表示这个函数只读，不会修改账户数据。
 */
void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}

/*
 * 成员函数：makeDeposit
 * 作用：
 *   给当前账户存钱，并更新：
 *   - 当前账户余额与存款次数
 *   - 全局总金额与总存款次数
 *   然后按 log 格式打印存款日志
 *
 * 参数：
 *   deposit：存入金额
 */
void Account::makeDeposit(int deposit)
{
    int previousAmount;

    // 保存存款前余额（log 需要打印 p_amount）
    previousAmount = this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << previousAmount << ";";

    // ===== 更新当前账户 =====
    this->_amount = this->_amount + deposit;
    this->_nbDeposits = this->_nbDeposits + 1;

    // ===== 更新全局统计 =====
    Account::_totalAmount = Account::_totalAmount + deposit;
    Account::_totalNbDeposits = Account::_totalNbDeposits + 1;

    // 按 log 格式输出
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

/*
 * 成员函数：makeWithdrawal
 * 作用：
 *   尝试取钱：
 *   - 如果 withdrawal > 当前余额：拒绝（refused），不修改任何统计，返回 false
 *   - 否则：扣钱并更新统计，打印日志，返回 true
 *
 * 参数：
 *   withdrawal：取款金额
 *
 * 返回：
 *   true  = 成功取款
 *   false = 被拒绝
 */
bool Account::makeWithdrawal(int withdrawal)
{
    int previousAmount;

    // 取款前余额
    previousAmount = this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << previousAmount << ";";

    // 如果取的钱比余额还多，不能让余额变负数，所以拒绝
    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused\n";
        return false;
    }

    // ===== 更新当前账户 =====
    this->_amount = this->_amount - withdrawal;
    this->_nbWithdrawals = this->_nbWithdrawals + 1;

    // ===== 更新全局统计 =====
    Account::_totalAmount = Account::_totalAmount - withdrawal;
    Account::_totalNbWithdrawals = Account::_totalNbWithdrawals + 1;

    // 按 log 格式输出
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}

/*
 * 成员函数：checkAmount（const）
 * 作用：返回当前账户余额
 * 为什么这样实现：
 *   函数名是 checkAmount（检查金额），最直观就是返回余额数值。
 */
int Account::checkAmount(void) const
{
    return this->_amount;
}

/*
 * 静态私有函数：_displayTimestamp
 * 作用：
 *   打印时间戳，格式是：
 *     [YYYYMMDD_HHMMSS] （后面带一个空格）
 *
 * 用到的新结构：std::tm
 *   tm_year：从 1900 开始算（例如 2026 年是 126）
 *   tm_mon ：0~11（0 代表 1 月）
 *   tm_mday：1~31
 *   tm_hour：0~23
 *   tm_min ：0~59
 *   tm_sec ：0~60
 *
 * 用到的新函数（ctime）：
 *   std::time(NULL)        -> 现在的时间（秒数）
 *   std::localtime(&now)   -> 把秒数转成本地时间结构 tm
 *
 * 用到的新工具（iomanip）：
 *   std::setw(2)           -> 宽度固定 2（比如 7 输出成 " 7"）
 *   std::setfill('0')      -> 不够宽用 '0' 填（" 7" 变 "07"）
 */
void Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm     *timeParts;

    // 获取当前时间（秒）
    now = std::time(NULL);

    // 把秒转换为“本地时间”的年月日时分秒结构
    timeParts = std::localtime(&now);

    // 开始输出：[YYYYMMDD_HHMMSS]
    std::cout << "[";

    // 年：tm_year 从 1900 开始，所以要 +1900 才是真实年份
    std::cout << (timeParts->tm_year + 1900);

    // 月：tm_mon 从 0 开始，所以 +1
    // setw(2)+setfill('0')：保证两位，例如 2 月输出 02
    std::cout << std::setw(2) << std::setfill('0') << (timeParts->tm_mon + 1);

    // 日：两位
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_mday;

    std::cout << "_";

    // 时：两位
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_hour;

    // 分：两位
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_min;

    // 秒：两位
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_sec;

    std::cout << "] ";

    // 重要：把填充字符恢复成空格，避免影响后续输出格式
    std::cout << std::setfill(' ');
}
