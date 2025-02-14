/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 16:09:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called\n";
	this->setRawBits(other.getRawBits());
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator = (Fixed const &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (_RawBits);
}

void Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
}
