/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/20 15:42:21 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors and Destructors

ClapTrap::ClapTrap(void) {
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << "ClapTrap was constructed\n";
}

ClapTrap::ClapTrap(std::string name) {
	setName(name);
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << "ClapTrap was constructed with name " << name << "\n";
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap was destroyed\n";
}

//Getters and Setters

void ClapTrap::setHitPoints(int hit_points) {
	_hit_points = hit_points;
}
int ClapTrap::getHitPoints(void) {
	return (_hit_points);
}
void ClapTrap::setEnergyPoints(int energy_points) {
	_energy_points = energy_points;
}
int ClapTrap::getEnergyPoints(void) {
	return (_energy_points);
}
void ClapTrap::setAttackDamage(int attack_damage) {
	_attack_damage = attack_damage;
}
int ClapTrap::getAttackDamage(void) {
	return (_attack_damage);
}
void ClapTrap::setName(std::string name) {
	_name = name;
}
std::string ClapTrap::getName(void) {
	return (_name);
}

//Mandatory Functions

void ClapTrap::takeDamage(unsigned int amount) {
	setHitPoints(getHitPoints() - amount);
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " heals " << amount << " health points!\n";
	}
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " cannot repair. " << getName() << " is dead.\n";
	else
		std::cout << "ClapTrap " << getName() << " cannot repair. " << getName() << " is low on energy.\n";
}

void ClapTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	}
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << " cannot attack. " << getName() << " is dead.\n";
	else
		std::cout << "ClapTrap " << getName() << " cannot attack. " << getName() << " is low on energy.\n";
}
