/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/20 15:54:35 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n";
	FragTrap marco("marco");

	std::cout << "\n-----Print default parameters--------------------------\n";
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHitPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";
	marco.highFivesGuys();
	marco.attack("sim");
	std::cout << "\n";

	return (0);
}
