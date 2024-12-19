/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:27 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/19 12:00:36 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact[0].set_index("0");
	this->contact[1].set_index("1");
	this->contact[2].set_index("2");
	this->contact[3].set_index("3");
	this->contact[4].set_index("4");
	this->contact[5].set_index("5");
	this->contact[6].set_index("6");
	this->contact[7].set_index("7");
}

PhoneBook::~PhoneBook() {}

static std::string get_input(std::string prompt)
{
	std::string str = "";
	
	while (str == "")
	{
		std::cout << prompt;
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit (1);
	}
	return (str);
}

void PhoneBook::add_contact()
{
	int last_id;

	last_id = 0;
	for (int i = 1; i < NUM_OF_CONTACTS; i++) {
		if (contact[i].get_time_created() < contact[last_id].get_time_created())
			last_id = i;
	}
	contact[last_id].set_time_created(std::time(NULL));
	contact[last_id].set_first_name(get_input("First Name: "));
	contact[last_id].set_last_name(get_input("Last Name: "));
	contact[last_id].set_nickname(get_input("Nickname: "));
	contact[last_id].set_phone_number(get_input("Phone Number: "));
	contact[last_id].set_darkest_secret(get_input("Darkest Secret: "));
}

static void show_contact(Contact contact, int index)
{
	std::cout << std::setw(10) << index;
	if (contact.get_first_name().length() >= 10)
		std::cout << "|" << contact.get_first_name().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.get_first_name();
	if (contact.get_last_name().length() >= 10)
		std::cout << "|" << contact.get_last_name().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.get_last_name();
	if (contact.get_nickname().length() >= 10)
		std::cout << "|" << contact.get_nickname().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << contact.get_nickname();
	std::cout << "\n";
}

void PhoneBook::search_contacts()
{
	for (int i = 0; i < NUM_OF_CONTACTS; i++) {
		show_contact(contact[i],i);
	}
}

static void print_contact(Contact contact)
{
	std::cout << "First Name: " << contact.get_first_name() << "\n";
	std::cout << "Last Name: " << contact.get_last_name() << "\n";
	std::cout << "Nickname: " << contact.get_nickname() << "\n";
	std::cout << "Phone Number: " << contact.get_phone_number() << "\n";
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << "\n";
}

void PhoneBook::receive_index()
{
	std::string input;

	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	for (int i = 0; i < NUM_OF_CONTACTS; i++) {
		if (input == contact[i].get_index()) {
			print_contact(contact[i]);
			return ;
		}
	}
	std::cout << "Not a valid index\n";
}
