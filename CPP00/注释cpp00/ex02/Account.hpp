#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

// 题目给的头文件（接口）
// 你需要在 Account.cpp 里实现这些函数，并维护这些成员变量。

class Account
{
public:
	// typedef：给类型起别名
	// 这里把 Account 取别名叫 t
	// tests.cpp 里用 Account::t 来表示 Account
	typedef Account		t;

	// ===== 静态函数（属于“类”，不属于某个对象）=====
	// 你可以理解成“全班共用的数据/功能”
	static int	getNbAccounts( void );      // 账户总数
	static int	getTotalAmount( void );     // 所有账户余额总和
	static int	getNbDeposits( void );      // 所有账户存款次数总和
	static int	getNbWithdrawals( void );   // 所有账户取款次数总和

	// 打印全局信息（accounts/total/deposits/withdrawals）
	static void	displayAccountsInfos( void );

	// ===== 构造/析构 =====
	// 创建对象时自动调用构造函数
	Account( int initial_deposit );
	// 对象销毁时自动调用析构函数
	~Account( void );

	// ===== 普通成员函数（属于“某个账户对象”）=====
	void	makeDeposit( int deposit );           // 存款
	bool	makeWithdrawal( int withdrawal );     // 取款（可能拒绝）
	int		checkAmount( void ) const;            // 查看余额（只读）
	void	displayStatus( void ) const;          // 打印该账户状态（只读）

private:
	// 私有默认构造：不允许外部写 Account a; 必须给初始存款
	Account( void );

	// 打印时间戳：[YYYYMMDD_HHMMSS] （log 里就这种格式）
	static void	_displayTimestamp( void );

	// ===== 静态成员变量（全局统计，共用一份）=====
	static int	_nbAccounts;         // 账户总数
	static int	_totalAmount;        // 总金额
	static int	_totalNbDeposits;    // 总存款次数
	static int	_totalNbWithdrawals; // 总取款次数

	// ===== 每个账户对象自己的数据（每个对象一份）=====
	int				_accountIndex;   // 账户编号（通常从 0 开始递增）
	int				_amount;         // 当前账户余额
	int				_nbDeposits;     // 该账户存款次数
	int				_nbWithdrawals;  // 该账户取款次数
};

#endif
