/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/10 12:14:27 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors, Destructors, and Assignment Operators

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal default contructor called\n";
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called\n";
}

Animal& Animal::operator = (Animal const &other) {
	std::cout << "Animal copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::makeSound(void) const {
	std::cout << "UNDEFINED ANIMAL NOISE\n";
}
