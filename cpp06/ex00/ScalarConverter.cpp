/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/14 11:23:16 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

// Mandatory

static void convert_unprintable()
{
	std::cout << "char: Non displayable\n" <<
				"int: impossible\n" <<
				"float: impossible\n" <<
				"double: impossible\n";
}

static void convert_special(std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible\n" <<
		"int: impossible\n" <<
		"float: nanf\n" <<
		"double: nan\n";	
	}
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
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

static void convert_impossible()
{
	std::cout << "char: impossible\n" <<
	"int: impossible\n" <<
	"float: impossible\n" <<
	"double: impossible\n";
}

static void convert_char(std::string input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (!isprint(c))
	{
		convert_unprintable();
		return ;
	}
	std::cout << "char: " << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static void convert_int(std::string input)
{
	int i = stoi(input);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

    if (i < 0 || i > 255 || !std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static void convert_float(std::string input)
{
	float f = stof(input);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (isprint(c) && std::floor(d) == d)
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f > (float)INT_MAX || f < (float)INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (std::floor(d) == d)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

static void convert_double(std::string input)
{
	double d = stod(input);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (isprint(c) && std::floor(d) == d)
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d <= (double)INT_MAX || d >= (double)INT_MIN)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (std::floor(d) == d && f <= __FLT_MAX__ && f >= __FLT_MIN__)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

static bool is_special(const std::string input)
{
	if (input == "nan" ||
		input == "nanf" ||
		input == "+inf" ||
		input == "+inff" ||
		input == "-inf" ||
		input == "-inff" ||
		input == "inf" ||
		input == "inff")
		return (true);
	return (false);
}

static bool is_char(std::string input, size_t len)
{
	if ((len == 1 && !isdigit(input[0])) ||
		(len == 3 && input[0] == '\'' && input[2] == '\''))
		return (true);
	else
		return (false);
}

static bool is_int(std::string input, size_t len)
{
	size_t i = 0;

	if (input[0] == '+' || input[0] == '-')
	{
		if (len > 11)
			return (false);
		i++;
	}
	else if (len > 10)
		return (false);
	for (; i < len ; i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	try {
		std::stoi(input);
	} catch (...) {
		return (false);
	}
	return (true);
}

static bool is_float(std::string input, size_t len)
{
	if (input.find('.') == std::string::npos)
		return (false);
	if (input.back() == 'f' || input.back() == 'F')
	{
		input.pop_back();
		len--;
	}
	try {
		size_t index;
		std::stof(input, &index);
		if (index == len)
			return (true);
	} catch (...) {
		return (false);
	}
	return (false);
}

static bool is_double(std::string input, size_t len)
{
	if (input.back() == 'd' || input.back() == 'D')
	{
		input.pop_back();
		len--;
	}
	try {
		size_t index;
		std::stod(input, &index);
		if (index == len)
			return (true);
	} catch (...) {
		return (false);
	}
	return (false);
}

void ScalarConverter::convert(std::string input)
{
	size_t len = input.length();

	if (is_special(input))
		convert_special(input);
	else if (is_char(input, len))
		convert_char(input);
	else if (is_int(input, len))
		convert_int(input);
	else if (is_double(input, len))
		convert_double(input);
	else if (is_float(input, len))
		convert_float(input);
	else
		convert_impossible();
}
