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
	_brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called\n";
	_type = other._type;
	_brain = new Brain();
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator = (Dog const &other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return (*this);
}

// Mandatory Functions

void	Dog::makeSound(void) const {
	std::cout << "BARK!\n";
}

void	Dog::setIdea(unsigned int n, std::string idea) {
	if (n >= 100)
		std::cout << "Dog Brain cannot hold more than 100 ideas\n";
	else
		_brain->_ideas[n] = idea;
}

std::string	Dog::getIdea(unsigned int n) {
	if (n >= 100)
		return ("Dog Brain cannot hold more than 100 ideas");
	else
		return (_brain->_ideas[n]);
}
