/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/27 19:11:42 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	// TEST #1: CREATE FORMS
	std::cout << "\n----- TEST #1: CREATE FORMS -----\n\n";

	Intern intern;
	Bureaucrat Barry("Barry", 1);
	AForm *shrubs;
	AForm *robotomy;
	AForm *pardon;

	shrubs = intern.makeForm("ShrubberyCreationForm", "Shrub_target");
	robotomy = intern.makeForm("RobotomyRequestForm", "Robotomy_target");
	pardon = intern.makeForm("PresidentialPardonForm", "Pardon_target");

	Barry.signForm(*shrubs);
	Barry.executeForm(*shrubs);
	Barry.signForm(*robotomy);
	Barry.executeForm(*robotomy);
	Barry.signForm(*pardon);
	Barry.executeForm(*pardon);

	std::cout << "\n";
	return (0);
}
