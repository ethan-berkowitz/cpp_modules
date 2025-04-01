/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:33:30 by eberkowi          #+#    #+#             */
/*   Updated: 2025/04/01 11:46:06 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Data
{
	private:
	
		std::string _name;

	public:

		Data(void);
		Data(std::string name);
		Data(const Data &other);
		Data& operator = (Data const &other);
		~Data(void);

		std::string		getName(void);
};
