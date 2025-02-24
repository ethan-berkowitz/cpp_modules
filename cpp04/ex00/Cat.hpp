/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
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

class Cat : public Animal
{	
	public:

		Cat(void);
		Cat(const Cat &other);
		~Cat(void);

		Cat& operator = (Cat const &other);

		virtual void	makeSound(void) const;
};