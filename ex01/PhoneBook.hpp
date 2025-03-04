/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:02:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/04 07:31:59 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include <cstdlib>
# include <sstream>

# include "Contact.hpp"

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"

class PhoneBook
{
	private:

		static int			_nbr_contact;
		static const int	_max_contact = 8;
		Contact				_contacts[_max_contact];
		int					_oldest_index;

		/*	private method	*/
		bool				hasChar( std::string &input);
		bool				isNumber( const std::string	&input );
		bool				isValidInput( const std::string	&input );
		std::string			getValidInput( const std::string &prompt, bool isPhone );

	public:

		/*	Constructor / Destructor	*/
		PhoneBook( void );
		~PhoneBook( void );

		/*	Method	*/
		void				addContact( void );
		void				searchContact( void ) const;
		void				displayContact( int index ) const;
		void				printContacts( void ) const;

};

#endif
