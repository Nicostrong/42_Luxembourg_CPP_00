/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:24:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/03 16:58:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact_class.hpp"

/*
 *	Constructor of the class Contact
 */
Contact::Contact( void)
{
	std::cout << GREEN << "Contact constructor called." << RESET << std::endl;
	return ;
}

/*
 *	Destructor of the class Contact
 */
Contact::~Contact( void )
{
	std::cout << RED << "Contact destructor called." << RESET << std::endl;
	return ;
}

/*
 *	Format the lenght of the string to s characters
 */
std::string Contact::formatOutput(std::string str, size_t s)
{
	if (str.length() < s)
		str.insert(0, s - str.length(), ' ');
	else if (str.length() > s)
		str = str.substr(0, s - 1) + ".";
	return (str);
}

/*
 *	Get the string input of user empty string are not allowed
 */
std::string	Contact::getInput( void )
{
	std::string	buff;

	do
	{
		std::getline(std::cin, buff);
		if (buff.empty())
			std::cout << "Please enter a valid input: ";
	} while (buff.empty());
	return (buff);
}

/*
 *	Check the format of the phone number
 */
int	Contact::checkFormatPhoneNumber( std::string str )
{
	bool	hasdigit;

	hasdigit = false;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		char c = *it;
		if (!isdigit(c) && c != ' ' && c != '.' && c != '/')
			return (0);
		if (isdigit(c))
			hasdigit = true;
	}
	return (hasdigit ? 1 : 0);
}

/*
 *	Get the string input of user check no char just digit or ' ', '/', '.'
 */
std::string	Contact::getNumber( void )
{
	std::string input;
	bool valid;

	valid = false;
	do
	{
		input = this->getInput();
		if (this->checkFormatPhoneNumber(input))
			valid = true;
		else
			std::cout << "Please enter a valid number (digits, ' ', '.', or '/'): ";
	} while (!valid);
	return (input);
}

/*
 *	Ask to the user all informations to creat a new contact
 */
void Contact::createContact( int index )
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << GREEN << "Creating new contact." << RESET << std::endl;
	this->_index = index + 1;
	std::cout << GREEN <<"What's your first name ?" << RESET << std::endl;
	this->_first_name = getInput();
	std::cout <<  GREEN << "What's your last name ?" << RESET << std::endl;
	this->_last_name = getInput();
	std::cout << GREEN << "What's your nickname ?" << RESET << std::endl;
	this->_nickname = getInput();
	std::cout << GREEN << "What's your phone number ?" << RESET << std::endl;
	this->_phone_number = getNumber();
	std::cout << GREEN << "And finaly, what's your darkest secret ???" << RESET << std::endl;
	this->_darkest_secret = getInput();
	return ;
}

/*
 *	Print the contact information
 */
void	Contact::printContact( void ) const
{
	std::cout << GREEN << "Show contact." << RESET << std::endl;
	std::cout	<< BLUE << "Name :\n\t" << YELLOW << this->_first_name << "\n"
				<< BLUE << "Last name :\n\t" << YELLOW << this->_last_name << "\n"
				<< BLUE << "Nickname :\n\t" << YELLOW << this->_nickname << "\n"
				<< BLUE << "Phone number :\n\t" << YELLOW << this->_phone_number << "\n"
				<< BLUE << "Darkest secret :\n\t" << YELLOW << this->_darkest_secret << RESET << std::endl;

}

/*
 *	Print a list of contacts
 */
void Contact::printContactList( int index )
{
	std::cout	<< "|"
				<< BLUE << formatOutput(std::to_string(index + 1), 10) << RESET << "|"
				<< BLUE << formatOutput(this->_first_name, 10) << RESET << "|"
				<< BLUE << formatOutput(this->_last_name, 10) << RESET << "|"
				<< BLUE << formatOutput(this->_nickname, 10) << RESET << "|" << std::endl;
}

