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

#include "AForm.hpp"

AForm::AForm(void) : _is_signed(false),
					_required_signing_grade(1),
					_required_execution_grade(1) {}

AForm::AForm(const std::string name,
			int required_signing_grade,
			int required_execution_grade) : _name(name),
											_is_signed(false),
											_required_signing_grade(required_signing_grade),
											_required_execution_grade(required_execution_grade) {
	if (required_signing_grade > 150)
		throw GradeTooLowException();
	else if (required_signing_grade < 1)
		throw GradeTooHighException();
	if (required_execution_grade > 150)
		throw GradeTooLowException();
	else if (required_execution_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : _name(other._name),
								_is_signed(other._is_signed),
								_required_signing_grade(other._required_signing_grade),
								_required_execution_grade(other._required_execution_grade) {}

AForm::~AForm(void) {}

AForm& AForm::operator = (AForm const &other) {
	if (this != &other) {
		_is_signed = other._is_signed;
	}
	return (*this);
}

//Mandatory

std::string	AForm::getName(void) const{
	return (_name);
}

bool AForm::getIsSigned(void) const{
	return (_is_signed);
}

int AForm::getRequiredSigningGrade(void) {
	return (_required_signing_grade);
}

int AForm::getRequiredExecutionGrade(void) const{
	return (_required_execution_grade);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _required_signing_grade)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

// Operator Overload

std::ostream &operator<<(std::ostream &os, AForm &other)
{
	os << "Name: " << other.getName() << "\n";
	if (other.getIsSigned() == true)
		os << "Signed: True\n";
	else
		os << "Signed: False\n";
	os << "Required Signing Grade: " << other.getRequiredSigningGrade() << "\n";
	os << "Required Execution Grade: " << other.getRequiredExecutionGrade() << "\n";
	return (os);
}
