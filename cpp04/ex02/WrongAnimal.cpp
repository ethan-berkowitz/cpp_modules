/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 10:44:55 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors, Destructors, and Assignment Operators

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default contructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator = (WrongAnimal const &other) {
	std::cout << "WrongAnimal copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "UNDEFINED WrongAnimal NOISE\n";
}
