/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/18 12:04:06 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

// void applyData(std::string filename) {
// 	// Get raw input file
// 	std::ifstream input_file(filename);
// 	if (!input_file) {
// 		throw std::runtime_error("Could not open input file");
// 	}

// 	// Get lines from input file stream
// 	std::string line;
// 	size_t end;
// 	while (std::getline(input_file, line)) {
// 		if ((end = line.find(" | ", 0)) != std::string::npos) {
// 			std::cout << line << std::endl;

// 			// Convert date to tm
// 			std::istringstream temp_stream(line.substr(0, end));
// 			tm time;
// 			temp_stream >> std::get_time(&time, "%Y-%m-%d");
// 			std::cout << "    " << time.tm_year + 1900 << " " << time.tm_mon + 1 << " " << time.tm_mday << std::endl;

// 			// Convert value to float
// 			std::string temp_str(line.substr(end + 3));
// 			std::cout << "    " << temp_str << std::endl;
// 			float temp_float;
// 			try {
// 				temp_float = std::stof(temp_str);
// 			} catch (...){
// 				std::cout << "    " << "Invalid value" << std::endl;
// 			}
// 			std::cout << "    " << temp_float << std::endl;
			
// 		}
// 		else {
// 			std::cout << line << "\n\n\n";
// 		}
// 	}
// }

bool validate_date(std::tm date) {
	std::tm converted_date{};
	converted_date = date;
	std::mktime(&converted_date);
	if (converted_date.tm_year != date.tm_year
		|| converted_date.tm_mon != date.tm_mon
		|| converted_date.tm_mday != date.tm_mday) {
		return false;
	} 
	return true;
}

void parseData(std::map<std::string, float> &data) {
	(void)data;
	
	// Get data file

	std::ifstream data_file("data.csv");
	if (!data_file) {
		throw std::runtime_error("Could not open data file");
	}

	// Verify first line
	
	std::string line;
	std::getline(data_file, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Error: data.csv header is malformed");
	}

	// Get lines from input file stream

	size_t end;
	while (std::getline(data_file, line)) {
		if ((end = line.find(",", 0)) == std::string::npos) {
			throw std::runtime_error("Error: data.csv is missing a comma delimiter");
		}
		std::cout << line << std::endl;

		// Convert date to tm

		std::istringstream temp_stream(line.substr(0, end));
		std::string date_string = temp_stream.str();
		std::tm time{};
		temp_stream >> std::get_time(&time, "%Y-%m-%d");
		std::cout << "    " << time.tm_year + 1900 << " " << time.tm_mon + 1 << " " << time.tm_mday << std::endl;

		// TODO Validate date

		 if (!validate_date(time)) {
			throw std::runtime_error("Error: Invalid date");
		 }

		// Convert exchange rate to float

		std::string temp_str(line.substr(end + 1));
		std::cout << "    " << temp_str << std::endl;
		float exchange_rate;
		try {
			exchange_rate = std::stof(temp_str);
		} catch (...){
			std::cout << "    " << "Invalid value" << std::endl;
		}
		std::cout << "    " << exchange_rate << std::endl;

		// Add valid data to map

		data[date_string] = exchange_rate;
	}
}

void btc(std::string filename) {
	(void)filename;
	std::map<std::string, float> data;
	parseData(data);
	
	//applyData(filename);
}

// Convert input.txt to map
	// Use gettime to convert string to day, month, year
	// Check for bad dates
		// Use mktime to check for bad leap year or bad date in general
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
