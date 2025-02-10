/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:24:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 14:52:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "Contact_class.hpp"

/*
 *	Constructor of the class Contact
 */
Contact::Contact(	int index, \
					const std::string f_name, \
					const std::string l_name, \
					const std::string n_name, \
					const std::string phone, \
					const std::string secret) :	_index(index), \
												_first_name(f_name), \
												_last_name(l_name), \
												_nickname(n_name), \
												_phone_number(phone), \
												_darkest_secret(secret)
{
	std::cout << GREEN << "Contact constructor called." << RESET << std::endl;
	return ;
}
/*
 *	Constructor of the class Contact
 */
Contact::Contact( void ) :	_index(0), \
							_first_name( "DOE" ), \
							_last_name( "JOHN" ), \
							_nickname( " JOHN DOE" ), \
							_phone_number( "+00/00.00.00.00.00"), \
							_darkest_secret( "Unknow person" )
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
