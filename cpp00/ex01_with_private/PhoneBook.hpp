/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:54:39 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/18 15:14:33 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define NUM_OF_CONTACTS 8

# include "Contact.hpp"
# include <iostream>
# include <ctime>

class PhoneBook
{
    public:
	PhoneBook();
        Contact contact[NUM_OF_CONTACTS];
};

void add_contact(Contact *contact);
