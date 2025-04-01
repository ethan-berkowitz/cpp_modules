/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/01 13:22:10 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data data("colin");

	uintptr_t raw = Serializer::serialize(&data);
	Data *serialized_data = Serializer::deserialize(raw);

	std::cout << "Data Name           : " << data.getName() << std::endl;
	std::cout << "Serialized Data Name: " << serialized_data->getName() << std::endl;

	std::cout << "Data Pointer           : " << &data << std::endl;
	std::cout << "Serialized Data Pointer: " << serialized_data << std::endl;

	return (0);
}
