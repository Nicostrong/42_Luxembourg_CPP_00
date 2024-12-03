/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:02:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/03 16:52:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"

class PhoneBook
{
	private:

		static int	_nbr_contact;
		Contact		*contacts[8];

	public:

		PhoneBook();
		~PhoneBook();

		int			printMenu( void );
		static int	getNbrContact( void );
		void		addContact( void );
		void		removeContact(int index );
		void		searchContact( void ) const;
		void		printPhoneBook( void ) const;

};

#endif
