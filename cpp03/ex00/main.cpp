/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/18 14:09:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap marco("marco");
	ClapTrap finnan("finnan");
	
	std::cout << "\n-----Print default parameters--------------------------\n";
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHealthPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";
	
	// Test getters and setters
	marco.setHealthPoints(20);
	marco.setEnergyPoints(30);
	marco.setAttackDamage(5);
	std::cout << "\n-----Test getters and setters--------------------------\n";
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHealthPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";

	// Test Repair and Damage
	std::cout << "\n-----Test Repair and Damage----------------------------\n";
	finnan.setAttackDamage(5);
	finnan.attack("marco");
	marco.takeDamage(finnan.getAttackDamage());
	std::cout << "health after damage: " <<  marco.getHealthPoints() << "\n";
	marco.beRepaired(5);
	std::cout << "health after repair: " <<  marco.getHealthPoints() << "\n";

	// Test death status
	std::cout << "\n-----Test death status---------------------------------\n";
	finnan.setAttackDamage(50);
	finnan.attack("marco");
	marco.takeDamage(finnan.getAttackDamage());
	std::cout << "health after damage: " <<  marco.getHealthPoints() << "\n";
	marco.attack("finnan");
	marco.beRepaired(5);
	std::cout << "health after repair: " <<  marco.getHealthPoints() << "\n";

	// Test energy points
	std::cout << "\n-----Test energy points--------------------------------\n";
	finnan.setEnergyPoints(1);
	finnan.beRepaired(5);
	finnan.attack("marco");
	finnan.beRepaired(5);

	std::cout << "\n-------------------------------------------------------\n";
	return (0);
}
