/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 11:33:48 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors, Destructors, and Assignment Operators

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default contructor called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "WrongCat copy constructor called\n";
	_type = other._type;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator = (WrongCat const &other) {
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

void	WrongCat::makeSound(void) const {
	std::cout << "WRONG MEOW!\n";
}
