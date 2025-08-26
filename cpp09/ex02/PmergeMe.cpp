/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/26 10:52:47 by eberkowi         ###   ########.fr       */
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
	unsigned int width = 2;
	for (unsigned int j = 0; j < info.inputSize; j++) {
		if (j == first || j == second) {
			if (swapped == true)
				std::cout << std::setw(width) << info.green << info.input[j] << " ";
			else
				std::cout << std::setw(width) << info.red << info.input[j] << " ";
		}
		else {
			std::cout << std::setw(width) << info.reset << info.input[j] << " ";
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
		if (SWAP_DEBUG) {
			std::cout << std::endl;
		}
		info.level++;
		handleComparisons(info);
	}
}

void printInsertVectors(Info &info,
					std::vector<Element> &main,
					std::vector<Element> &pend,
					std::vector<unsigned int> &nonParticipating) {

	unsigned int width = 2;

	// PRINT PEND

	std::cout << info.reset << "pend.value      : ";
	for (unsigned int i = 0; i < pend.size(); i++) {
		std::cout << std::setw(width) << pend[i].value << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "pend.matchLetter: ";
	for (unsigned int i = 0; i < pend.size(); i++) {
		std::cout << std::setw(width) << pend[i].matchLetter << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "pend.matchNumber: ";
	for (unsigned int i = 0; i < pend.size(); i++) {
		if (pend[i].matchNumber == 0) {
			std::cout << std::setw(width) <<  "-" << " ";
		}
		else {
			std::cout << std::setw(width) <<  pend[i].matchNumber << " ";
		}
	}
	std::cout << std::endl << std::endl;
	
	// PRINT MAIN

	std::cout << info.reset << "main.value      : ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << std::setw(width) << main[i].value << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "main.matchLetter: ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << std::setw(width) <<  main[i].matchLetter << " ";
	}
	std::cout << std::endl;

	std::cout << info.reset << "main.matchNumber: ";
	for (unsigned int i = 0; i < main.size(); i++) {
		if (main[i].matchNumber == 0) {
			std::cout << std::setw(width) <<  "-" << " ";
		}
		else {
			std::cout << std::setw(width) <<  main[i].matchNumber << " ";
		}
	}
	std::cout << std::endl << std::endl;


	//PRINT NON-PARTICIPATING

	std::cout << info.reset << "nonPartici.value: ";
	for (unsigned int value : nonParticipating) {
		std::cout << std::setw(width) << info.reset << value << " ";
	}
	std::cout << std::endl << std::endl;

}

void addFirstTwoGroupsToMain(Info &info,
							std::vector<Element> &main,
							unsigned int &range) {
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

void addmatches(std::vector<Element> &main, std::vector<Element> &pend, unsigned int groupSize) {
	unsigned int mainSize = main.size();
	unsigned int pendSize = pend.size();

	// Add to main

	unsigned int matchNumber = 1;
	main[groupSize - 1].matchNumber = matchNumber;
	main[groupSize - 1].matchLetter = 'b';
	for (unsigned int i = groupSize; i < mainSize; i += groupSize) {
		main[i + groupSize - 1].matchNumber = matchNumber;
		main[i + groupSize - 1].matchLetter = 'a';
		matchNumber++;
	}

	// Add to pend

	matchNumber = 2;
	for (unsigned int i = 0; i < pendSize; i += groupSize) {
		pend[i + groupSize - 1].matchNumber = matchNumber;
		pend[i + groupSize - 1].matchLetter = 'b';
		matchNumber++;
	}
}

int findIndexOfJacobNumber(unsigned int j,
							unsigned int groupSize,
							unsigned int &index,
							std::vector<Element> &elements) {
	for (index = groupSize - 1; index < elements.size(); index += 1) {
		if (j == elements[index].matchNumber) {
			return true;
		}
	}
	return false;
}

unsigned int findInsertionIndex(Info &info,
					unsigned int value,
					unsigned int lower,
					unsigned int upper,
					unsigned int groupSize,
					std::vector<Element> &main) {
	
	// Check if we found the index

	if (upper == lower) {
		info.comparisons++;
		if (value < main[lower].value) {
			return lower;
		}
		else {
			return lower + groupSize;
		}
	}

	// Debug
	
	std::cout << "lower = " << lower << ", upper = " << upper << ", ";

	// Find middle index

	unsigned int groups_between = (upper - lower) / groupSize;
	unsigned int middle_index = lower + ((groups_between / 2) * groupSize);
	std::cout << "middle = " << middle_index << ", ";
	
	// Compare value to value at middle index

	info.comparisons++;
	if (value < main[middle_index].value) {
		if ((int)middle_index - (int)groupSize < 0){
			upper = lower;
		}
		else {
			upper = middle_index - groupSize;
		}
	}
	else {
		lower = middle_index + groupSize;
	}
	std::cout << std::endl;

	return findInsertionIndex(info, value, lower, upper, groupSize, main);

	
}

void insertToMain(unsigned int pend_index,
					unsigned int insert_index,
					unsigned int groupSize,
					std::vector<Element> &main,
					std::vector<Element> &pend
					) {

	// Set starting position of pend and insert

	unsigned int pend_start = pend_index - groupSize + 1;
	std::cout << "\033[32m" << "pend_start = " << pend_start << "\n";
	unsigned int insert_start = insert_index - groupSize + 1;
	std::cout << "\033[32m" << "insert_start = " << insert_start << "\n";

	// Hold on to main values that we want to shift

	std::vector<Element> temp;
	for (unsigned int i = insert_start; i < main.size(); i++) {
		Element element;
		element.matchLetter = main[i].matchLetter;
		element.matchNumber = main[i].matchNumber;
		element.value = main[i].value;
		temp.push_back(element);
	}

	// Print temp for debug

	std::cout << "temp = ";
	for (unsigned int i = 0; i < temp.size(); i++) {
		std::cout << temp[i].value << " ";
	}
	std::cout << std::endl;

	// Remove shifting values from main

	unsigned int size = main.size();
	for (unsigned int i = insert_start; i < size; i++) {
		main.pop_back();
	}

	// Print main for debug

	std::cout << "main_after_remove = ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << main[i].value << " ";
	}
	std::cout << std::endl;

	// Insert pend group into main

	for (unsigned int i = 0; i < groupSize; i++) {
		Element element;
		element.matchLetter = pend[i + pend_start].matchLetter;
		element.matchNumber = pend[i + pend_start].matchNumber;
		element.value = pend[i + pend_start].value;
		main.push_back(element);
	}

	// Print main for debug

	std::cout << "main_after_insert = ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << main[i].value << " ";
	}
	std::cout << std::endl;

	// Add back the shifted main values

	for (unsigned int i = 0; i < temp.size(); i++) {
		main.push_back(temp[i]);
	}

	// Print main for debug

	std::cout << "main_after_remain = ";
	for (unsigned int i = 0; i < main.size(); i++) {
		std::cout << main[i].value << " ";
	}
	std::cout << std::endl;

	//Remove elements from pend

	pend.erase(pend.begin() + pend_start, pend.begin() + pend_index + 1);



	

}

void handleBinaryInsertion(Info& info,
							std::vector<Element> &main,
							std::vector<Element> &pend,
							unsigned int groupSize,
							std::vector<unsigned int> &nonParticipating) {

	std::cout << std::endl;
	// Loop through jacobsthal numbers
	for (unsigned int i = 1; i < 3; i++) { //CHANGE < 3 to size of jacobsthal array
		for (unsigned int j = info.jacobsthal[i]; j > info.jacobsthal[i - 1]; j--) {

			// Check for empty pend

			if (pend.size() == 0) {
				return;
			}
			
			// Find matching index for jacob in pend
			unsigned int pend_index;
			if (findIndexOfJacobNumber(j, groupSize, pend_index, pend)) {
				printInsertVectors(info, main, pend, nonParticipating);
				std::cout << "value = " << pend[pend_index].value << ", ";
				// Find matching index for jacob in main
				unsigned int main_index;
				unsigned int insert_index;
				if (findIndexOfJacobNumber(j, groupSize, main_index, main)) {
					std::cout << "main = " << main_index << ",\n";
					insert_index = findInsertionIndex(info, pend[pend_index].value,
													groupSize - 1, main_index - groupSize,
													groupSize, main);
				}
				else {
					std::cout << "main = " << "--,\n";
					insert_index = findInsertionIndex(info, pend[pend_index].value,
													groupSize - 1, main.size() - 1,
													groupSize, main);
				}
				std::cout << "insert_index = " << insert_index << std::endl;
				insertToMain(pend_index, insert_index, groupSize, main, pend);
			}
			else {
				std::cout << "--------,\n";
			}
			std::cout << info.reset << "\n\n";
		}
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
	addmatches(main, pend, range / 2);
	handleBinaryInsertion(info, main, pend, range / 2, nonParticipating);

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

	std::cout << info.yellow << "Comparisons = " << info.comparisons << std::endl;
}
