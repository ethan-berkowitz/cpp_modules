/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/12 11:30:06 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{	
	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap(void);

		FragTrap& operator = (FragTrap const &other);

		void	highFivesGuys();
		void	attack(const std::string& target);
};