/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:24:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 09:55:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sstream>
#include "Contact.hpp"

/*******************************************************************************
 *						CONSTRUCTOR / DESTRUCTOR							   *
 ******************************************************************************/

/*
 *	Constructor of the class Contact
 */
Contact::Contact(	int index, \
					const std::string& f_name, \
					const std::string& l_name, \
					const std::string& n_name, \
					const std::string& phone, \
					const std::string& secret) :	_index(index), \
													_first_name(f_name), \
													_last_name(l_name), \
													_nickname(n_name), \
													_phone_number(phone), \
													_darkest_secret(secret)
{
#ifdef DEBUG
	std::cout << "Contact constructor with all parameter called." << std::endl;
#endif
	return ;
}
/*
 *	Default constructor of the class Contact with default values
 */
Contact::Contact( void ) :	_index(0), \
							_first_name( "DOE" ), \
							_last_name( "JOHN" ), \
							_nickname( "JOHN DOE" ), \
							_phone_number( "+00/00.00.00.00.00"), \
							_darkest_secret( "Unknown person" )
{
#ifdef DEBUG
	std::cout << "Contact constructor with basic parameter called." << std::endl;
#endif
	return ;
}
/*
 *	Destructor of the class Contact
 */
Contact::~Contact( void )
{
#ifdef DEBUG
	std::cout << "Contact destructor called." << std::endl;
#endif
	return ;
}

/*******************************************************************************
 *								GETTER										   *
 ******************************************************************************/

/*
 *	getIndex returns the index of the contact
 */
int			Contact::getIndex( void ) const
{
	return (this->_index);
}

/*
 *	getFirstName returns the first name of the contact
 */
std::string	Contact::getFirstName( void ) const
{
	return (this->_first_name);
}

/*
 *	getLastName returns the last name of the contact
 */
std::string	Contact::getLastName( void ) const
{
	return (this->_last_name);
}

	/*
	 *	getNickname returns the nickname of the contact
	 */
std::string	Contact::getNickname( void ) const
{
	return (this->_nickname);
}

	/*
	 *	getPhoneNumber returns the phone number of the contact
	 */
std::string	Contact::getPhoneNumber( void ) const
{
	return (this->_phone_number);
}

	/*
	 *	getDarkestSecret returns the darkest secret of the contact
	 */
std::string	Contact::getDarkestSecret( void ) const
{
	return (this->_darkest_secret);
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

/*
 *	Validation of name it accept only alphabets, '-' and ' '
 */
bool		isValidName( const std::string& name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!std::isalpha(name[i]) && name[i] != '-' && name[i] != ' ')
			return false;
	}
	return (!name.empty());
}

/*
 *	capitalize the input put the first letter in uppercase and the rest in 
 *	lowercase
 */
std::string	capitalizeInput( const std::string & input )
{
	std::string	capitalizedInput;

	if (input.empty())
		return ("");
	capitalizedInput = input;
	capitalizedInput[0] = std::toupper(capitalizedInput[0]);
	for (size_t i = 1; i < capitalizedInput.length(); i++)
		capitalizedInput[i] = std::tolower(capitalizedInput[i]);
	return (capitalizedInput);
}

/*
 *	put input in uppercase
 */
std::string	putToUpperCase( const std::string& input )
{
	std::string	inUpperCase;

	inUpperCase = input;
	for (size_t i = 0; i < input.length(); i++)
		inUpperCase[i] = std::toupper(inUpperCase[i]);
	return (inUpperCase);
}

/*
 *	setContact set the contact with the given parameters
 *	check if parameters are empty and put some parameters on the correct 
 *	format
 */
void		Contact::setContact(	int index, \
								const std::string& f_name, \
								const std::string& l_name, \
								const std::string& n_name, \
								const std::string& phone, \
								const std::string& secret )
{
	if (f_name.empty() || l_name.empty() || n_name.empty() || phone.empty() || \
		secret.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return ;
	}
	this->_index = index;
	this->_first_name = capitalizeInput(f_name);
	this->_last_name = putToUpperCase(l_name);
	this->_nickname = capitalizeInput(n_name);
	this->_phone_number = phone;
	this->_darkest_secret = secret;
	return ;
}
