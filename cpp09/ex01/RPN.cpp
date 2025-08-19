/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/19 15:47:57 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float getResult(double a, double b, std::string value) {
	if (value == "+")
		return (a + b);
	else if (value == "-")
		return (a - b);
	else if (value == "*")
		return (a * b);
	else
		return (a / b);
	
}

void RPN(std::string input) {
	std::stringstream input_stream(input);
	std::stack<float> values;
	std::string value;
	std::string single_digits = "0 1 2 3 4 5 6 7 8 9";
	std::string operands = "+ - * /";
	float a, b, result;

	while (input_stream >> value) {
		if (single_digits.find(value) != std::string::npos) {
			values.push(stod(value));
		}
		else if (operands.find(value) != std::string::npos) {
			if (!values.empty()) {
				b = values.top();
				values.pop();
			}
			else {
				throw std::runtime_error("Error: cannot operate on 0 values");
			}
			if (!values.empty()) {
				a = values.top();
				values.pop();
			}
			else {
				throw std::runtime_error("Error: cannot operate on 1 value");
			}
			result = getResult(a, b, value);
			values.push(result);
		}
		else {
			throw std::runtime_error("Error: invalid input");
		}
	}
	if (!values.empty()) {
		result = values.top();
		values.pop();
		if (values.empty())
			std::cout << result << std::endl;
		else {
			throw std::runtime_error("Error: more digits than operands");
		}
	}
	else {
		throw std::runtime_error("Error: malformed input");
	}
	
	
}
