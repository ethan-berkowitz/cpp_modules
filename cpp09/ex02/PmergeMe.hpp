/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/21 11:41:54 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

struct Info {
	std::vector<unsigned int > input;
	unsigned int maxLevel = 1;
	unsigned int level = 1;
	unsigned int inputSize;
	unsigned int comparisons;
};

// struct node {
//     unsigned int largest;
// 	std::vector<unsigned int> other;
// 	unsigned int level = 0;
// 	std::string type = "pair";
// };

void PmergeMe(char **argv);
