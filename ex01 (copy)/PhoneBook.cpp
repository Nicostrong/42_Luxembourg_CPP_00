/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 11:24:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "PhoneBook_Class.hpp"
#include "Contact_class.hpp"

int	PhoneBook::_nbr_contact = 0;

/*
 *	Constructor PhoneBook
 */
PhoneBook::PhoneBook( void )
{
	if (PhoneBook::_nbr_contact == 0)
		std::cout << RED << "*** PhoneBook is empty ***" << RESET << std::endl;
	for(int i = 0; i < PhoneBook::_max_contact; i++)
		PhoneBook::contacts[i] = NULL;
	return ;
}

/*
 *	Destructor PhoneBook
 */
PhoneBook::~PhoneBook( void )
{
	for(int i = 0; i < PhoneBook::_max_contact; i++)
		delete PhoneBook::contacts[i];
	PhoneBook::_nbr_contact = 0;
	std::cout << RED << "*** PhoneBook is destroyed ***" << RESET << std::endl;
}

/*
 *	get the number of contact on the phonebook
 */
int PhoneBook::getNbrContact( void )
{
	return (PhoneBook::_nbr_contact);
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

void	PhoneBook::printPhoneBook( void ) const
{
	std::cout	<< YELLOW << "---------------------------------------------" << RESET << std::endl;
	std::cout	<< YELLOW << "|     Index|      Name| Last Name|  Nickname|" << RESET << std::endl;
	std::cout	<< YELLOW << "---------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < PhoneBook::_max_contact; i++)
		PhoneBook::contacts[i]->printContactList(i);
	std::cout	<< YELLOW << "---------------------------------------------" << RESET << std::endl;
	return ;
}

void	PhoneBook::addContact( void )
{
	if (PhoneBook::_nbr_contact < PhoneBook::_max_contact)
	{
		contacts[_nbr_contact] = new Contact();
		contacts[_nbr_contact]->createContact(_nbr_contact);
		_nbr_contact++;
	}
	else
	{
		PhoneBook::_nbr_contact = 0;
		this->addContact();
	}
	return ;
}

void	PhoneBook::removeContact(int index )
{
	if (index < PhoneBook::_nbr_contact)
	{
		delete PhoneBook::contacts[index];
		for (int i = index; i < PhoneBook::_max_contact - 1; i++)
			PhoneBook::contacts[i] = PhoneBook::contacts[i + 1];
		PhoneBook::contacts[PhoneBook::_nbr_contact - 1] = NULL;
		PhoneBook::_nbr_contact--;
	}
	else
		std::cout << "*** Index not found ***" << std::endl;
	return ;
}

void	PhoneBook::searchContact( void ) const
{
	int			index;
	std::string	buff;

	if (PhoneBook::_nbr_contact == 0)
	{
		std::cout << "*** PhoneBook is empty ***" << std::endl;
		return;
	}
	do
	{
		std::cout << "Enter the index of the contact you want to see : ";
		std::cin >> buff;
		try
		{
			index = atoi(buff.c_str());
			if (index < 0 || index > PhoneBook::_nbr_contact)
			{
				std::cout 	<< "Invalid index. Please enter a number between 1 and "
							<< PhoneBook::_nbr_contact<< "." << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			index = -1;
		}
		std::cin.clear();
		std::cin.ignore();
	} while (index <= 0 || index > PhoneBook::_nbr_contact);
	contacts[index - 1]->printContact();
	return ;
}
