/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/19 15:23:21 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Constructors and Destructors

ScavTrap::ScavTrap(void) {
	this->setHealthPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap was constructed\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setName(name);
	this->setHealthPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap was constructed with name " << name << "\n";
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap was destroyed\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper model\n";
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHealthPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHealthPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "ScavTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
