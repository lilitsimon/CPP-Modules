#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
	if (_amount < withdrawal)
	{
		std::cout << "Refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";amount" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *localTime = std::localtime(&now);
	std::cout << "[" << (1900 + localTime->tm_year);
	if (localTime->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (localTime->tm_mon + 1);
	if (localTime->tm_mday < 10)
		std::cout << "0";
	std::cout << (localTime->tm_mday);
	std::cout << "_";
	if (localTime->tm_hour < 10)
		std::cout << "0";
	std::cout << (localTime->tm_hour);
	if (localTime->tm_min < 10)
		std::cout << (localTime->tm_min);
	std::cout << (localTime->tm_min);
	if (localTime->tm_sec < 10)
		std::cout << "0";
	std::cout << (localTime->tm_sec);
	std::cout << "]";
	std::cout << " ";
}
