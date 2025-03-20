/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 11:31:50 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{	
	public:

		WrongCat(void);
		WrongCat(const WrongCat &other);
		~WrongCat(void);

		WrongCat& operator = (WrongCat const &other);

		void	makeSound(void) const;
};