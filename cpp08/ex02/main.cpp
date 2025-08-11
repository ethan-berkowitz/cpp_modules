/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/11 13:26:56 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
	{
		try {
			std::cout << "\033[1;33m\n----- REQUIRED FUNCTIONS -----\n\n\033[0m";
			
			Span sp = Span(10);
			sp.addNumber(3);
			sp.addNumber(5);
			sp.addNumber(9);
			sp.addNumber(17);
			sp.addNumber(45);

			sp.print();

			std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan = " << sp.longestSpan() << std::endl;

			std::vector<int> temp = {20, 21, 22, 23, 53};
			sp.addRangeOfIterators(temp.begin(), temp.end());

			sp.print();

			std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		} catch(const std::exception &e) {
			std::cerr << "Exception caught " << e.what() << "\n";
		}
	}
	{
		try {
			std::cout << "\033[1;33m\n----- EXCEPTION FOR ADD NUMBER -----\n\n\033[0m";
			
			Span sp = Span(3);
			sp.addNumber(3);
			sp.addNumber(5);
			sp.addNumber(9);
			sp.addNumber(17);
		} catch(const std::exception &e) {
			std::cerr << "Exception caught " << e.what() << "\n";
		}
	}
	{
		try {
			std::cout << "\033[1;33m\n----- EXCEPTION FOR SPAN -----\n\n\033[0m";
			
			Span sp = Span(1);
			sp.addNumber(3);
			sp.shortestSpan();
		} catch(const std::exception &e) {
			std::cerr << "Exception caught " << e.what() << "\n";
		}
	}
	{
		try {
			std::cout << "\033[1;33m\n----- EXCEPTION FOR RANGE -----\n\n\033[0m";
			
			Span sp = Span(1);
			sp.addNumber(3);
			std::vector<int> temp = {20, 21, 22, 23, 53};
			sp.addRangeOfIterators(temp.begin(), temp.end());
		} catch(const std::exception &e) {
			std::cerr << "Exception caught " << e.what() << "\n";
		}
	}
	std::cout << std::endl;
}
