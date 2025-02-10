/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:31:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 11:08:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook_Class.hpp"

int main(void)
{
	PhoneBook	repertoire;
	int			choice;

	choice = 0;
	while (1)
	{
		choice = repertoire.printMenu();
		switch (choice)
		{
			case 1:
				repertoire.addContact();
				break;
			case 2:
				repertoire.printPhoneBook();
				repertoire.searchContact();
				break;
			case 3:
				return (0);
		}
	}
}
