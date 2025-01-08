/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:23 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/31 09:54:58 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *horde = nullptr;
	int num_of_zombies = 10;

	horde = zombieHorde(num_of_zombies, "Peter");
	for (int i = 0; i < num_of_zombies; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
