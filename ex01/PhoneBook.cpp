/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/03 16:57:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook_Class.hpp"
#include "Contact_class.hpp"

int	PhoneBook::_nbr_contact = 0;

PhoneBook::PhoneBook( void )
{
	if (PhoneBook::_nbr_contact == 0)
		std::cout << BLUE << "*** PhoneBook is empty ***" << RESET << std::endl;
	for(int i = 0; i < 8; i++)
		PhoneBook::contacts[i] = nullptr;
}

PhoneBook::~PhoneBook( void )
{
	for(int i = 0; i < 8; i++)
		delete PhoneBook::contacts[i];
	PhoneBook::_nbr_contact = 0;
	std::cout << RED << "*** PhoneBook is destroyed ***" << RESET << std::endl;
}

int PhoneBook::getNbrContact( void )
{
	return (PhoneBook::_nbr_contact);
}

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
	for (int i = 0; i < PhoneBook::_nbr_contact; i++)
		PhoneBook::contacts[i]->printContactList(i);
	std::cout	<< YELLOW << "---------------------------------------------" << RESET << std::endl;
}

void	PhoneBook::addContact( void )
{
	if (PhoneBook::_nbr_contact < 8)
	{
		contacts[_nbr_contact] = new Contact();
		contacts[_nbr_contact]->createContact(_nbr_contact);
		_nbr_contact++;
	}
	else
		std::cout << "*** PhoneBook is full ***" << std::endl;
}

void	PhoneBook::removeContact(int index )
{
	if (index < PhoneBook::_nbr_contact)
	{
		delete PhoneBook::contacts[index];
		for (int i = index; i < PhoneBook::_nbr_contact - 1; i++)
			PhoneBook::contacts[i] = PhoneBook::contacts[i + 1];
		PhoneBook::contacts[PhoneBook::_nbr_contact - 1] = nullptr;
		PhoneBook::_nbr_contact--;
	}
	else
		std::cout << "*** Index not found ***" << std::endl;
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
			index = std::stoi(buff);
			if (index < 0 || index > PhoneBook::_nbr_contact)
			{
				std::cout 	<< "Invalid index. Please enter a number between 0 and "
							<< PhoneBook::_nbr_contact<< "." << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			index = -1;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (index <= 0 || index > PhoneBook::_nbr_contact);
	contacts[index - 1]->printContact();
}
