/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/09/03 09:44:21 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

bool validate_leapyear(std::tm date) {
	struct std::tm test_date{};
	test_date = date;
	std::mktime(&test_date);
	if (test_date.tm_year != date.tm_year
		|| test_date.tm_mon != date.tm_mon
		|| test_date.tm_mday != date.tm_mday) {
		return false;
	} 
	return true;
}

bool validate_date(std::tm date, std::string date_string) {
	if (!validate_leapyear(date))
		return false;
	
	int year = date.tm_year + 1900;
	int month = date.tm_mon + 1;
	int day = date.tm_mday;
	
	std::string temp;
	if (year < 10) {
		temp = temp + "000" + std::to_string(year) + "-";
	}
	else if (year < 100) {
		temp = temp + "00" + std::to_string(year) + "-";
	}
	else if (year < 1000) {
		temp = temp + "0" + std::to_string(year) + "-";
	}
	else {
		temp = temp + std::to_string(year) + "-";
	}
	if (month < 10) {
		temp = temp + "0" + std::to_string(month) + "-";
	}
	else {
		temp = temp + std::to_string(month) + "-";
	}
	if (day < 10) {
		temp = temp + "0" + std::to_string(day);
	}
	else {
		temp = temp + std::to_string(day);
	}
	if (date_string == temp) {
		return (true);
	}
	return (false);
}



void applyData(std::string filename, std::map<std::string, float> &data) {

	(void)data;

	// Get raw input file

	std::ifstream input_file(filename);
	if (!input_file) {
		throw std::runtime_error("Could not open input file");
	}

	// Verify first line
	
	std::string line;
	std::getline(input_file, line);
	if (line != "date | value") {
		throw std::runtime_error("Error: input file header is malformed");
	}

	// Get lines from input file stream

	size_t end;
	while (std::getline(input_file, line)) {
		if ((end = line.find(" | ", 0)) != std::string::npos) {

			// Convert date to tm

			std::istringstream temp_stream(line.substr(0, end));
			std::string input_date = temp_stream.str();
			tm time;
			memset(&time, 0, sizeof(time));
			temp_stream >> std::get_time(&time, "%Y-%m-%d");

			// Validate date

			if (!validate_date(time, input_date)) {
				std::cout << "Error: invalid date" << std::endl;
				continue;
			}
			
			// Convert value to float and check for invalid float

			std::string temp_str(line.substr(end + 3));
			float input_float;
			try {
				input_float = std::stof(temp_str);
			} catch (...){
				std::cout << "Error: invalid value" << std::endl;
				continue;
			}
			if (input_float < 0) {
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (input_float > 1000) {
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}

			// Apply data to the input

			float result = 0;
			try {
				result = data.at(input_date) * input_float;
			} catch (...) {
				auto it = data.lower_bound(input_date);
				if (it == data.begin()) {
					std::cout << "Error: date is too low" << std::endl;
					continue;
				}
				else {
					--it;
					result = it->second * input_float;
				}
			}
			std::cout << input_date << " => " << input_float << " = " << result << std::endl;
		}
		else {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
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

		// Convert date to tm

		std::istringstream temp_stream(line.substr(0, end));
		std::string date_string = temp_stream.str();
		std::tm time{};
		memset(&time, 0, sizeof(time));
		temp_stream >> std::get_time(&time, "%Y-%m-%d");

		// Validate date

		 if (!validate_date(time, date_string)) {
			throw std::runtime_error("Error: Invalid date");
		 }

		// Convert exchange rate to float

		std::string temp_str(line.substr(end + 1));
		float exchange_rate;
		try {
			exchange_rate = std::stof(temp_str);
		} catch (...){
			std::cout << "    " << "Invalid value" << std::endl;
		}

		// Add valid data to map

		data[date_string] = exchange_rate;
	}
}

void btc(std::string filename) {
	std::map<std::string, float> data;
	parseData(data);
	applyData(filename, data);
}
