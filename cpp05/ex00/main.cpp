/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/31 09:37:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n";

	// TEST #1: INITIALIZATION, COPYING, AND INCREMENT/DECREMENT
	std::cout << "----- TEST #1: INITIALIZATION, COPYING, AND INCREMENT/DECREMENT -----\n\n";

	Bureaucrat Tilda("Tilda", 42);
	std::cout << Tilda;
	Bureaucrat Russell(Tilda);
	std::cout << "Name  = " << Russell.getName() << "\n";
	std::cout << "Grade = " << Russell.getGrade() << "\n";
	Russell.incrementGrade();
	std::cout << "Grade = " << Russell.getGrade() << "\n";
	Russell.decrementGrade();
	std::cout << "Grade = " << Russell.getGrade() << "\n";
	
	std::cout << "\n";

	// TEST #2: EXCEPTIONS
	std::cout << "----- TEST #2: EXCEPTIONS -----\n\n";

	// 1
	try {
		Bureaucrat Kevin("Kevin", 0);
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught " << e.what() << "\n";
	}
	// 2
	try {
		Bureaucrat Keleven("Keleven", 151);
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught " << e.what() << "\n";
	}
	// 3
	Bureaucrat Nerd("Nerd", 1);
	try {
		Nerd.incrementGrade();
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught " << e.what() << "\n";
	}
	// 4
	Bureaucrat Coolguy("Coolguy", 150);
	try {
		Coolguy.decrementGrade();
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught " << e.what() << "\n";
	}

	std::cout << "\n";
	
	return (0);
}
