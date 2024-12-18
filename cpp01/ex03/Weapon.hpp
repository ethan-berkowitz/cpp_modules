/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:18:18 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/13 13:50:26 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Weapon
{
	private:

		std::string _type;

	public:

		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string &getType();
		void setType(std::string type);
};
