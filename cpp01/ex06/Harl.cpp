/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:49:19 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/30 18:08:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::_debug(void) {
	std::cout << "I love extra bacon on my debug\n";	
}

void Harl::_info(void) {
	std::cout << "Bacon sure is expensive on my info\n";	
}

void Harl::_warning(void) {
	std::cout << "I deserve some free bacon on my warning\n";	
}

void Harl::_error(void) {
	std::cout << "I want to speak to the bacon manager for my error\n";
}

void Harl::complain(std::string level) {
	std::string level_array[]{"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for(size_t i = 0; i < 4; i++) {
		if (level == level_array[i]) {
			switch(i) {
				case 0:
					(this->*fptr[0])();
				case 1:
					(this->*fptr[1])();
				case 2:
					(this->*fptr[2])();
				case 3:
					(this->*fptr[3])();
			}
			return ;
		}
	}
	std::cout << "Not a valid level\n";
}
