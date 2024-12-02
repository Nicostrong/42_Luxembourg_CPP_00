/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:02:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/02 13:19:30 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"
class PhoneBook
{
	private:

		static int	_nbr_contact;
		Contact		contact[8];

	public:

		PhoneBook();
		~PhoneBook();

		static int	get_nbr_contact( void );
		void		ft_addcontact(Contact contact);
		void		ft_removecontact(int index);
		void		ft_printphonebook(PhoneBook book) const;

};

#endif