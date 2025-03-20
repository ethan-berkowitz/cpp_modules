/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:29:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructors and Destructors

FragTrap::FragTrap(void) : ClapTrap("Default FragTrap", 100, 100, 30) {
	std::cout << "FragTrap was constructed\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap was constructed with name " << name << "\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other._name, 
													other._hit_points, 
													other._energy_points, 
													other._attack_damage) {
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator = (FragTrap const &other) {
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap was destroyed\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "Positive high fives are distributed among all nearby guys\n";
}

void FragTrap::attack(const std::string& target) {
	if (_energy_points > 0 && _hit_points > 0) {
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else if (_hit_points <= 0)
		std::cout << "FragTrap " << _name << " cannot attack. " << _name << " is dead.\n";
	else
		std::cout << "FragTrap " << _name << " cannot attack. " << _name << " is low on energy.\n";
}
