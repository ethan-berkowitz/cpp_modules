/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:22:59 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/13 15:18:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Weapon.hpp"

class HumanB
{
	private:

		std::string _name;
		Weapon *_weapon;

	public:

		HumanB(std::string name);

		void setWeapon(Weapon &weapon);
		void attack();
};
