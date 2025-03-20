/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 11:31:50 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{	
	private:

		Brain* _brain;

	public:

		Dog(void);
		Dog(const Dog &other);
		~Dog(void);

		Dog& operator = (Dog const &other);

		void	makeSound(void) const;
		void		setIdea(unsigned int n, std::string idea);
		std::string	getIdea(unsigned int n);
};