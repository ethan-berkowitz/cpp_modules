/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/20 15:53:00 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Constructors and Destructors

ScavTrap::ScavTrap(void) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap was constructed\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap was constructed with name " << name << "\n";
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap was destroyed\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHitPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "ScavTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
