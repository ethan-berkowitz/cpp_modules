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
#include "Brain.hpp"

// Constructors, Destructors, and Assignment Operators

Cat::Cat(void) {
	std::cout << "Cat default contructor called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called\n";
	_type = other._type;
	_brain = new Brain();
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator = (Cat const &other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return (*this);
}

// Mandatory Functions

void	Cat::makeSound(void) const {
	std::cout << "MEOW!\n";
}

void	Cat::setIdea(unsigned int n, std::string idea) {
	if (n >= 100)
		std::cout << "Cat Brain cannot hold more than 100 ideas\n";
	else
		_brain->_ideas[n] = idea;
}

std::string	Cat::getIdea(unsigned int n) {
	if (n >= 100)
		return ("Cat Brain cannot hold more than 100 ideas");
	else
		return (_brain->_ideas[n]);
}
