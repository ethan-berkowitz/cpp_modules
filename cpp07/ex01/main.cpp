/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:09:18 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/03 10:44:54 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.hpp"
#include "iter.hpp"
#include "print.hpp"


int main( void )
{
	int arr[5] = {1, 2, 3, 4, 5};

	::iter(&arr, 5, ::print);

	return 0;
}
