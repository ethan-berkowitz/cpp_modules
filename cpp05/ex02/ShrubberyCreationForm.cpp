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

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Form", 145, 137),
													_target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137),
																_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("Shrubbery Form", 145, 137),
																					_target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (ShrubberyCreationForm const &other) {
	if (this != &other) {
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

//Mandatory

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getRequiredExecutionGrade() > executor.getGrade()
		&& getIsSigned())
	{
		std::ofstream outFile(_target);
    	if (outFile.is_open())
		{
			outFile << "          &&& &&  & &&\n";
			outFile << "      && &\\/&\\|& ()|/ @, &&\n";
			outFile << "      &\\/(/&/&||/& /_/)_&/_&\n";
			outFile << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
			outFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
			outFile << "&&   && & &| &| /& & % ()& /&&\n";
			outFile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
			outFile << "     &&     \\|||\n";
			outFile << "             |||\n";
			outFile << "             |||\n";
			outFile << "             |||\n";
			outFile << "       , -=-~  .-^- _\n";
			outFile.close();
		}
		else
        	std::cerr << "Error opening file!\n";
	}	
	else
		throw CannotExecuteFormException();
}

