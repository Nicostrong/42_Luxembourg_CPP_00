/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/11 15:45:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_Class.hpp"

int	PhoneBook::_nbr_contact = 0;

/*
 *	Constructor PhoneBook
 */
PhoneBook::PhoneBook( void ) : _oldest_index(0)
{
#ifdef DEBUG
	std::cout << BLUE << "*** PhoneBook is created ***" << RESET << std::endl;
#endif
	return ;
}

/*
 *	Destructor PhoneBook
 */
PhoneBook::~PhoneBook( void )
{
#ifdef DEBUG
	std::cout << RED << "*** PhoneBook is destroyed ***" << RESET << std::endl;
#endif
	return ;
}

/*
 *	check if the input is only digit and no empty
 */
bool	isNumber( const std::string& input)
{
	for (size_t i = 0; i < input.length(), i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return !input.empty();
}

/*
 *	addContact add a new contact on the phonebooj
 */
void	PhoneBook::addContact( void )
{
	int			index;
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	phone;
	std::string	secret;

	std::cout << YELLOW << "ADD new contact" << RESET << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, f_name);
	std::cout << "Last name: ";
	std::getline(std::cin, l_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, n_name);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);

	if (f_name.empty() || l_name.empty() || n_name.empty() || phone.empty() || \
		secret.empty())
	{
		std::cout << RED << "Error: Empty field" << RESET << std::endl;
		return ;
	}

	index = (_nbr_contact < _max_contact) ? _nbr_contact : _oldest_index;
	_contacts[index].setContact(index, f_name, l_name, n_name, phone, secret);
	if (_nbr_contact < _max_contact)
		_nbr_contact++;
	else
		_oldest_index = (_oldest_index + 1) % _max_contact;
	std::cout << GREEN << "Contact added" << RESET << std::endl;
	return ;
}

/*
 *	searchContact search a contact on the phonebook
 */
void	PhoneBook::searchContact( void ) const
{
	std::string	input;
	int			index;

	if (_nbr_contact == 0)
	{
		std::cout << RED << "No contact on phonebook" << RESET << std::endl;
		return ;
	}
	printContacts();
	std::cout << "Enter the index of the contact you want to display: ";
	std::getline(std::cin, input);
	try
	{
		index = std::stoi(input);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error: Invalid index" << RESET << std::endl;
		return ;
	}
	displayContact(index);
	return ;
}

/*
 *	displayContact display a contact on the phonebook
 */
void	PhoneBook::displayContact( int index ) const
{
	if (index < 0 || index >= _nbr_contact)
	{
		std::cout << RED << "Error: Invalid index" << RESET << std::endl;
		return ;
	}
	std::cout << BLUE;
	std::cout << "Contact " << index << std::endl;
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret();
	std::cout << RESET << std::endl;
	return ;
}

/*
 *	printContacts print all the contacts on the phonebook
 */
void	PhoneBook::printContacts( void ) const
{
	std::cout	<< std::setw(10) << "index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i< _nbr_contact; i++)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << (_contacts[i].getFirstName().length() > 10 ? 
						_contacts[i].getFirstName().substr(0, 9) + "." : 
						_contacts[i].getFirstName()) << "|"
					<< std::setw(10) << (_contacts[i].getLastName().length() > 10 ? 
						_contacts[i].getLastName().substr(0, 9) + "." : 
						_contacts[i].getLastName()) << "|"
					<< std::setw(10) << (_contacts[i].getNickname().length() > 10 ? 
						_contacts[i].getNickname().substr(0, 9) + "." : 
						_contacts[i].getNickname()) << "|"
					<< std::endl;
	}
	return ;
}
