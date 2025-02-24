/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:48 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/20 15:40:15 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class ClapTrap
{
	private:

		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
		
	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
	
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			setName(std::string name);
		std::string		getName(void);
		void			setHitPoints(int hit_points);
		int				getHitPoints(void);
		void			setEnergyPoints(int energy_points);
		int				getEnergyPoints(void);
		void			setAttackDamage(int attack_damage);
		int				getAttackDamage(void);
};