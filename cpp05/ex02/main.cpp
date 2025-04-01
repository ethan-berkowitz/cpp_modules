/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/31 11:56:16 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// TEST #1: SIGN AND EXECUTE FORMS
	std::cout << "\n----- TEST #1: SIGN AND EXECUTE FORMS -----\n\n";

	Bureaucrat Vogon("Vogon", 1);
	Bureaucrat King_Arthur("King Arthur", 1);
	ShrubberyCreationForm petition_for_shrubs("England");

	Vogon.signForm(petition_for_shrubs);
	King_Arthur.executeForm(petition_for_shrubs);

	std::cout << "\n";

	RobotomyRequestForm schedule_surgery("Arthur");
	Vogon.signForm(schedule_surgery);
	King_Arthur.executeForm(schedule_surgery);

	std::cout << "\n";

	PresidentialPardonForm intergalactic_pardon("Slartibartfast");
	Vogon.signForm(intergalactic_pardon);
	King_Arthur.executeForm(intergalactic_pardon);

	std::cout << "\n";
	return (0);
}
