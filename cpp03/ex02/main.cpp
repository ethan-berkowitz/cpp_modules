/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:30:50 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap Franky("Franky");
	std::cout << "name: " <<  Franky.getName() << "\n";
	std::cout << "health: " <<  Franky.getHitPoints() << "\n";
	std::cout << "energy: " <<  Franky.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  Franky.getAttackDamage() << "\n";
	Franky.highFivesGuys();
	Franky.attack("Peter");

	return (0);
}
