/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/24 12:26:00 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// TEST #1: INITIALIZATION, COPY, AND OVEROAD OPERATOR
	std::cout << "\n----- TEST #1: INITIALIZATION -----\n\n";
	
	Form		taxform("taxform", 42, 150);
	Form		otherform(taxform);

	std::cout << otherform;

	// TEST #2: SIGN FORM
	std::cout << "\n----- TEST #2: SIGN FORM -----\n\n";

	Bureaucrat	leon("Leon", 42);
	Form 		nda("nda", 50, 50);
	Form 		important("important", 1, 1);

	leon.signForm(nda);
	leon.signForm(important);

	// TEST #3: SHOW FORM IS SIGNED
	std::cout << "\n----- TEST #3: SHOW FORM IS SIGNED -----\n\n";

	std::cout << nda;

	std::cout << "\n";
	return (0);
}
