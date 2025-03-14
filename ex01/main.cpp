/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:31:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/18 12:41:47 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
 *	Print the menu of the PhoneBook.
 */
void	printMenu( void )
{
	std::cout << YELLOW << "**************************" << RESET << std::endl;
	std::cout << YELLOW << "Welcome to the PhoneBook" << RESET << std::endl;
	std::cout << YELLOW << "**************************" << RESET << std::endl;
	std::cout << YELLOW << "ADD :\t\tadd a new contact" << RESET << std::endl;
	std::cout << YELLOW << "SEARCH :\tsearch a contact" << RESET << std::endl;
	std::cout << YELLOW << "EXIT :\t\texit the program" << RESET << std::endl;
	std::cout << YELLOW << "What do you want to do ?" << RESET << std::endl;
}

/*
 *	PhoneBook programm is a simulation of phone book of 8 contacts.
 *	You can add a contact, search a contact and exit the program.
 *	if you put CTRL + D you exit the programm.
 */
int main(void)
{
	PhoneBook	my_phonebook;
	std::string	commande;

	while (true)
	{
		printMenu();
		std::getline(std::cin, commande);
		if (commande == "ADD")
			my_phonebook.addContact();
		else if (commande == "SEARCH")
			my_phonebook.searchContact();
		else if (commande == "EXIT")
		{
			std::cout << YELLOW << "Goodbye" << RESET << std::endl;
			return (0);
		}
		else
			std::cout << RED << "Invalid command" << RESET << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Goodbye" << std::endl;
			return (0);
		}
	}
}
