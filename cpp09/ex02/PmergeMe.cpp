/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/20 14:11:08 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void handleInput(char **argv, std::vector<unsigned int> &input) {
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
		input.push_back(n);
	}	
}


void addInputToNodes(std::vector<unsigned int> &input, std::vector<node> &nodes) {
	for (unsigned int n : input) {
		node temp;
		temp.largest = n;
		nodes.push_back(temp);
	}
}

std::vector<node> handlePairComparisons(std::vector<node> nodes) {
	unsigned int vector_size = nodes.size();
	std::vector<node> result;
	
	unsigned int i = 0;
	for (;i + 1 < vector_size; i += 2) {
		std::cout << "first = " << nodes[i].largest << " second = " << nodes[i + 1].largest << std::endl;
		if (nodes[i].largest > nodes[i + 1].largest) {
			node temp;
			temp.largest = nodes[i].largest;
			//temp.other.push_back
		}
	}
	if (vector_size % 2 == 1) {
		std::cout << "leftover = " << nodes[i].largest  << std::endl;
	}
}

void PmergeMe(char **argv) {
	std::vector<unsigned int> input;
	handleInput(argv, input);

	std::vector<node> nodes;
	addInputToNodes(input, nodes);

	std::vector<node> new_nodes;
	new_nodes = handlePairComparisons(nodes);
}
