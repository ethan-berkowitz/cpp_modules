/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:25:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/08 12:01:43 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	{
		std::cout << "\n---------------------\n";
		std::cout << "-----TYPE IS INT-----\n";
		std::cout << "---------------------\n\n";

		std::cout << "-----Construction with no parameter-----" << std::endl;
		Array<int> a;
		std::cout << "a = " << a << std::endl;

		std::cout << "-----Construction with parameter-----" << std::endl;
		Array<int> b(4);
		std::cout << "b = " << b << std::endl;

		std::cout << "-----Assigning values by index-----" << std::endl;
		Array<int> c(2);
		c[0] = 42;
		c[1] = 43;
		std::cout << "c = " << c << std::endl;

		std::cout << "-----Copy constructor-----" << std::endl;
		Array<int> d(c);
		std::cout << "d = " << d << std::endl;

		std::cout << "-----Copy assignment operator-----" << std::endl;
		b = c;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " <<c << std::endl;

		std::cout << "-----Size member function-----" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;

		std::cout << "-----Exception for index out of bounds-----" << std::endl;
		try {
			b[6] = 0;
		} catch(std::exception e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----------------------\n";
		std::cout << "-----TYPE IS CHAR-----\n";
		std::cout << "----------------------\n\n";

		std::cout << "-----Construction with no parameter-----" << std::endl;
		Array<char> a;
		std::cout << "a = " << a << std::endl;

		std::cout << "-----Construction with parameter-----" << std::endl;
		Array<char> b(4);
		std::cout << "b = " << b << std::endl;

		std::cout << "-----Assigning values by index-----" << std::endl;
		Array<char> c(2);
		c[0] = 'A';
		c[1] = 'B';
		std::cout << "c = " << c << std::endl;

		std::cout << "-----Copy constructor-----" << std::endl;
		Array<char> d(c);
		std::cout << "d = " << d << std::endl;

		std::cout << "-----Copy assignment operator-----" << std::endl;
		b = c;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " <<c << std::endl;

		std::cout << "-----Size member function-----" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;

		std::cout << "-----Exception for index out of bounds-----" << std::endl;
		try {
			b[6] = 0;
		} catch(std::exception e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;
	}
}
