/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/26 17:19:33 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout
#include <iomanip> // std::setw
#include <vector> // vector
#include <limits> // numeric_limits
#include <cmath> // pow
#include <algorithm> // swap
#include <cstdlib> // random number generation in debugging
#include <ctime> // random number generation in debugging
#include <chrono>

#define SWAP_DEBUG					false
#define INSERTION_DEBUG				false
#define INSERTION_EXTRA_DEBUG		false
#define PRINT_MAIN_AND_PEND_DEBUG	false
#define MAIN_DEBUG					false
#define PRINT_STARTING_INPUT		true
#define PRINT_EXPECTED_COMPARISONS	true
#define PRINT_CHECK_FOR_SORTED		true

#define GENERATE_RANDOM_INPUT		true
#define NUM_OF_VALUES				3000
#define RANGE_OF_VALUES				100000

struct Element {
	unsigned int value;
	unsigned int matchNumber = 0;
	char matchLetter = '-';
};

struct Info {
	std::vector<unsigned int > input;
	unsigned int maxLevel = 1;
	unsigned int level = 1;
	unsigned int inputSize;
	unsigned int comparisons = 0;
	unsigned int expectedComparisons;
	const unsigned int jacobsthal[16] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
										1365, 2731, 5461, 10923, 21845, 43691};

    const std::string red     = "\033[31m";
    const std::string green   = "\033[32m";
    const std::string yellow  = "\033[33m";
    const std::string blue    = "\033[34m";
    const std::string magenta = "\033[35m";
    const std::string cyan    = "\033[36m";
    const std::string reset   = "\033[0m";
};

void PmergeMe(char **argv);
