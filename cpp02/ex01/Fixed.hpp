/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:14 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/08 12:31:32 by eberkowi         ###   ########.fr       */
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

		Fixed(void); 							//Default
		Fixed(Fixed const &other); 				//Copy
		Fixed& operator = (Fixed const &other);	//Copy Assignment
		Fixed(const int n);						//Integer
		Fixed(const float n);					//Float
		~Fixed(void); 							//Destructor

		int	getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);
