/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:06:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/11 15:32:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
 
class Contact
{
	private:

		int				_index;
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

	public:

		Contact();
		Contact(int index, \
				const std::string& f_name, \
				const std::string& l_name, \
				const std::string& n_name, \
				const std::string& phone, \
				const std::string& secret);
		~Contact();

		/*
		 *	getter functions
		 */

		int				getIndex( void ) const;
		std::string		getFirstName( void ) const;
		std::string		getLastName( void ) const;
		std::string		getNickname( void ) const;
		std::string		getPhoneNumber( void ) const;
		std::string		getDarkestSecret( void ) const;

		/*
		 *	setter functions
		 */

		void			setContact( int index, \
									const std::string& f_name, \
									const std::string& l_name, \
									const std::string& n_name, \
									const std::string& phone, \
									const std::string& secret );

};

#endif
