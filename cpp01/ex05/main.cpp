/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/06 11:28:05 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	
	std::cout << "-----------DEBUG-----------\n";
	harl.complain("DEBUG");
	std::cout << "-----------INFO------------\n";
	harl.complain("INFO");
	std::cout << "----------WARNING----------\n";
	harl.complain("WARNING");
	std::cout << "-----------ERROR-----------\n";
	harl.complain("ERROR");
	std::cout << "----------INVALID----------\n";
	harl.complain("INVALID_LEVEL");

	return (0);
}
