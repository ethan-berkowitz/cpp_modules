/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	
		const std::string	_name;
		bool				_is_signed;
		const int 			_required_signing_grade;
		const int 			_required_execution_grade;
		
	public:

		Form(void);
		Form(const std::string name,
			const int required_signing_grade,
			const int required_execution_grade);
		Form(const Form &other);
		~Form(void);

		Form& operator = (Form const &other);

		//Mandatory

		std::string	getName(void);
		bool getIsSigned(void);
		int getRequiredSigningGrade(void);
		int getRequiredExecutionGrade(void);

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
};

//Operator Overload
std::ostream &operator<<(std::ostream &os, Form &other);

#endif
