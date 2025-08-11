/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:51:58 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/15 11:50:57 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
int easyfind(T container, int to_find)
{
	unsigned int index = 0;
	for (int i : container)
	{
		if (i == to_find)
			return (index);
		index++;
	}
	return (-1);
}
