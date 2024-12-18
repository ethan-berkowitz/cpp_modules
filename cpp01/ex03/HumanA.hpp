/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:22:59 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/13 14:19:02 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Weapon.hpp"

class HumanA
{
	private:

		std::string _name;
		Weapon &_weapon;

	public:

		HumanA(std::string name, Weapon &weapon);

		void attack();
			
};