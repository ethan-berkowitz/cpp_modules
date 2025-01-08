/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:52:12 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/19 13:14:38 by eberkowi         ###   ########.fr       */
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

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (1) {
		get_input_and_check_for_signal(&input);
		if (input == "ADD") {
			phonebook.add_contact();
		}
		else if (input == "SEARCH") {
			phonebook.search_contacts();
			phonebook.receive_index();
		}
		else if (input == "EXIT")
			exit (0);
		else if (input == "")
			continue;
		else
			std::cout << "Invalid command. Enter ADD, SEARCH, or EXIT\n";
		input = "";
    }
	return (0);
}
