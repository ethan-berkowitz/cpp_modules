/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:54:39 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/19 14:29:27 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define NUM_OF_CONTACTS 8

# include "Contact.hpp"
# include <iostream>
# include <ctime>

class PhoneBook
{
	private:
	
		Contact contact[NUM_OF_CONTACTS];
		
    public:
	
		PhoneBook(void);
		~PhoneBook(void);

		void add_contact(void);
		void search_contacts(void);
		void receive_index(void);
};
