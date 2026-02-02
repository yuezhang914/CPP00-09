// =========================
// 文件用途：tests.cpp
// 作用：题目提供的“测试程序”
//      它会：
//      1) 创建一组 Account 账户（用给定的初始金额）
//      2) 打印全局信息 + 每个账户状态
//      3) 给每个账户存一次钱
//      4) 再打印全局信息 + 每个账户状态
//      5) 给每个账户取一次钱（可能会被拒绝）
//      6) 再打印全局信息 + 每个账户状态
//
// 你要做的不是改它，而是：
// 让你写的 Account.cpp 输出和 log 一致（除了时间戳）。
// =========================

// 这段 tests.cpp 在做什么？”（一句话版）

// 中文：它用 vector 保存 8 个账户，然后用 for_each + mem_fun_ref 打印每个账户状态，
// 再用 pair<iterator, iterator> 同步遍历账户和金额数组，
// 分别调用 makeDeposit 和 makeWithdrawal。

// 英文：It stores 8 accounts in a vector, 
// prints each status with for_each + mem_fun_ref, 
// then iterates accounts and amounts in parallel 
// using a pair of iterators to call makeDeposit and makeWithdrawal.



// vector：C++ 标准库里的“动态数组容器”（可以自动变长）
// 这个文件里用它来存一组 Account 和一组 int（存款/取款数）
#include <vector>

// algorithm：标准库算法，如 for_each（对一段范围内的每个元素做同一件事）
#include <algorithm>

// functional：函数对象/适配器，如 mem_fun_ref（把成员函数变成可传给算法的“可调用东西”）
#include <functional>

// 你实现的类接口（Account.hpp）
// tests.cpp 会调用 Account::displayAccountsInfos / displayStatus / makeDeposit / makeWithdrawal
#include "Account.hpp"


/*
 * 函数：main
 * 作用：测试 Account 类是否实现正确。
 *
 * 你可以把它理解为：题目官方的“自动评测脚本”（只是写成了 C++ 代码）。
 */
int main( void ) {

    // ===== 1) 下面三行 typedef 是“起别名”，让后面的类型更短更好写 =====

    // accounts_t：表示“装 Account 的 vector”
    // Account::t 是 Account.hpp 里 typedef 的别名（t 就是 Account）
    // 所以 accounts_t 等价于：std::vector<Account>
    typedef std::vector<Account::t>                              accounts_t;

    // ints_t：表示“装 int 的 vector”
    typedef std::vector<int>                                     ints_t;

    // acc_int_t：pair（一对东西）
    // 里面装两个迭代器：一个指向 accounts 的当前位置，一个指向 ints 的当前位置
    // 这样就能“同时走两个数组”（账户和对应的存款/取款数）
    typedef std::pair<accounts_t::iterator, ints_t::iterator>    acc_int_t;

    // ===== 2) 创建 8 个账户：初始金额数组 amounts =====

    // C 语言风格的数组：有 8 个初始余额
    int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };

    // amounts_size：数组长度（元素个数）
    // sizeof(amounts) 是整个数组占多少字节
    // sizeof(int) 是一个 int 占多少字节
    // 两者相除就是元素个数
    size_t const amounts_size( sizeof(amounts) / sizeof(int) );

    // accounts：用区间构造创建 vector
    // accounts(amounts, amounts + amounts_size) 的意思：
    //   把 amounts[0] 到 amounts[amounts_size-1] 这段数据复制进去，
    //   并把每个 int 当作 Account 的构造参数（调用 Account(int initial_deposit)）
    //
    // 换句话说：这里会创建 8 个 Account 对象，每个用不同初始金额。
    accounts_t accounts( amounts, amounts + amounts_size );

    // 迭代器 iterator：你可以把它理解为“指针升级版”
    // begin() 指向第一个元素，end() 指向最后一个元素的后面（不能解引用）
    accounts_t::iterator acc_begin = accounts.begin();
    accounts_t::iterator acc_end   = accounts.end();

    // ===== 3) 存款数据 deposits：每个账户对应一次存款 =====

    int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
    size_t const d_size( sizeof(d) / sizeof(int) );

    // deposits：把数组 d 的内容拷贝到 vector 里
    ints_t deposits( d, d + d_size );
    ints_t::iterator dep_begin = deposits.begin();
    ints_t::iterator dep_end   = deposits.end();

    // ===== 4) 取款数据 withdrawals：每个账户对应一次取款 =====

    int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
    size_t const w_size( sizeof(w) / sizeof(int) );

    ints_t withdrawals( w, w + w_size );
    ints_t::iterator wit_begin = withdrawals.begin();
    ints_t::iterator wit_end   = withdrawals.end();

    // ===== 5) 第一轮：打印全局信息 + 每个账户状态 =====

    // 静态函数：属于 Account 类本身，不需要对象就能调用
    Account::displayAccountsInfos();

    // std::for_each(开始, 结束, 要做的事)
    // 作用：对 [acc_begin, acc_end) 里的每个 Account 都做一件事
    //
    // std::mem_fun_ref(&Account::displayStatus)：
    // 作用：把“成员函数 displayStatus”包装成一个可传给 for_each 的东西
    // 意思是：对每个 Account 对象调用一次它的 displayStatus()
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    // ===== 6) 第二轮：给每个账户存钱 =====
    //
    // 这里用 for 循环（题目作者写的，你不用改）
    // acc_int_t it(acc_begin, dep_begin)：
    //   it.first  指向 accounts 当前账户
    //   it.second 指向 deposits 当前存款金额
    //
    // 循环条件：
    //   it.first != acc_end  表示账户没走完
    //   it.second != dep_end 表示存款数组没走完
    // 两个都没走完才继续（防止越界）
    for ( acc_int_t it( acc_begin, dep_begin );
          it.first != acc_end && it.second != dep_end;
          ++(it.first), ++(it.second) ) {

        // (*(it.first))：拿到当前 Account 对象
        // (*(it.second))：拿到当前存款金额 int
        // 调用 makeDeposit(存款金额)
        (*(it.first)).makeDeposit( *(it.second) );
    }

    // 存完钱后，再打印一次全局信息 + 每个账户状态
    Account::displayAccountsInfos();
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    // ===== 7) 第三轮：给每个账户取钱（可能被拒绝）=====
    for ( acc_int_t it( acc_begin, wit_begin );
          it.first != acc_end && it.second != wit_end;
          ++(it.first), ++(it.second) ) {

        // 调用 makeWithdrawal(取款金额)
        // 如果取款金额大于余额，你的 Account.cpp 应该输出 "withdrawal:refused"
        (*(it.first)).makeWithdrawal( *(it.second) );
    }

    // 取完钱后，再打印一次全局信息 + 每个账户状态
    Account::displayAccountsInfos();
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    return 0;
}
