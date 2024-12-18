/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:52:12 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/18 14:49:43 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	get_input_and_check_for_signal(std::string *input)
{
	if (std::cin.eof())
		exit (1);
	std::cout << "Enter command: ";
	std::getline(std::cin, *input);
	if (std::cin.eof())
		exit (1);
}

// make contact stuff private and use getters and setters
// use constructor when you CREATE the contact!

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (1) {
		get_input_and_check_for_signal(&input);
		if (input == "ADD") {
			add_contact(phonebook.contact);
		}
		else if (input == "SEARCH") {
			search_contacts(phonebook.contact);
			receive_index(phonebook.contact);
		}
		else if (input == "EXIT")
			exit (0);
		else if (input == "")
			continue;
		else
			std::cout << "Invalid command. Enter ADD, SEARCH, or EXIT\n";
		input = "";
    }
}
