/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:25:04 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Constructors and Destructors

ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap", 100, 50, 20) {
	std::cout << "ScavTrap was constructed\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap was constructed with name " << name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other._name, 
													other._hit_points, 
													other._energy_points, 
													other._attack_damage) {
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator = (ScavTrap const &other) {
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap was destroyed\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
	if (_energy_points > 0 && _hit_points > 0) {
		_energy_points -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else if (_hit_points <= 0)
		std::cout << "ScavTrap " << _name << " cannot attack. " << _name << " is dead.\n";
	else
		std::cout << "ScavTrap " << _name << " cannot attack. " << _name << " is low on energy.\n";
}
