/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:06:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 09:55:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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

		/*	Constructor / Destructor	*/
		Contact( void );
		Contact(int index, \
				const std::string& f_name, \
				const std::string& l_name, \
				const std::string& n_name, \
				const std::string& phone, \
				const std::string& secret);
		~Contact( void );

		/*	Getter	*/
		int				getIndex( void ) const;
		std::string		getFirstName( void ) const;
		std::string		getLastName( void ) const;
		std::string		getNickname( void ) const;
		std::string		getPhoneNumber( void ) const;
		std::string		getDarkestSecret( void ) const;

		/*	Method	*/
		void			setContact( int index, \
									const std::string& f_name, \
									const std::string& l_name, \
									const std::string& n_name, \
									const std::string& phone, \
									const std::string& secret );

};

#endif
