/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Bureaucrat
{
	protected:
	
		const std::string	_name;
		int 				_grade;
		
	public:

		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator = (Bureaucrat const &other);
		~Bureaucrat(void);

		// Mandatory
		std::string	getName(void);
		int getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);

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
};

//Operator Overload
std::ostream &operator<<(std::ostream &os, Bureaucrat &other);
