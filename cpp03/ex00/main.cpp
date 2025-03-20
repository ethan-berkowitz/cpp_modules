/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:20:15 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	// Print default parameters
	std::cout << "\n-----Print default parameters--------------------------\n\n";
	ClapTrap marco("marco");
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHitPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";
	
	// Test getters and setters
	std::cout << "\n-----Test getters and setters--------------------------\n\n";
	marco.setHitPoints(20);
	marco.setEnergyPoints(30);
	marco.setAttackDamage(5);
	std::cout << "name: " <<  marco.getName() << "\n";
	std::cout << "health: " <<  marco.getHitPoints() << "\n";
	std::cout << "energy: " <<  marco.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  marco.getAttackDamage() << "\n";

	// Test Repair and Damage
	std::cout << "\n-----Test Repair and Damage----------------------------\n\n";
	ClapTrap finnan("finnan");
	finnan.setAttackDamage(5);
	finnan.attack("marco");
	marco.takeDamage(finnan.getAttackDamage());
	std::cout << "health after damage: " <<  marco.getHitPoints() << "\n";
	marco.beRepaired(5);
	std::cout << "health after repair: " <<  marco.getHitPoints() << "\n";

	// Test death status
	std::cout << "\n-----Test death status---------------------------------\n\n";
	finnan.setAttackDamage(50);
	finnan.attack("marco");
	marco.takeDamage(finnan.getAttackDamage());
	std::cout << "health after damage: " <<  marco.getHitPoints() << "\n";
	marco.attack("finnan");
	marco.beRepaired(5);
	std::cout << "health after repair: " <<  marco.getHitPoints() << "\n";

	// Test energy points
	std::cout << "\n-----Test energy points--------------------------------\n\n";
	finnan.setEnergyPoints(1);
	finnan.beRepaired(5);
	finnan.attack("marco");
	finnan.beRepaired(5);

	//Copy Tests
	std::cout << "\n-----Copy Tests----------------------------------------\n\n";
	ClapTrap adam("adam");

	adam.setHitPoints(42);
	adam.setEnergyPoints(43);
	adam.setAttackDamage(44);

	ClapTrap bob(adam);
	ClapTrap colin("colin");
	colin = adam;

	std::cout << "name: " <<  bob.getName() << "\n";
	std::cout << "health: " <<  bob.getHitPoints() << "\n";
	std::cout << "energy: " <<  bob.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  bob.getAttackDamage() << "\n";
	std::cout << "name: " <<  colin.getName() << "\n";
	std::cout << "health: " <<  colin.getHitPoints() << "\n";
	std::cout << "energy: " <<  colin.getEnergyPoints() << "\n";
	std::cout << "attack: " <<  colin.getAttackDamage() << "\n";

	std::cout << "\n-------------------------------------------------------\n\n";
	return (0);
}
