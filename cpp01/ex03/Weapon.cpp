/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:47:04 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/30 15:07:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string &Weapon::getType() {
	return (this->_type);
}

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}
