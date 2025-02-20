/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/19 15:33:29 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructors and Destructors

FragTrap::FragTrap(void) {
	this->setHealthPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap was constructed\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setName(name);
	this->setHealthPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap was constructed with name " << name << "\n";
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap was destroyed\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "Positive high fives are distributed among all nearby guys\n";
}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHealthPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHealthPoints() <= 0)
		std::cout << "FragTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "FragTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
