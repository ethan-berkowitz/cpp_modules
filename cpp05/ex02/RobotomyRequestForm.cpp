/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/21 12:20:42 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Form", 72, 45),
													_target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Form", 72, 45),
																_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("Robotomy Form", 72, 45),
																					_target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm const &other) {
	if (this != &other) {
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

//Mandatory

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getRequiredExecutionGrade() > executor.getGrade()
		&& getIsSigned())
	{
		std::cout << "*DRILLING NOISES*\n";
		std::srand(std::time(0));
		int random_int = std::rand();
		if (random_int % 2)
			std::cout << _target << " robotomy was successful\n";
		else
			std::cout << _target << " robotomy has failed\n";

	}	
	else
		throw CannotExecuteFormException();
}

