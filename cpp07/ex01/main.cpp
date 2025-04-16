/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:09:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/15 10:53:42 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "print.hpp"

int main( void )
{
	int int_array[5] = {1, 2, 3, 4, 5};
	char char_array[10] = {'a', 'b', 'c', 'd', 'e', 'f' , 'g' ,'h' ,'i', 'j'};

	std::cout << "-----INT ARRAY-----" << std::endl;
	iter(int_array, 5, print);
	std::cout << "-----CHAR ARRAY-----" << std::endl;
	iter(char_array, 10, print);

	return 0;
}
