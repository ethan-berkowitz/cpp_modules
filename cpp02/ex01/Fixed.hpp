/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:14 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 16:11:17 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
	private:

		int _RawBits;
		const static int _bits;
		
	public:

		Fixed(void);
		Fixed(Fixed const &other);
		Fixed& operator = (Fixed const &other);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed(void);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);
