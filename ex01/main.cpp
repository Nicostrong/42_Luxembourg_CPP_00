/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:31:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:24 by nfordoxc         ###   Luxembourg.lu     */
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
	do
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
	} while (repertoire.getNbrContact() < 8);
	return (0);
}
