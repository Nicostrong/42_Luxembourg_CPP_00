/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:24:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/02 13:06:35 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact_class.hpp"

int		Contact::_nbr_contact = 0;

Contact::Contact(int index) : index( index )
{
	std::cout << "Constructor called." << std::endl;
	//this->_Create();
	Contact::_nbr_contact++;
	return ;
}

Contact::~Contact( void )
{
	std::cout << "Destructor called." << std::endl;
	Contact::_nbr_contact--;
	return ;
}

int	Contact::get_nbr_contact( void )
{
	return (Contact::_nbr_contact);
}

void	Contact::ft_print( void ) const
{
	std::cout << "Votre index est " << this->index << std::endl;
	std::cout << "Votre nom est " << this->first_name << std::endl;
	std::cout << "Votre prenom est " << this->last_name << std::endl;
	std::cout << "Votre pseudo est " << this->nickname << std::endl;
	std::cout << "Votre num est " << this->phone_number << std::endl;
	std::cout << "Votre secret est " << this->darkest_secret << std::endl;

}

void Contact::_Create( void )
{
	std::cout << "Quel est votre nom ?" << std::endl;
	getline(std::cin, this->first_name);
	std::cin.clear();
	std::cout << "Quel est votre prenom ?" << std::endl;
	getline(std::cin, this->last_name);
	std::cin.clear();
	std::cout << "Quel est votre pseudo ?" << std::endl;
	getline(std::cin, this->nickname);
	std::cin.clear();
	std::cout << "Quel est votre num de tel ?" << std::endl;
	getline(std::cin, this->phone_number);
	std::cin.clear();
	std::cout << "Quel est votre secret ?" << std::endl;
	getline(std::cin, this->darkest_secret);
	std::cin.clear();
	return ;
}
