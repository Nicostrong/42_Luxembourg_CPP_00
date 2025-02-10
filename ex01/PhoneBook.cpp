/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 14:53:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "PhoneBook_Class.hpp"
#include "Contact_class.hpp"

/*
 *	Constructor PhoneBook
 */
PhoneBook::PhoneBook( void )
{
	if (PhoneBook::_nbr_contact == 0)
		std::cout << RED << "*** PhoneBook is empty ***" << RESET << std::endl;
	for(int i = 0; i < PhoneBook::_max_contact; i++)
		PhoneBook::contacts[i];
	return ;
}

/*
 *	Destructor PhoneBook
 */
PhoneBook::~PhoneBook( void )
{
	std::cout << RED << "*** PhoneBook is destroyed ***" << RESET << std::endl;
}

/*
 *	Print the menu of the PhoneBook
 */
int	PhoneBook::printMenu( void )
{
	std::string	buff;
	
	do
	{
		std::cout << YELLOW << "What do you want to do ?" << RESET << std::endl;
		std::cout << YELLOW << "ADD : add a new contact" << RESET << std::endl;
		std::cout << YELLOW << "SEARCH : search a contact" << RESET << std::endl;
		std::cout << YELLOW << "EXIT : exit the program" << RESET << std::endl;
		std::cin >> buff;
		std::cin.clear();
	} while (buff != "ADD" && buff != "SEARCH" && buff != "EXIT");
	if (buff == "ADD")
		return (1);
	else if (buff == "SEARCH")
		return (2);
	else
		return (3);
}
