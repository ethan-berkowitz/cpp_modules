/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:21:04 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors and Destructors

ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap was constructed\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hit_points(10),
										_energy_points(10),
										_attack_damage(0) {
	std::cout << "ClapTrap was constructed with name " << name << "\n";
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad) : _name(name),
																_hit_points(hp),
																_energy_points(ep),
																_attack_damage(ad) {
	std::cout << "ClapTrap was constructed with name " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
											_hit_points(other._hit_points),
											_energy_points(other._energy_points),
											_attack_damage(other._attack_damage) {
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap& ClapTrap::operator = (ClapTrap const &other) {
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
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
	_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points > 0 && _hit_points > 0) {
		_hit_points += amount;
		_energy_points -= 1;
		std::cout << "ClapTrap " << _name << " heals " << amount << " health points!\n";
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " cannot repair. " << _name << " is dead.\n";
	else
		std::cout << "ClapTrap " << _name << " cannot repair. " << _name << " is low on energy.\n";
}

void ClapTrap::attack(const std::string& target) {
	if (_energy_points > 0 && _hit_points > 0) {
		_energy_points -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack. " << _name << " is dead.\n";
	else
		std::cout << "ClapTrap " << _name << " cannot attack. " << _name << " is low on energy.\n";
}
