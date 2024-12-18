/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:27 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/18 14:55:58 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact[0].index = "0";
	this->contact[1].index = "1";
	this->contact[2].index = "2";
	this->contact[3].index = "3";
	this->contact[4].index = "4";
	this->contact[5].index = "5";
	this->contact[6].index = "6";
	this->contact[7].index = "7";
	for (int i = 0; i < NUM_OF_CONTACTS; i++) {
		this->contact[i].time_created = 0;
	}
}

static void get_info(std::string *str, std::string prompt)
{
	*str = "";
	while (*str == "")
	{
		std::cout << prompt;
		std::getline(std::cin, *str);
		if (std::cin.eof())
			exit (1);
	}
}

void add_contact(Contact *contact)
{
	int last_id;

	last_id = 0;
	for (int i = 1; i < NUM_OF_CONTACTS; i++) {
		if (contact[i].time_created < contact[last_id].time_created)
			last_id = i;
	}
	contact[last_id].time_created = std::time(NULL);
	get_info(&contact[last_id].first_name, "First Name: ");
	get_info(&contact[last_id].last_name, "Last Name: ");
	get_info(&contact[last_id].nickname, "Nickname: ");
	get_info(&contact[last_id].phone_number, "Phone Number: ");
	get_info(&contact[last_id].darkest_secret, "Darkest Secret: ");
}
