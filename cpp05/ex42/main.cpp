/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/27 11:18:12 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class MyFirstException : public std::exception
{
	public:
		virtual const char* what() const noexcept
		{
			return ("My Custom Exception String");
		}		
};

int main(void)
{
	std::string word = "four";

	try {
		throw MyFirstException();
	}
	catch (MyFirstException& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
}