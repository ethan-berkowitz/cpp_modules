/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:16:24 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/07 14:42:33 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <ctime>
# include <iomanip>

class Contact
{
    private:

        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
        std::string _index;
		std::time_t _time_created;

	public:

		Contact(void);
		~Contact(void);

		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_phone_number(void);
		std::string get_darkest_secret(void);
		std::string get_index(void);
		std::time_t get_time_created(void);
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);
		void set_index(std::string index);
		void set_time_created(std::time_t time_created);
};
