/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/08 11:49:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "check_type.hpp"
#include "conversions.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

// Mandatory

void ScalarConverter::convert(std::string input)
{
	size_t len = input.length();

	if (contains_unprintable_char(input, len))
		convert_unprintable();
	else if (is_special(input))
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
