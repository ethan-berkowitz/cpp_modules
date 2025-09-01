/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/26 17:16:24 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	auto start = std::chrono::high_resolution_clock::now();
	if (argc == 1) {
		std::cout << "Error: no arguments." << std::endl;
		return 1;
	}
	try {
		PmergeMe(argv);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
	
	return 0;
}
