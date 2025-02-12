/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/12 12:09:03 by nfordoxc         ###   Luxembourg.lu     */
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
 *	Static methode
 */

	/*
	 *	get _nbAccounts
	 */
int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

	/*
	 *	get _totalAmount
	 */
int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

	/*
	 *	get _totalNbDeposits
	 */
int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

	/*
	 *	get _totalNbWithdrawals
	 */
int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

	/*
	 *	display all accounts informations
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
 *	make deposit methode
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
 *	make withdrawal methode
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
 *	check of amount methode
 */
int	Account::checkAmount( void ) const
{
	return (_amount);
}

/*
 *	displey the status account methode
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
 *	display the timestamp
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