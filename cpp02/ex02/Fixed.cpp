/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:46:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/08 15:19:07 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// cpp00 ----------------------------------------------------------------------

const int Fixed::_bits = 8;

Fixed::Fixed(void) {
	//std::cout << "Default constructor called\n";
	this->_RawBits = 0;
}

Fixed::Fixed(Fixed const &other) {
	//std::cout << "Copy constructor called\n";
	this->_RawBits = other.getRawBits();
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called\n";
}

Fixed& Fixed::operator = (Fixed const &other) {
	//std::cout << "Copy assignment operator called\n";
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
	//std::cout << "Int constructor called\n";
	this->_RawBits = n * (1 << this->_bits);
}

Fixed::Fixed(const float n) {
	//std::cout << "Float constructor called\n";
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

// cpp02 ----------------------------------------------------------------------

bool	Fixed::operator > (Fixed const &f) const {
	if (this->_RawBits > f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator < (Fixed const &f) const {
	if (this->_RawBits < f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator >= (Fixed const &f) const {
	if (this->_RawBits >= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator <= (Fixed const &f) const {
	if (this->_RawBits <= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator == (Fixed const &f) const {
	if (this->_RawBits == f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator != (Fixed const &f) const {
	if (this->_RawBits != f.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator + (Fixed const &f) {
	this->_RawBits += f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator - (Fixed const &f) {
	this->_RawBits -= f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator * (Fixed const &f) {
	this->_RawBits = this->toFloat() * f.toFloat() * (1 << this->_bits);
	return (*this);
}

Fixed	Fixed::operator / (Fixed const &f) {
	this->_RawBits = (this->toFloat() / f.toFloat()) * (1 << this->_bits);
	return (*this);
}

Fixed	Fixed::operator++()
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->_RawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
