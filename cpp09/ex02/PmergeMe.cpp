/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/21 11:42:49 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void handleInput(char **argv, Info &info) {
	for (int i = 1; argv[i]; i++) {
		unsigned long temp;
		try {
			temp = std::stoul(argv[i]);
		} catch (...) {
			throw std::runtime_error("Error: invalid input");
		}
		if (temp > std::numeric_limits<unsigned int>::max()) {
			throw std::runtime_error("Error: input is not an unsigned int");
		}
		unsigned int n = static_cast<unsigned int>(temp);
		info.input.push_back(n);
	}	
}


// void addInputToNodes(std::vector<unsigned int> &input, std::vector<node> &nodes) {
// 	for (unsigned int n : input) {
// 		node temp;
// 		temp.largest = n;
// 		nodes.push_back(temp);
// 	}
// }

// std::vector<node> handlePairComparisons(std::vector<node> nodes) {
// 	unsigned int vector_size = nodes.size();
// 	std::vector<node> result;
	
// 	unsigned int i = 0;
// 	for (;i + 1 < vector_size; i += 2) {
// 		std::cout << "first = " << nodes[i].largest << " second = " << nodes[i + 1].largest << std::endl;
// 		if (nodes[i].largest > nodes[i + 1].largest) {
// 			node temp;
// 			temp.largest = nodes[i].largest;
// 			//temp.other.push_back
// 		}
// 	}
// 	if (vector_size % 2 == 1) {
// 		std::cout << "leftover = " << nodes[i].largest  << std::endl;
// 	}
// }

void getMaxLevel(Info &info) {
	while (pow(2, info.maxLevel) <= info.inputSize / 2) {
		info.maxLevel++;
	}
}

void swapGivenRange(Info &info, unsigned int start, unsigned int range) {
	
}

void handleComparisons(Info &info) {

	unsigned int lookAhead = pow(2, info.level);
	unsigned int disA = lookAhead / 2 - 1;
	unsigned int disB = lookAhead - 1;

	for (unsigned int i = 0; i + lookAhead - 1 < info.inputSize; i += lookAhead) {
		std::cout << "value = " << info.input[i] << " level = " << info.level
		<< " lookAhead = " << lookAhead
		<< " disA = " << info.input[i + disA]
		<< " disB = " << info.input[i + disB];

		std::cout << " swap = ";
		if (info.input[i + disA] > info.input[i + disB]) {
			std::cout << "YES";
			info.comparisons++;
			swapGivenRange(info, i, lookAhead);
		}
		else {
			std::cout << "NO";
		}
		std::cout << std::endl;
	}
	if (info.level < info.maxLevel) {
		std::cout << "--------------------------------------------------------------\n";
		info.level++;
		handleComparisons(info);
	}
}

void PmergeMe(char **argv) {
	Info info;

	handleInput(argv, info);
	info.inputSize = info.input.size();
	getMaxLevel(info);
	handleComparisons(info);
	std::cout << "--------------------------------------------------------------\n";
	std::cout << "comparisons = " << info.comparisons << std::endl;

	// std::vector<node> nodes;
	// addInputToNodes(input, nodes);

	// std::vector<node> new_nodes;
	// new_nodes = handlePairComparisons(nodes);
}
