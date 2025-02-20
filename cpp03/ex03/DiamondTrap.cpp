/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/19 15:33:29 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Constructors and Destructors

DiamondTrap::DiamondTrap(void) {
	this->setHealthPoints(FragTrap::_health_points);
	this->setEnergyPoints(ScavTrap::_energy_points);
	this->setAttackDamage(FragTrap::_attack_damage);
	std::cout << "DiamondTrap was constructed\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->setName(name);
	this->setHealthPoints(FragTrap::_health_points);
	this->setEnergyPoints(ScavTrap::_energy_points);
	this->setAttackDamage(FragTrap::_attack_damage);
	std::cout << "DiamondTrap was constructed with name " << name << "\n";
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap was destroyed\n";
}

void DiamondTrap::whoAmI() {
	std::cout << "Who am I?\n";
}

void DiamondTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHealthPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "DiamondTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHealthPoints() <= 0)
		std::cout << "DiamondTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "DiamondTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
