/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:25:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/15 13:45:02 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	{
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
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Array<std::string> a;
		Array<std::string> b(4);
		Array<std::string> c(2);
		Array<std::string> d(a);

		c[0] = "Apple";
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		c = b;
		b[2] = "Banana";
		try {
			b[6] = "Coconut";
		} catch(std::exception e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << a.size() << "-" << b.size() << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "d: " << d << std::endl;
	}
}
