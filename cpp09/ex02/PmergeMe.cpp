/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/21 17:24:40 by eberkowi         ###   ########.fr       */
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

void getMaxLevel(Info &info) {
	while (pow(2, info.maxLevel) <= info.inputSize / 2) {
		info.maxLevel++;
	}
}

void printInputAndHighlightSwaps (Info &info, unsigned int first, unsigned int second, bool swapped) {
	for (unsigned int j = 0; j < info.inputSize; j++) {
		if (j == first || j == second) {
			if (swapped == true)
				std::cout << info.green << info.input[j] << " ";
			else
				std::cout << info.red << info.input[j] << " ";
		}
		else {
			std::cout << info.reset << info.input[j] << " ";
		}
	}
	std::cout << std::endl;
}

void swapGivenRange(Info &info, unsigned int &start, unsigned int &range) {
	for (unsigned int i = 0; i < range / 2; i++) {
		std::swap(info.input[i + start], info.input[i + start + (range / 2)]);
	}
}

void handleComparisons(Info &info) {
	unsigned int range = pow(2, info.level);
	unsigned int disA = range / 2 - 1;
	unsigned int disB = range - 1;
	bool swapped = false;

	if (SWAP_DEBUG)
		std::cout << info.cyan << "Swap Level " << info.level << std::endl;
	for (unsigned int i = 0; i + range - 1 < info.inputSize; i += range) {
		info.comparisons++;
		if (info.input[i + disA] > info.input[i + disB]) {
			swapped = true;
			swapGivenRange(info, i, range);
		}
		else {
			swapped = false;
		}
		if (SWAP_DEBUG)
			printInputAndHighlightSwaps(info, i + disA, i + disB, swapped);
	}
	if (info.level < info.maxLevel) {
		std::cout << std::endl;
		info.level++;
		handleComparisons(info);
	}
}

void printInsertVectors(Info &info,
					std::vector<Element> &main,
					std::vector<Element> &pend,
					std::vector<unsigned int> &nonParticipating) {

	std::cout << info.reset << "main_value: ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << main[i].value << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "main_match: ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << main[i].match << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "pend_value: ";
	for (unsigned int i = 0; i < pend.size(); i++) {
		std::cout << pend[i].value << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "pend_match: ";
	for (unsigned int i = 0; i < pend.size(); i++) {
		std::cout << pend[i].match << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "nonParticipating_value: ";
	for (unsigned int value : nonParticipating) {
		std::cout << info.reset << value << " ";
	}
	std::cout << std::endl;

}

void addFirstTwoGroupsToMain(Info &info, std::vector<Element> &main, unsigned int &range) {
	for (unsigned int i = 0; i < range; i++) {
		Element temp;
		temp.value = info.input[i];
		main.push_back(temp);
	}
}

void addOtherGroups(Info &info,
					std::vector<Element> &main,
					std::vector<Element> &pend,
					std::vector<unsigned int> &nonParticipating,
					unsigned int &range) {

	unsigned int groupSize = range / 2;
	bool addToMain = false;

	// Alternate adding groups to pend and main starting with pend
	unsigned int i = range;
	for (; i + groupSize < info.inputSize; i += groupSize) {
		for (unsigned int j = 0; j < groupSize; j++) {
			Element temp;
			temp.value = info.input[i + j];
			if (addToMain) {
				main.push_back(temp);
			}
			else {
				pend.push_back(temp);
			}
		}
		addToMain = !addToMain;
	}

	// Add the rest to nonParticipating

	for (; i < info.inputSize; i++) {
		nonParticipating.push_back(info.input[i]);
	}
}

void addMatches(std::vector<Element> &main, std::vector<Element> &pend, unsigned int groupSize) {
	unsigned int mainSize = main.size();
	unsigned int pendSize = pend.size();

	// Add to main

	unsigned int match = 1;
	for (unsigned int i = 0; i < groupSize; i++) {
		main[i].match = match;
	}
	for (unsigned int i = groupSize; i < mainSize; i += groupSize) {
		for (unsigned int j = 0; j < groupSize; j++) {
			main[i + j].match = match;
		}
		match++;
	}

	// Add to pend

	match = 2;
	for (unsigned int i = 0; i < pendSize; i += groupSize) {
		for (unsigned int j = 0; j < groupSize; j++) {
			pend[i + j].match = match;
		}
		match++;
	}
}

void handleInsertion(Info &info) {
	if (info.level == 0) {
		return ;
	}
	if (INSERTION_DEBUG) {
		std::cout << info.cyan << "\nInsert Level " << info.level << std::endl; 
	}
	if (info.inputSize < pow(2, info.level) * 2) {
		info.level--;
		if (INSERTION_DEBUG) {
			std::cout << info.reset << "SKIP" << std::endl; 
		}
		handleInsertion(info);
		return ;
	}


	unsigned int range = pow(2, info.level);
	std::vector<Element> main;
	std::vector<Element> pend;
	std::vector<unsigned int> nonParticipating;

	addFirstTwoGroupsToMain(info, main, range);
	addOtherGroups(info, main, pend, nonParticipating, range);
	addMatches(main, pend, range / 2);
	printInsertVectors(info, main, pend, nonParticipating);



	info.level--;
	handleInsertion(info);
}

void initInfo(Info &info) {
	info.inputSize = info.input.size();
	getMaxLevel(info);
}

void PmergeMe(char **argv) {
	Info info;

	handleInput(argv, info);
	initInfo(info);
	handleComparisons(info);
	handleInsertion(info);

	std::cout << std::endl;
	std::cout << info.yellow << "Comparisons = " << info.comparisons << std::endl;

}
