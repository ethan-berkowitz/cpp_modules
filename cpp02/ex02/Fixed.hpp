/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:14 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/08 15:19:29 by eberkowi         ###   ########.fr       */
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
		float toFloat(void) const;
		int toInt(void) const;

		bool	operator > (Fixed const &f) const;
		bool	operator < (Fixed const &f) const;
		bool	operator >= (Fixed const &f) const;
		bool	operator <= (Fixed const &f) const;
		bool	operator == (Fixed const &f) const;
		bool	operator != (Fixed const &f) const;

		Fixed	operator + (Fixed const &f);
		Fixed	operator - (Fixed const &f);
		Fixed	operator * (Fixed const &f);
		Fixed	operator / (Fixed const &f);

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream	&operator << (std::ostream &stream, Fixed const &f);
