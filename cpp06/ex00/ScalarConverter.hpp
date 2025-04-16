/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>
# include <iomanip>
# include <limits.h>


class ScalarConverter
{
	private:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter& operator = (ScalarConverter const &other) = delete;
		~ScalarConverter(void);

	public:

		static void	convert(std::string input);
};
