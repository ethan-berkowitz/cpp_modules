/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:58:21 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/15 12:15:31 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Temp
{
    private:

        std::string _string;
		int _n;

	public:

		Temp(void) {_string = "default";}
		Temp(std::string str) {_string = str;}
		Temp(int n) {_n = n;}
		~Temp(void) {};

		void addString(std::string str) {_string = str;}
		void printString() {std::cout << "string = " << _string << std::endl;}
	};

int main(void)
{
	Temp temp;
	temp.printString();
	temp.addString("hello");
	temp.printString();
	temp = Temp();
	temp.printString();
}
