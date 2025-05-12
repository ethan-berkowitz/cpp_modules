/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/12 11:00:59 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector = {1, 2, 3, 4, 5};
	std::deque<int> deq = {10, 20, 30, 40, 50};
	std::list<int> list = {100, 200, 300, 400, 500};

	int vector_output = easyfind(vector, 1);
	int deq_output = easyfind(deq, 20);
	int list_output = easyfind(list, 42);

	std::cout << "vector_output: " << vector_output << std::endl;
	std::cout << "deq_output   : " << deq_output << std::endl;
	std::cout << "list_output  : " << list_output << std::endl;
}
