/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:57:35 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/30 17:17:59 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::set_name(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) {
	this->set_name(name);
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " was destroyed\n";
}

