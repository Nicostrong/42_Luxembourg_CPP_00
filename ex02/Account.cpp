/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/12 15:26:09 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
 *	Initialisation static variables
 */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
 *	Constructor
 */
Account::Account( int initial_deposit ) :	_accountIndex(_nbAccounts), \
											_amount(initial_deposit), \
											_nbDeposits(0), \
											_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
 *	Destructor
 */
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
 *	Static methode for static variables shared with all instance of Account
 */

	/*
	 *	getNbAccounts returns the number of accounts
	 */
int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

	/*
	 *	getTotalAmount returns the total amount of all accounts
	 */
int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

	/*
	 *	getNbDeposits returns the total number of deposits
	 */
int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

	/*
	 *	getNbWithdrawals returns the total number of withdrawals
	 */
int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

	/*
	 *	display all informations of all accounts
	 */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts \
				<< ";total:" << _totalAmount \
				<< ";deposits:" << _totalNbDeposits \
				<< ";withdrawals:" << _totalNbWithdrawals \
				<< std::endl;
}

/*
 *	makeDeposit add the deposit to the account
 */
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex \
				<< ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< ";amount:" << _amount \
				<< ";deposit:" << deposit \
				<< ";nb_deposits:" << _nbDeposits \
				<< std::endl;
}

/*
 *	makeWthdrawal soustract the withdrawal to the account if it's possible.
 *	return true if the withdrawal is possible, false otherwise.
 */
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex \
				<< ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout	<< ";withdrawal:refused" \
					<< std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< ";withdrawal:" << withdrawal \
				<< ";amount:" << _amount \
				<< ";nb_withdrawals:" << _nbWithdrawals \
				<< std::endl;
	return (true);
}

/*
 *	checkAmount check the amount of the account
 */
int	Account::checkAmount( void ) const
{
	return (_amount);
}

/*
 *	displeyStatus show the status of the account
 */
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals \
				<< std::endl;
}

/*
 *	displayTimestamp put the timestamp in the output in format [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp( void )
{
	std::time_t	now;
	std::tm		*ltm;
	
	now = std::time(NULL);
	ltm = std::localtime(&now);
	std::cout	<< "[" << 1900 + ltm->tm_year \
				<< (ltm->tm_mon + 1 < 10 ? "0" : "") << (ltm->tm_mon + 1) \
				<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday \
				<< "_" \
				<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour \
				<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min \
				<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec \
				<< "] ";
}