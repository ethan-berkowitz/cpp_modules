/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:06:58 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class WrongAnimal
{
	protected:
	
		std::string _type;
		
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal(void);

		WrongAnimal& operator = (WrongAnimal const &other);

		std::string	getType(void) const;
		void	makeSound(void) const;
};