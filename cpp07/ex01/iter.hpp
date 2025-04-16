/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:09:51 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/15 11:14:26 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void iter(T* address, unsigned int length, void (*func)(T))
{
    for (unsigned int i = 0; i < length; i++)
        func(address[i]);
}
