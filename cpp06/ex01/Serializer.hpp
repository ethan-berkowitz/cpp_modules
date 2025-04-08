/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:38 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:

		Serializer(void);
		Serializer(const Serializer &other) = delete;
		Serializer& operator = (Serializer const &other) = delete;
		~Serializer(void);

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
