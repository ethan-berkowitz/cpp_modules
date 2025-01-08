/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:02 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/30 15:25:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;
	
	if (argc != 2) {
		std::cout << "Error: Incorrect number of args\n";
		return (1) ;
	}
	harl.complain(argv[1]);

	return (0);
}
