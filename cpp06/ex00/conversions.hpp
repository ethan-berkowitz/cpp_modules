/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:24:11 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/08 11:32:53 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
# include <iostream>

void convert_unprintable()
{
	std::cout << "char: Non displayable\n" <<
				"int: impossible\n" <<
				"float: impossible\n" <<
				"double: impossible\n";
}

void convert_special(std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible\n" <<
		"int: impossible\n" <<
		"float: nanf\n" <<
		"double: nan\n";	
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible\n" <<
		"int: impossible\n" <<
		"float: +inff\n" <<
		"double: +inf\n";	
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible\n" <<
		"int: impossible\n" <<
		"float: -inff\n" <<
		"double: -inf\n";
	}
}

void convert_impossible()
{
	std::cout << "char: impossible\n" <<
	"int: impossible\n" <<
	"float: impossible\n" <<
	"double: impossible\n";
}

void convert_char(std::string input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void convert_int(std::string input)
{
	int i = stoi(input);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

    if (i < 0 || i > 255 || !std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void convert_float(std::string input)
{
	float f = stof(input);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (std::floor(f) == f)	
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (std::floor(d) == d)	
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	
}

void convert_double(std::string input)
{
	double d = stod(input);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (std::floor(f) == f)	
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (std::floor(d) == d)	
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	
}
