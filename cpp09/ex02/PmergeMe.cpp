/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/09/03 11:44:59 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ----------------------------------------------------------------------------
// VECTOR AND SHARED ----------------------------------------------------------
// ----------------------------------------------------------------------------


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

void printInputAndHighlightSwaps (Info &info,
	unsigned int first,
	unsigned int second, bool swapped) {

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

void handleSwaps(Info &info) {
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
		handleSwaps(info);
	}
}

void printInsertVectors(Info &info,
					std::vector<Element> &main,
					std::vector<Element> &pend,
					std::vector<unsigned int> &nonParticipating) {
	
	if (PRINT_MAIN_AND_PEND_DEBUG == false) {
		return;
	}

	unsigned int width = 2;

	std::cout << info.reset << "------------------------------------------------------------\n";

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
	
	if (INSERTION_EXTRA_DEBUG) {		
		std::cout << info.reset << "nonPartici.value: ";
		for (unsigned int value : nonParticipating) {
			std::cout << std::setw(width) << info.reset << value << " ";
		}
		std::cout << std::endl;
	}

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
	for (; i + groupSize - 1 < info.inputSize; i += groupSize) {
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

void addMatchesToElements(std::vector<Element> &main, std::vector<Element> &pend,
	unsigned int groupSize) {
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

	// Find middle index

	unsigned int groups_between = (upper - lower) / groupSize;
	unsigned int middle_index = lower + ((groups_between / 2) * groupSize);
	
	// Debug
	
	if (PRINT_MAIN_AND_PEND_DEBUG) {
		std::cout << "lower = " << lower << ", upper = " << upper << ", ";
		std::cout << "middle = " << middle_index << std::endl;
	}

	// Compare value to value at middle index

	info.comparisons++;
	if (value < main[middle_index].value) {
		if ((int)middle_index - (int)groupSize < 0){
			upper = lower;
		}
		else {
			upper = middle_index - groupSize;
			if (upper < lower) {
				upper = lower;
			}
		}
	}
	else {
		lower = middle_index + groupSize;
	}

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
	unsigned int insert_start = insert_index - groupSize + 1;

	// Hold on to main values that we want to shift

	std::vector<Element> temp;
	for (unsigned int i = insert_start; i < main.size(); i++) {
		Element element;
		element.matchLetter = main[i].matchLetter;
		element.matchNumber = main[i].matchNumber;
		element.value = main[i].value;
		temp.push_back(element);
	}

	// Remove shifting values from main

	unsigned int size = main.size();
	for (unsigned int i = insert_start; i < size; i++) {
		main.pop_back();
	}

	// Print main for debug

	if (MAIN_DEBUG) {		
			std::cout << "main_after_remove = ";
			for (unsigned int i = 0; i < main.size(); i++) {
				std::cout << main[i].value << " ";
			}
			std::cout << std::endl;
	}

	// Insert pend group into main

	for (unsigned int i = 0; i < groupSize; i++) {
		Element element;
		element.matchLetter = pend[i + pend_start].matchLetter;
		element.matchNumber = pend[i + pend_start].matchNumber;
		element.value = pend[i + pend_start].value;
		main.push_back(element);
	}

	// Print main for debug

	if (MAIN_DEBUG) {		
			std::cout << "main_after_insert = ";
			for (unsigned int i = 0; i < main.size(); i++) {
				std::cout << main[i].value << " ";
			}
			std::cout << std::endl;
	}

	// Add back the shifted main values

	for (unsigned int i = 0; i < temp.size(); i++) {
		main.push_back(temp[i]);
	}

	// Print main for debug

	if (MAIN_DEBUG) {		
			std::cout << "main_after_remain = ";
			for (unsigned int i = 0; i < main.size(); i++) {
				std::cout << main[i].value << " ";
			}
			std::cout << std::endl;
	}

	//Remove elements from pend

	pend.erase(pend.begin() + pend_start, pend.begin() + pend_index + 1);

}

void handleBinaryInsertion(Info& info,
							std::vector<Element> &main,
							std::vector<Element> &pend,
							unsigned int groupSize,
							std::vector<unsigned int> &nonParticipating) {

	// Loop through jacobsthal numbers
	for (unsigned int i = 1; i < 16; i++) {
		for (unsigned int j = info.jacobsthal[i]; j > info.jacobsthal[i - 1]; j--) {

			// Check for empty pend

			if (pend.size() == 0) {
				return;
			}
			
			// Find matching index for jacob in pend
			unsigned int pend_index;
			if (findIndexOfJacobNumber(j, groupSize, pend_index, pend)) {
				printInsertVectors(info, main, pend, nonParticipating);
				// Find matching index for jacob in main
				unsigned int main_index;
				unsigned int insert_index;
				if (findIndexOfJacobNumber(j, groupSize, main_index, main)) {
					insert_index = findInsertionIndex(info, pend[pend_index].value,
													groupSize - 1, main_index - groupSize,
													groupSize, main);
				}
				else {
					insert_index = findInsertionIndex(info, pend[pend_index].value,
													groupSize - 1, main.size() - 1,
													groupSize, main);
				}
				insertToMain(pend_index, insert_index, groupSize, main, pend);
			}
		}
	}

}

void updateInput(Info &info,
				std::vector<Element> &main,
				std::vector<unsigned int> nonParticipating) {

	// Erase entire input

	info.input.clear();

	// Add element values from main to input

	for (unsigned int i = 0; i < main.size(); i++) {
		info.input.push_back(main[i].value);
	}

	// Add values from non participating to input

	for (unsigned int i = 0; i < nonParticipating.size(); i++) {
		info.input.push_back(nonParticipating[i]);
	}

	// Print input for debug

	if (INSERTION_DEBUG) {
		std::cout << "\nupdated input = ";
		for (unsigned int i = 0; i < info.input.size(); i++) {
			std::cout << info.green << info.input[i] << " ";
		}
		std::cout << std::endl;
	}
	
}

void handleInsertion(Info &info) {

	// End insertion when level is 0
	
	if (info.level == 0) {
		return ;
	}

	// Debug print Insert Levels

	if (INSERTION_DEBUG) {
		std::cout << std::endl;
		std::cout << info.cyan << "------------------------------------------------------------\n";
		std::cout << info.cyan << "Insert Level " << info.level << std::endl;
		std::cout << info.cyan << "------------------------------------------------------------\n";
	}

	// Skip level when there are less than 3 groups for insertion

	if (info.inputSize < pow(2, info.level)) {
		info.level--;
		handleInsertion(info);
		return ;
	}

	// Find the range of of the groups

	unsigned int range = pow(2, info.level);
	std::vector<Element> main;
	std::vector<Element> pend;
	std::vector<unsigned int> nonParticipating;

	addFirstTwoGroupsToMain(info, main, range);
	addOtherGroups(info, main, pend, nonParticipating, range);
	addMatchesToElements(main, pend, range / 2);
	handleBinaryInsertion(info, main, pend, range / 2, nonParticipating);
	updateInput(info, main, nonParticipating);

	info.level--;
	handleInsertion(info);
}

void getExpectedComparisons(unsigned int &sum, unsigned int &n) {
    sum = 0;
    for (unsigned int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
}

void initInfo(Info &info) {
	info.inputSize = info.input.size();
	if (info.inputSize > MAX_INPUT_SIZE) {
		throw std::runtime_error("Error: input size too large");
	}
	getMaxLevel(info);
	getExpectedComparisons(info.expectedComparisons, info.inputSize);
}

void checkIfSorted(std::vector<unsigned int> &input) {
	for (unsigned int i = 0; i < input.size() - 1; i++) {
		if (input[i] > input[i + 1]) {
			std::cout << "Sorted      = " << "NO" << std::endl;
		}
	}
	std::cout << "Sorted      = " << "YES" << std::endl;
}

void printResult(Info &info) {
	std::cout << info.green << "After:  ";
	for (unsigned int i = 0; i < info.input.size(); i++) {
		std::cout <<  info.green << info.input[i] << " ";
	}
	std::cout << std::endl;
	if (COMPARISONS_DEBUG) {
		std::cout << info.yellow << "Comparisons = " << info.comparisons << std::endl;
	}
	if (PRINT_EXPECTED_COMPARISONS) {
		std::cout << info.yellow << "Expected    = " << info.expectedComparisons << std::endl;
	}
	if (PRINT_CHECK_FOR_SORTED) {
		checkIfSorted(info.input);
	}
}

void generateRandomInput(Info &info) {
	std::srand(std::time(nullptr));
	for (unsigned int i = 0; i < NUM_OF_VALUES; i++) {
		unsigned int random_number = std::rand() % (RANGE_OF_VALUES + 1);
		info.input.push_back(random_number);
		info.inputDeque.push_back(random_number);
	}
}

void printStartingInput(Info &info) {
	std::cout << info.green << "Before: ";
	for (unsigned int i = 0; i < info.input.size(); i++) {
		std::cout << info.green << info.input[i] << " ";
	}
	std::cout << std::endl;
}

// ----------------------------------------------------------------------------
// LIST -----------------------------------------------------------------------
// ----------------------------------------------------------------------------

void handleInputDeque(char **argv, Info &info) {
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
		info.inputDeque.push_back(n);
	}	
}

void printStartingInputDeque(Info &info) {
	std::cout << std::endl;
	std::cout << info.green << "Before: ";
	for (unsigned int i = 0; i < info.inputDeque.size(); i++) {
		std::cout << info.green << info.inputDeque[i] << " ";
	}
	std::cout << std::endl;
}

void initInfoDeque(Info &info) {
	info.inputSize = info.inputDeque.size();
	if (info.inputSize > MAX_INPUT_SIZE) {
		throw std::runtime_error("Error: input size too large");
	}
	getMaxLevel(info);
	getExpectedComparisons(info.expectedComparisons, info.inputSize);
}

void swapGivenRangeDeque(Info &info, unsigned int &start, unsigned int &range) {
	for (unsigned int i = 0; i < range / 2; i++) {
		std::swap(info.inputDeque[i + start], info.inputDeque[i + start + (range / 2)]);
	}
}

void handleSwapsDeque(Info &info) {
	unsigned int range = pow(2, info.level);
	unsigned int disA = range / 2 - 1;
	unsigned int disB = range - 1;
	bool swapped = false;

	for (unsigned int i = 0; i + range - 1 < info.inputSize; i += range) {
		info.comparisons++;
		if (info.inputDeque[i + disA] > info.inputDeque[i + disB]) {
			swapped = true;
			swapGivenRangeDeque(info, i, range);
		}
		else {
			swapped = false;
		}
	}
	if (info.level < info.maxLevel) {
		info.level++;
		handleSwapsDeque(info);
	}
}

void addFirstTwoGroupsToMainDeque(Info &info,
							std::deque<Element> &main,
							unsigned int &range) {
	for (unsigned int i = 0; i < range; i++) {
		Element temp;
		temp.value = info.inputDeque[i];
		main.push_back(temp);
	}
}

void addOtherGroupsDeque(Info &info,
					std::deque<Element> &main,
					std::deque<Element> &pend,
					std::deque<unsigned int> &nonParticipating,
					unsigned int &range) {

	unsigned int groupSize = range / 2;
	bool addToMain = false;

	// Alternate adding groups to pend and main starting with pend

	unsigned int i = range;
	for (; i + groupSize - 1 < info.inputSize; i += groupSize) {
		for (unsigned int j = 0; j < groupSize; j++) {
			Element temp;
			temp.value = info.inputDeque[i + j];
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
		nonParticipating.push_back(info.inputDeque[i]);
	}
}

void addMatchesToElementsDeque(std::deque<Element> &main, std::deque<Element> &pend,
	unsigned int groupSize) {
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

int findIndexOfJacobNumberDeque(unsigned int j,
							unsigned int groupSize,
							unsigned int &index,
							std::deque<Element> &elements) {
	for (index = groupSize - 1; index < elements.size(); index += 1) {
		if (j == elements[index].matchNumber) {
			return true;
		}
	}
	return false;
}

unsigned int findInsertionIndexDeque(Info &info,
					unsigned int value,
					unsigned int lower,
					unsigned int upper,
					unsigned int groupSize,
					std::deque<Element> &main) {
	
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

	// Find middle index

	unsigned int groups_between = (upper - lower) / groupSize;
	unsigned int middle_index = lower + ((groups_between / 2) * groupSize);

	// Compare value to value at middle index

	info.comparisons++;
	if (value < main[middle_index].value) {
		if ((int)middle_index - (int)groupSize < 0){
			upper = lower;
		}
		else {
			upper = middle_index - groupSize;
			if (upper < lower) {
				upper = lower;
			}
		}
	}
	else {
		lower = middle_index + groupSize;
	}

	return findInsertionIndexDeque(info, value, lower, upper, groupSize, main);
}

void insertToMainDeque(unsigned int pend_index,
					unsigned int insert_index,
					unsigned int groupSize,
					std::deque<Element> &main,
					std::deque<Element> &pend
					) {

	// Set starting position of pend and insert

	unsigned int pend_start = pend_index - groupSize + 1;
	unsigned int insert_start = insert_index - groupSize + 1;

	// Hold on to main values that we want to shift

	std::vector<Element> temp;
	for (unsigned int i = insert_start; i < main.size(); i++) {
		Element element;
		element.matchLetter = main[i].matchLetter;
		element.matchNumber = main[i].matchNumber;
		element.value = main[i].value;
		temp.push_back(element);
	}

	// Remove shifting values from main

	unsigned int size = main.size();
	for (unsigned int i = insert_start; i < size; i++) {
		main.pop_back();
	}

	// Insert pend group into main

	for (unsigned int i = 0; i < groupSize; i++) {
		Element element;
		element.matchLetter = pend[i + pend_start].matchLetter;
		element.matchNumber = pend[i + pend_start].matchNumber;
		element.value = pend[i + pend_start].value;
		main.push_back(element);
	}

	// Add back the shifted main values

	for (unsigned int i = 0; i < temp.size(); i++) {
		main.push_back(temp[i]);
	}

	//Remove elements from pend

	pend.erase(pend.begin() + pend_start, pend.begin() + pend_index + 1);

}

void handleBinaryInsertionDeque(Info& info,
							std::deque<Element> &main,
							std::deque<Element> &pend,
							unsigned int groupSize,
							std::deque<unsigned int> &nonParticipating) {
	(void)nonParticipating;

	// Loop through jacobsthal numbers

	for (unsigned int i = 1; i < 16; i++) {
		for (unsigned int j = info.jacobsthal[i]; j > info.jacobsthal[i - 1]; j--) {

			// Check for empty pend

			if (pend.size() == 0) {
				return;
			}
			
			// Find matching index for jacob in pend

			unsigned int pend_index;
			if (findIndexOfJacobNumberDeque(j, groupSize, pend_index, pend)) {
				// Find matching index for jacob in main
				unsigned int main_index;
				unsigned int insert_index;
				if (findIndexOfJacobNumberDeque(j, groupSize, main_index, main)) {
					insert_index = findInsertionIndexDeque(info, pend[pend_index].value,
													groupSize - 1, main_index - groupSize,
													groupSize, main);
				}
				else {
					insert_index = findInsertionIndexDeque(info, pend[pend_index].value,
													groupSize - 1, main.size() - 1,
													groupSize, main);
				}
				insertToMainDeque(pend_index, insert_index, groupSize, main, pend);
			}
		}
	}

}

void updateInputDeque(Info &info,
				std::deque<Element> &main,
				std::deque<unsigned int> nonParticipating) {

	// Erase entire input

	info.inputDeque.clear();

	// Add element values from main to input

	for (unsigned int i = 0; i < main.size(); i++) {
		info.inputDeque.push_back(main[i].value);
	}

	// Add values from non participating to input

	for (unsigned int i = 0; i < nonParticipating.size(); i++) {
		info.inputDeque.push_back(nonParticipating[i]);
	}

	// Print input for debug

	if (INSERTION_DEBUG) {
		std::cout << "\nupdated input = ";
		for (unsigned int i = 0; i < info.input.size(); i++) {
			std::cout << info.green << info.inputDeque[i] << " ";
		}
		std::cout << std::endl;
	}
}

void handleInsertionDeque(Info &info) {

	// End insertion when level is 0

	if (info.level == 0) {
		return ;
	}

	// Skip level when there are less than 3 groups for insertion

	if (info.inputSize < pow(2, info.level)) {
		info.level--;
		handleInsertionDeque(info);
		return ;
	}

	// Find the range of of the groups

	unsigned int range = pow(2, info.level);
	std::deque<Element> main;
	std::deque<Element> pend;
	std::deque<unsigned int> nonParticipating;

	addFirstTwoGroupsToMainDeque(info, main, range);
	addOtherGroupsDeque(info, main, pend, nonParticipating, range);
	addMatchesToElementsDeque(main, pend, range / 2);
	handleBinaryInsertionDeque(info, main, pend, range / 2, nonParticipating);
	updateInputDeque(info, main, nonParticipating);

	info.level--;
	handleInsertionDeque(info);
}

void printResultDeque(Info &info) {
	std::cout << info.green << "After:  ";
	for (unsigned int i = 0; i < info.inputDeque.size(); i++) {
		std::cout <<  info.green << info.inputDeque[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe(char **argv) {
	
	// Vector -----------------------------------------------------------------
	
	
	Info info;
	
	if (GENERATE_RANDOM_INPUT) {
		generateRandomInput(info);
	}

	auto start = std::chrono::high_resolution_clock::now();

	if (!GENERATE_RANDOM_INPUT) {
		handleInput(argv, info);
	}
	printStartingInput(info);
	
	initInfo(info);
	handleSwaps(info);
	handleInsertion(info);
	printResult(info);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds> (end - start);

	std::cout << "Time to process a range of " << info.inputSize << " with std::vector : "
		<< elapsed.count() << " us" << std::endl;
	
	// Deque -------------------------------------------------------------------

	auto startDeque = std::chrono::high_resolution_clock::now();

	Info infoDeque;

	if (GENERATE_RANDOM_INPUT) {
		infoDeque.inputDeque = info.inputDeque;
	}
	else {
		handleInputDeque(argv, infoDeque);
	}
	if (PRINT_DEQUE_RESULT) {
		printStartingInputDeque(infoDeque);
	}

	initInfoDeque(infoDeque);
	handleSwapsDeque(infoDeque);
	handleInsertionDeque(infoDeque);
	if (PRINT_DEQUE_RESULT) {
		printResultDeque(infoDeque);
	}
	
	auto endDeque = std::chrono::high_resolution_clock::now();
	auto elapsedDeque = std::chrono::duration_cast<std::chrono::microseconds> (endDeque - startDeque);

	
	std::cout << "Time to process a range of " << info.inputSize << " with std::deque  : "
		<< elapsedDeque.count() << " us" << std::endl;
}
