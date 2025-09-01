/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/09/01 11:19:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "Error: no arguments." << std::endl;
		return 1;
	}
	try {
		// auto start = std::chrono::high_resolution_clock::now();
		PmergeMe(argv);
		// auto end = std::chrono::high_resolution_clock::now();
		// std::chrono::duration<double> elapsed = end - start;
		// std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	
	return 0;
}
