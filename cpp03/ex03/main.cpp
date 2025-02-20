/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/20 11:06:23 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "\n";
	DiamondTrap marco("marco");

	std::cout << "\n-----Print default parameters--------------------------\n";
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHealthPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n"; //WRONG
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";
	marco.whoAmI();
	marco.attack("leon");
	std::cout << "\n";

	return (0);
}
