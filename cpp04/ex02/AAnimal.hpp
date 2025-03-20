/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/10 12:14:22 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class AAnimal
{
	protected:

		std::string _type;
		
	public:

		AAnimal(void);
		AAnimal(const AAnimal &other);
		virtual ~AAnimal(void);

		AAnimal& operator = (AAnimal const &other);

		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
};
