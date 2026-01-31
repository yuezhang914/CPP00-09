/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:28:13 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:33:46 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
    return;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts = Account::_nbAccounts + 1;
    Account::_totalAmount = Account::_totalAmount + this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";created\n";
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed\n";
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
    int previousAmount;

    previousAmount = this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << previousAmount << ";";

    this->_amount = this->_amount + deposit;
    this->_nbDeposits = this->_nbDeposits + 1;
    Account::_totalAmount = Account::_totalAmount + deposit;
    Account::_totalNbDeposits = Account::_totalNbDeposits + 1;

    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previousAmount;

    previousAmount = this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << previousAmount << ";";

    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused\n";
        return false;
    }

    this->_amount = this->_amount - withdrawal;
    this->_nbWithdrawals = this->_nbWithdrawals + 1;
    Account::_totalAmount = Account::_totalAmount - withdrawal;
    Account::_totalNbWithdrawals = Account::_totalNbWithdrawals + 1;

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm      *timeParts;

    now = std::time(NULL);
    timeParts = std::localtime(&now);

    std::cout << "[";
    std::cout << (timeParts->tm_year + 1900);
    std::cout << std::setw(2) << std::setfill('0') << (timeParts->tm_mon + 1);
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << timeParts->tm_sec;
    std::cout << "] ";

    // Avoid surprising later output formatting.
    std::cout << std::setfill(' ');
}
