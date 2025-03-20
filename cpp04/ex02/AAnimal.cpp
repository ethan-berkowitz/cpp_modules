/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/10 12:14:27 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors, Destructors, and Assignment Operators

AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << "AAnimal default contructor called\n";
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called\n";
}

AAnimal& AAnimal::operator = (AAnimal const &other) {
	std::cout << "AAnimal copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

std::string	AAnimal::getType(void) const {
	return (_type);
}
