/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 11:33:48 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors, Destructors, and Assignment Operators

Dog::Dog(void) {
	std::cout << "Dog default contructor called\n";
	_type = "Dog";
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called\n";
	_type = other._type;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator = (Dog const &other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

void	Dog::makeSound(void) const {
	std::cout << "BARK!\n";
}
