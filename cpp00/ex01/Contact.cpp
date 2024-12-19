/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:53:28 by eberkowi          #+#    #+#             */
/*   Updated: 2024/12/19 11:57:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void) 
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
	_index = "";
	_time_created = 0;
}

Contact::~Contact(void) {}

std::string Contact::get_first_name(void)
{
	return (_first_name);
}

std::string Contact::get_last_name(void)
{
	return (_last_name);
}

std::string Contact::get_nickname(void)
{
	return (_nickname);
}

std::string Contact::get_phone_number(void)
{
	return (_phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}

std::string Contact::get_index(void)
{
	return (_index);
}

std::time_t Contact::get_time_created(void)
{
	return (_time_created);
}

void Contact::set_first_name(std::string first_name)
{
	_first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	_last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
	_nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number)
{
	_phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}

void Contact::set_index(std::string index)
{
	_index = index;
}

void Contact::set_time_created(std::time_t time_created)
{
	_time_created = time_created;
}
