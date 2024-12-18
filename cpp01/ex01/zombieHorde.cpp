/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:57:35 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/17 12:32:33 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)	{
		horde[i].set_name(name);
	}
	return (horde);
}
