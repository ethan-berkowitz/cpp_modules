/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/03/14 11:20:44 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "\n";

	//TEST #1 - SETTING AND GETTING IDEAS FOR CAT

	std::cout << "-----TEST #1 - SETTING AND GETTING IDEAS FOR CAT-----\n\n";
	Cat cat;
	cat.setIdea(0, "0th idea for cat!");
	cat.setIdea(50, "50th idea for cat!");
	cat.setIdea(200, "200th idea for cat!");
	std::cout << "Idea = " << cat.getIdea(0) << "\n";
	std::cout << "Idea = " << cat.getIdea(50) << "\n";
	std::cout << "Idea = " << cat.getIdea(200) << "\n\n";

	//TEST #2 - SETTING AND GETTING IDEAS FOR DOG

	std::cout << "-----TEST #2 - SETTING AND GETTING IDEAS FOR DOG-----\n\n";
	Dog dog;
	dog.setIdea(0, "0th idea for dog!");
	dog.setIdea(99, "99th idea for dog!");
	dog.setIdea(100, "100th idea for dog!");
	std::cout << "Idea = " << dog.getIdea(0) << "\n";
	std::cout << "Idea = " << dog.getIdea(99) << "\n";
	std::cout << "Idea = " << dog.getIdea(100) << "\n\n";

	//TEST #3 - PDF TEST FOR ARRAY
	std::cout << "-----TEST #3 - PDF TEST FOR ARRAY-----\n\n";
	const Animal* arr[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		std::cout << "\n";
	}
	for (int i = 0; i < 10; i++) {
		delete arr[i];
		std::cout << "\n";
	}	

	return (0);
}
