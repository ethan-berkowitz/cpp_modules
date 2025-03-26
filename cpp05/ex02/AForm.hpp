/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

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
		~AForm(void);

		AForm& operator = (AForm const &other);

		//Mandatory

		std::string	getName(void);
		bool getIsSigned(void) const;
		int getRequiredSigningGrade(void);
		int getRequiredExecutionGrade(void);
		void setIsSigned(bool is_signed);

		void beSigned(Bureaucrat &bureaucrat);

		// Exception Classes

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

//Operator Overload
std::ostream &operator<<(std::ostream &os, AForm &other);

#endif
