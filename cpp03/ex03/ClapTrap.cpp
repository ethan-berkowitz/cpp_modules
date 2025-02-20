/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/18 14:14:57 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors and Destructors

ClapTrap::ClapTrap(void) {
	this->setHealthPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	std::cout << "ClapTrap was constructed\n";
}

ClapTrap::ClapTrap(std::string name) {
	this->setName(name);
	this->setHealthPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	std::cout << "ClapTrap was constructed with name " << name << "\n";
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap was destroyed\n";
}

//Getters and Setters

void ClapTrap::setHealthPoints(int health_points) {
	this->_health_points = health_points;
}
int ClapTrap::getHealthPoints(void) {
	return (this->_health_points);
}
void ClapTrap::setEnergyPoints(int energy_points) {
	this->_energy_points = energy_points;
}
int ClapTrap::getEnergyPoints(void) {
	return (this->_energy_points);
}
void ClapTrap::setAttackDamage(int attack_damage) {
	this->_attack_damage = attack_damage;
}
int ClapTrap::getAttackDamage(void) {
	return (this->_attack_damage);
}
void ClapTrap::setName(std::string name) {
	this->_name = name;
}
std::string ClapTrap::getName(void) {
	return (this->_name);
}

//Mandatory Functions

void ClapTrap::takeDamage(unsigned int amount) {
	setHealthPoints(getHealthPoints() - amount);
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHealthPoints() > 0) {
		setHealthPoints(getHealthPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " heals " << amount << " health points!\n";
	}
	else if (getHealthPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " cannot repair. " << getName() << " is dead.\n";
	else
		std::cout << "ClapTrap " << getName() << " cannot repair. " << getName() << " is low on energy.\n";
}

void ClapTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHealthPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHealthPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "ClapTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
