/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/13 14:37:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cout << "Error: too many arguments." << std::endl;
		return 1;	
	}
	
	BitCoinExchange btc(argv[1]);

	std::cout << btc.filename << std::endl;	
}
