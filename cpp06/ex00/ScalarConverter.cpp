/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/01 11:22:26 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void convert_char_and_int(std::string input)
{
	try {
		int i = std::stoi(input);
		if (i >= 32 && i <= 126)
			std::cout << "char: " << (char)i << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	} catch (const std::exception &e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}	
}

static void convert_float(std::string input)
{
	try {
		float f = std::stof(input);
		std::cout << "float: " << f << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "float: impossible" << std::endl;
	}
}

static void convert_double(std::string input)
{
	try {
		double d = std::stod(input);
		std::cout << "double: " << d << std::endl;
	} catch (const std::exception &e) {
		std::cout << "double: impossible" << std::endl;
	}	
}

void ScalarConverter::convert(std::string input)
{
	convert_char_and_int(input);
	convert_float(input);
	convert_double(input);
}
