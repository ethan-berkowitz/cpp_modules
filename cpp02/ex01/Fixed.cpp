/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/14 10:27:06 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// cpp00 ----------------------------------------------------------------------

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

// cpp01 ----------------------------------------------------------------------

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called\n";
	this->setRawBits(n * (1 << this->_bits));
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called\n";
	this->setRawBits(std::roundf(n * (1 << this->_bits)));
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
