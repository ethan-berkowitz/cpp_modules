/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/21 16:56:01 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout
#include <vector> // vector
#include <limits> // numeric_limits
#include <cmath> // pow
#include <algorithm> // swap

#define SWAP_DEBUG true
#define INSERTION_DEBUG true

struct Element {
	unsigned int value;
	unsigned int match;
};

struct Info {
	std::vector<unsigned int > input;
	unsigned int maxLevel = 1;
	unsigned int level = 1;
	unsigned int inputSize;
	unsigned int comparisons;

    const std::string red     = "\033[31m";
    const std::string green   = "\033[32m";
    const std::string yellow  = "\033[33m";
    const std::string blue    = "\033[34m";
    const std::string magenta = "\033[35m";
    const std::string cyan    = "\033[36m";
    const std::string reset   = "\033[0m";
};

// struct node {
//     unsigned int largest;
// 	std::vector<unsigned int> other;
// 	unsigned int level = 0;
// 	std::string type = "pair";
// };

void PmergeMe(char **argv);
