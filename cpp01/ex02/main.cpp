/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:23 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/17 12:47:56 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void) {
	std::string str = "hello";
	std::string *stringPTR = &str; 
	std::string &stringREF = str;

	std::cout << "Address of string:    " << &str << "\n";
	std::cout << "Address of stringPTR: " << &*stringPTR << "\n";
	std::cout << "Address of stringREF: " << &stringREF << "\n";

	std::cout << "Value of string:    " << str << "\n";
	std::cout << "Value of stringPTR: " << *stringPTR << "\n";
	std::cout << "Value of stringREF: " << stringREF << "\n";
}
