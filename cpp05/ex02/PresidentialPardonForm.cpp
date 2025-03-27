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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Pardon Form", 145, 137),
													_target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon Form", 145, 137),
																_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("Pardon Form", 145, 137),
																					_target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm const &other) {
	if (this != &other) {
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

//Mandatory

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getRequiredExecutionGrade() > executor.getGrade()
		&& getIsSigned())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	}	
	else
		throw CannotExecuteFormException();
}
