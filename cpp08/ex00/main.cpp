/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/11 10:54:56 by eberkowi         ###   ########.fr       */
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
	std::list<char> char_list = {'a', 'b', 'c', 'd', 'e'};
	std::list<float> float_list = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

	int vector_output = easyfind(vector, 1);
	int deq_output = easyfind(deq, 50);
	int list_output = easyfind(list, 42);
	int char_list_output = easyfind(char_list, 42);
	int float_list_output = easyfind(float_list, 1);

	std::cout << "vector_output: " << vector_output << std::endl;
	std::cout << "deq_output   : " << deq_output << std::endl;
	std::cout << "list_output  : " << list_output << std::endl;
	std::cout << "char_list_output  : " << char_list_output << std::endl;
	std::cout << "float_list_output  : " << float_list_output << std::endl;
}
