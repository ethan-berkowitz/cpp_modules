/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/08 13:58:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// cpp00 ----------------------------------------------------------------------

const int Fixed::_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->_RawBits = 0;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called\n";
	this->_RawBits = other.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator = (Fixed const &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		_RawBits = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const{
	return (_RawBits);
}

// cpp01 ----------------------------------------------------------------------

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called\n";
	this->_RawBits = n * (1 << this->_bits);
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called\n";
	this->_RawBits = std::roundf(n * (1 << this->_bits));
}

float Fixed::toFloat(void) const {
	return ((float)this->_RawBits / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const {
	return (this->_RawBits >> this->_bits);
}

std::ostream	&operator << (std::ostream &stream, Fixed const &f) {
	stream << f.toFloat();
	return (stream);
}
