/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:06:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 10:29:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
 
class Contact
{
	private:

		std::string		_index;
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

		int				checkFormatPhoneNumber( std::string str );

		std::string		getInput( void );
		std::string		getNumber( void );
		std::string		formatOutput(std::string str, size_t s);
	
	public:

		Contact();
		~Contact();
		
		void 				createContact( int index );
		void				printContact( void ) const;
		void				printContactList( int index );
};

#endif

