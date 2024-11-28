/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:31:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/28 13:58:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

int	ft_print_menu(void)
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
}

int main(void)
{
	int		choice;
	
	std::cout << "*** PhoneBook is empty ***" << std::endl;
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
	}
	return (0);
}