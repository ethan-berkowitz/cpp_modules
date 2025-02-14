/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:45:51 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/14 10:28:28 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) 
{
	// Mandatory ---------------------------------------------------------------

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// My tests ----------------------------------------------------------------
	
	// Comparison Operators
	if (Fixed(2) > Fixed(1.99f))	{ std::cout << "Test 1  (>)  : TRUE\n"; };
	if (Fixed(1.99f) < Fixed(1000))	{ std::cout << "Test 2  (<)  : TRUE\n"; };
	if (Fixed(5) >= Fixed(5.00f))	{ std::cout << "Test 3  (>=) : TRUE\n"; };
	if (Fixed(800) >= Fixed(5.00f))	{ std::cout << "Test 4  (>=) : TRUE\n"; };
	if (Fixed(5) <= Fixed(5.00f))	{ std::cout << "Test 5  (<=) : TRUE\n"; };
	if (Fixed(1) <= Fixed(1.25f))	{ std::cout << "Test 6  (<=) : TRUE\n"; };
	if (Fixed(1) == Fixed(1.00f))	{ std::cout << "Test 7  (==) : TRUE\n"; };
	if (Fixed(2) != Fixed(1.00f))	{ std::cout << "Test 8  (!=) : TRUE\n"; };

	// Arithmetic Operators
	Fixed const c(Fixed(40.00f) + Fixed(2));
	std::cout << "Test 9  (+)  : " << c << "\n";
	Fixed const d(Fixed(44.00f) - Fixed(1));
	std::cout << "Test 10 (-)  : " << d << "\n";
	Fixed const e(Fixed(11.00f) * Fixed(4));
	std::cout << "Test 11 (*)  : " << e << "\n";
	Fixed const f(Fixed(90.00f) / Fixed(2));
	std::cout << "Test 12 (/)  : " << f << "\n";

	// Increment and Decrement Operators
	std::cout << "Test 13 (++)\n";
	Fixed g(42);
	std::cout << g << std::endl;
	std::cout << ++g << std::endl;
	std::cout << g << std::endl;
	std::cout << g++ << std::endl;
	std::cout << g << std::endl;

	std::cout << "Test 14 (--)\n";
	Fixed h(42);
	std::cout << h << std::endl;
	std::cout << --h << std::endl;
	std::cout << h << std::endl;
	std::cout << h-- << std::endl;
	std::cout << h << std::endl;

	// Min and Max Overload Functions
	Fixed const i(42);
	Fixed const j(101.05f);
	std::cout << "Test 15 (min const): " << Fixed::min(i, j) << std::endl;

	Fixed k(42);
	Fixed l(101.05f);
	std::cout << "Test 16 (min): " << Fixed::min(k, l) << std::endl;

	Fixed const m(42);
	Fixed const n(1.05f);
	std::cout << "Test 17 (min const): " << Fixed::max(m, n) << std::endl;

	Fixed o(42);
	Fixed p(1.05f);
	std::cout << "Test 18 (min): " << Fixed::max(o, p) << std::endl;

	return 0;
}
