/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 12:11:58 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Animal
{
	protected:

		std::string _type;
		
	public:

		Animal(void);
		Animal(const Animal &other);
		~Animal(void);

		Animal& operator = (Animal const &other);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};