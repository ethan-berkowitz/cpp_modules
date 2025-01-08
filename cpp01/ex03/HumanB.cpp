/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:47:04 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/30 18:00:43 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = nullptr;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
