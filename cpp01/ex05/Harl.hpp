/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:16:24 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/17 11:37:30 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define DEBUG 1;
# define INFO 2;
# define WARNING 3;
# define ERROR 4;

class Harl
{
    private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		void complain(std::string level);
};
