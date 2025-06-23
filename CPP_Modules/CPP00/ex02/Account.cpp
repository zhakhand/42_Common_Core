#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initialDeposit){
	if (initialDeposit < 0)
		throw std::invalid_argument("Negative Value!");
	_amount = initialDeposit;
	Account::_nbAccounts++;
	Account::_totalAmount += initialDeposit;
	Account::_totalNbDeposits++;
	_accountIndex = Account::_nbAccounts - 1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
				<< ";amount:" << _amount
				<< ";created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals
				<< "\n";
}

void Account::makeDeposit(int deposit) {
	if (deposit <= 0)
		throw std::invalid_argument("Deposited amount is less or equal 0!");
	_amount += deposit;
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > this->checkAmount())
		return false;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< "\n";
}

void Account::_displayTimestamp() {
	time_t now = time(NULL);
	tm *localTime = localtime(&now);
	std::cout << "[" << (1900 + localTime->tm_year)
				<< (localTime->tm_mon + 1 < 10 ? "0" : "") << localTime->tm_mon + 1
				<< (localTime->tm_mday < 10 ? "0" : "") << localTime->tm_mday
				<< "_" << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour
				<< (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min
				<< (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec << "] ";
}