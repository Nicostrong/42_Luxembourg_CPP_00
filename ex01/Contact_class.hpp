/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:06:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 14:55:31 by nfordoxc         ###   Luxembourg.lu     */
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

		int					_index;
		const std::string	_first_name;
		const std::string	_last_name;
		const std::string	_nickname;
		const std::string	_phone_number;
		const std::string	_darkest_secret;

	public:

		Contact(int index, \
				std::string f_name, \
				std::string l_name, \
				std::string n_name, \
				std::string phone, \
				std::string secret);
		Contact();
		~Contact();
};

#endif

