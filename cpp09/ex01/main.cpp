/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/19 15:46:13 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "Error: no arguments." << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cout << "Error: too many arguments." << std::endl;
		return 1;	
	}
	
	try {
		RPN(argv[1]);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
