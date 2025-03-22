/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:37 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/22 09:01:08 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * Constructor for the Account class.
 *
 * This constructor initializes a new account with a specified initial deposit.
 * It assigns a unique index to the account, sets the initial amount, and initializes
 * the number of deposits and withdrawals to zero. It also increments the total number
 * of accounts and updates the total amount held in all accounts. The current timestamp
 * is displayed along with the account index and amount upon creation.
 *
 * @param initial_deposit The initial amount deposited into the account.
 */
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/**
 * Default constructor for the Account class.
 *
 * This constructor initializes an account with a zero balance, and
 * assigns a unique index to the account. It also increments the total
 * number of accounts. The current timestamp is displayed along with the
 * account index and amount upon creation.
 */
Account::Account(void) : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/**
 * Destructor for the Account class.
 *
 * This destructor outputs the current timestamp, account index, and amount
 * before the account is closed. It ensures that any necessary cleanup
 * operations or logging are performed when an account object is destroyed.
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/**
 * Returns the total number of accounts currently existing.
 *
 * This method returns the total number of accounts existing, which is
 * incremented by the constructor and decremented by the destructor.
 *
 * @return The total number of accounts.
 */
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

/**
 * Returns the total amount of all existing accounts.
 *
 * This method returns the total amount stored in all existing accounts,
 * which is updated by the constructor and by the makeDeposit and
 * makeWithdrawal methods.
 *
 * @return The total amount of all accounts.
 */
int Account::getTotalAmount(void)
{
	return _totalAmount;
}

/**
 * Returns the total number of deposits that have been made to all existing accounts.
 *
 * This method returns the total number of deposits that have been made to all existing
 * accounts, which is incremented by the makeDeposit method.
 *
 * @return The total number of deposits.
 */
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

/**
 * Returns the total number of withdrawals that have been made from all existing accounts.
 *
 * This method returns the total number of withdrawals that have been made from all existing
 * accounts, which is incremented by the makeWithdrawal method.
 *
 * @return The total number of withdrawals.
 */
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

/**
 * Displays information about all accounts.
 *
 * This method outputs the total number of accounts, the total amount of money
 * in all accounts, and the total number of deposits and withdrawals across
 * all accounts. It also includes a timestamp for when the information is displayed.
 */
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/**
 * Makes a deposit into the account.
 *
 * This method adds the specified deposit amount to the account balance and
 * increments the number of deposits. It also updates the total amount and
 * total number of deposits across all accounts. The current timestamp is
 * included in the output.
 *
 * @param deposit The amount to deposit.
 */
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * Makes a withdrawal from the account.
 *
 * This method subtracts the specified withdrawal amount from the account balance
 * and increments the number of withdrawals. It also updates the total amount and
 * total number of withdrawals across all accounts. If the withdrawal amount exceeds
 * the account balance, the withdrawal is refused and the method returns false.
 * Otherwise, the method returns true. The current timestamp is included in the
 * output.
 *
 * @param withdrawal The amount to withdraw.
 * @return True if the withdrawal is successful, false if the withdrawal is refused.
 */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

/**
 * Returns the current balance of the account.
 *
 * This method returns the current balance of the account.
 *
 * @return The current balance of the account.
 */
int Account::checkAmount(void) const
{
	return _amount;
}

/**
 * Displays the current status of the account.
 *
 * This method displays the current status of the account, including the current
 * balance, number of deposits, and number of withdrawals. The current timestamp
 * is included in the output.
 */
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/**
 * Outputs the current timestamp in the format "YYYYMMDD_HHMMSS".
 *
 * This method is used to generate the timestamp that is included in the output
 * of many of the Account class methods. The timestamp is generated using the
 * time() and localtime() functions from the <ctime> library, and is formatted
 * using the strftime() function. The timestamp is output to the console followed
 * by a space.
 */
void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	struct tm *tm = localtime(&now);
	char buffer[16];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);
	std::cout << "[" << buffer << "] ";
}
