/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:21:33 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/08 10:25:09 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <limits>

bool contains_unprintable_char(std::string input, size_t len)
{
	for(size_t i = 0; i < len; i++)
	{
		if (!isprint(input[i]))
			return (true);
	}
	return (false);
}

bool is_special(const std::string input)
{
	if (input == "nan" ||
		input == "nanf" ||
		input == "+inf" ||
		input == "+inff" ||
		input == "-inf" ||
		input == "-inff")
		return (true);
	return (false);
}

bool is_char(std::string input, size_t len)
{
	if ((len == 1 && !isdigit(input[0])) ||
		(len == 3 && input[0] == '\'' && input[2] == '\''))
		return (true);
	else
		return (false);
}

bool is_int(std::string input, size_t len)
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
	double d = std::stod(input);
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

bool is_float(std::string input, size_t len)
{
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

bool is_double(std::string input, size_t len)
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
