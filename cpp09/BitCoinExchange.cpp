/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/13 15:34:22 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

void getRawInputFile(std::map<std::string, std::string> &raw_input, std::string filename) {
	(void)raw_input;

	std::ifstream input_file(filename);
	if (!input_file) {
		throw std::runtime_error("Could not open file");
	}

	std::string line;
	while (std::getline(input_file, line)) {
		std::cout << line << std::endl;
	}
}

void btc(std::string filename) {
	// Convert input.txt to map
	
	std::map<std::string, std::string> raw_input;

	getRawInputFile(raw_input, filename);

	for (auto &pair : raw_input) {
		std::cout << pair.first << " , " << pair.second << std::endl;
	}

		// Use gettime to convert string to day, month, year
		// Check for bad dates
			// Use mktime to check for bad leap year
			// If date is invalid, just throw error if when that SPECIFIC date is checked
				// don't close the whole program
	
	

	// Convert data.csv to map
		// Use gettime to convert string to day, month, year
		// Check for bad dates
			// Use mktime to check for bad leap year
		// Throw exception and end program for ANY parsing problems
	
	// Apply date from one to the other and do math
		// Use lowerbound to get next lowest date if date is too high
		// Error for date too low
	
}
