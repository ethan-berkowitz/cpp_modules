/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:53:28 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/18 14:49:29 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void) {}

static void show_contact(Contact contact, int index)
{
	std::cout << std::setw(10) << index;
	if (contact.first_name.length() >= 10)
		std::cout << "|" << contact.first_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.first_name;
	if (contact.last_name.length() >= 10)
		std::cout << "|" << contact.last_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.last_name;
	if (contact.nickname.length() >= 10)
		std::cout << "|" << contact.nickname.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.nickname;
	std::cout << "\n";
}

void search_contacts(Contact *contact)
{
	for (int i = 0; i < NUM_OF_CONTACTS; i++) {
		show_contact(contact[i],i);
	}
}

static void print_contact(Contact contact)
{
	std::cout << "First Name: " << contact.first_name << "\n";
	std::cout << "Last Name: " << contact.last_name << "\n";
	std::cout << "Nickname: " << contact.nickname << "\n";
	std::cout << "Phone Number: " << contact.phone_number << "\n";
	std::cout << "Darkest Secret: " << contact.darkest_secret << "\n";
}

void receive_index(Contact *contact)
{
	std::string input;

	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	for (int i = 0; i < NUM_OF_CONTACTS; i++) {
		if (input == contact[i].index) {
			print_contact(contact[i]);
			return ;
		}
	}
	std::cout << "Not a valid index\n";
}
