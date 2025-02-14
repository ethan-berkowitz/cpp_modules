/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:14 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 15:48:25 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Fixed
{
	private:

		int _RawBits;
		const static int _bits;
		
	public:

		Fixed(void);
		Fixed(Fixed const &other);
		~Fixed(void);

		Fixed& operator = (Fixed const &other);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
