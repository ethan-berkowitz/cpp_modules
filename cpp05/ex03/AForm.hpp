/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/27 17:09:51 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	
		const std::string	_name;
		bool				_is_signed;
		const int 			_required_signing_grade;
		const int 			_required_execution_grade;
		
	public:

		AForm(void);
		AForm(const std::string name,
			const int required_signing_grade,
			const int required_execution_grade);
		AForm(const AForm &other);
		AForm& operator = (AForm const &other);
		virtual ~AForm(void);

		//Mandatory

		std::string	getName(void) const;
		bool getIsSigned(void) const;
		int getRequiredSigningGrade(void);
		int getRequiredExecutionGrade(void) const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		// Exception Classes

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Grade too high!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Grade too low!");
				}
		};

		class CannotExecuteFormException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Cannot execute form!");
				}
		};
};

//Operator Overload
std::ostream &operator<<(std::ostream &os, AForm &other);

#endif
