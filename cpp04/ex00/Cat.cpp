/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 11:33:48 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors, Destructors, and Assignment Operators

Cat::Cat(void) {
	std::cout << "Cat default contructor called\n";
	_type = "Cat";
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called\n";
	_type = other._type;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator = (Cat const &other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Mandatory Functions

void	Cat::makeSound(void) const {
	std::cout << "MEOW!\n";
}
