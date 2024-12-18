/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:23 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/17 12:46:49 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void) {
	Zombie *horde = nullptr;
	int num_of_zombies = 4000;

	horde = zombieHorde(num_of_zombies, "Peter");
	for (int i = 0; i < num_of_zombies; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}
