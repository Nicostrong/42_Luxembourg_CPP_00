/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:31:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/02 13:05:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Contact_class.hpp"

/*int	ft_print_menu(void)
{
	std::string	buff;
	
	buff = "";
	std::cout << "What do you want to do ?" << std::endl;
	std::cout << "ADD : add a new contact" << std::endl;
	std::cout << "SEARCH : search a contact" << std::endl;
	std::cout << "EXIT : exit the program" << std::endl;
	while (buff != EXIT && buff != SEARCH && buff != ADD)
		std::cin >> buff;
	if (buff == ADD)
		return (1);
	else if (buff == SEARCH)
		return (2);
	return (0);
}*/

int main(void)
{
	//int		choice;
	std::cout << "nbr de contact initial " << Contact::get_nbr_contact() << std::endl;
	Contact c1( 1 );
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;
	Contact c2( 2 );
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;
	/*Contact		mon_contact(2);
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;
	mon_contact.ft_print();
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;*/
	/*std::cout << "*** PhoneBook is empty ***" << std::endl;
	choice = ft_print_menu();
	switch (choice)
	{
	case 1:
		std::cout << "execution de la commande [ADD]" << std::endl;
		main();
		break;
	case 2:
		std::cout << "execution de la commande [ SEARCH]" << std::endl;
		main();
		break;
	case 0:
		std::cout << "execution de la commande [EXIT]" << std::endl;
		return (0);
	default:
		break;
	}*/
	c1.~Contact();
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;
	c2.~Contact();
	std::cout << "nbr de contact " << Contact::get_nbr_contact() << std::endl;
	return (0);
}
