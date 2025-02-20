/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/19 15:28:47 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "\n";
	ScavTrap marco("marco");

	std::cout << "\n-----Print default parameters--------------------------\n";
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHealthPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";
	marco.guardGate();
	marco.attack("leon");
	std::cout << "\n";

	return (0);
}
