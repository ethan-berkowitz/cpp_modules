/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:09:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/08 11:27:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void my_print(const T input)
{
	std::cout << input << std::endl;
}

int main(void)
{
	int int_array[5] = {1, 2, 3, 4, 5};
	char char_array[10] = {'a', 'b', 'c', 'd', 'e', 'f' , 'g' ,'h' ,'i', 'j'};

	std::cout << "-----INT ARRAY-----\n\n";
	iter(int_array, 5, my_print);
	std::cout << "-----CHAR ARRAY-----\n\n";
	iter(char_array, 10, my_print);

	std::cout << std::endl;

	return 0;
}
