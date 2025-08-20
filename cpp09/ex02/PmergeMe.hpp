/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/20 13:40:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <limits>

struct node {
    unsigned int largest;
	std::vector<unsigned int> other;
	unsigned int level = 0;
	std::string type = "pair";
};

void PmergeMe(char **argv);
