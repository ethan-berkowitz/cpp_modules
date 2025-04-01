/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/01 11:46:51 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//Constructors and Destructors

Data::Data(void) : _name("default_name") {}

Data::Data(std::string name) : _name(name) {}

Data::Data(const Data &other) : _name(other._name) {}

Data& Data::operator = (Data const &other) {
	if (this != &other)
		_name = other._name;
	return (*this);
}

Data::~Data(void) {}

std::string Data::getName() {
	return (_name);
}
