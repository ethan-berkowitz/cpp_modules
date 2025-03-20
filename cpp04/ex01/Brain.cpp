/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/10 10:44:57 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors, Destructors, and Assignment Operators

Brain::Brain(void) {
	std::cout << "Brain default contructor called\n";
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator = (Brain const &other) {
	std::cout << "Brain copy assignment operator called\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}
