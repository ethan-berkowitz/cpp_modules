/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/27 19:10:43 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::makeForm(std::string form, std::string target)
{
	int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm",
									"RobotomyRequestForm",
									"PresidentialPardonForm"};

	while (i < 3 && form != available_forms[i])
		i++;
	
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << form << "\n";
		return (new ShrubberyCreationForm(target));
	case 1:
		std::cout << "Intern creates " << form << "\n";
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern creates " << form << "\n";
		return (new PresidentialPardonForm (target));
	default:
		std::cout << "Form does not exist" << "\n";
		return NULL;
	}
}
