/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:57:03 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/24 12:14:28 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "\n";

	// TEST #1: ANIMAL CLASS
	std::cout << "----- TEST #1: ANIMAL CLASS -----\n\n";
	Animal animal;
	std::cout << "Type = " << animal.getType() << "\n";
	std::cout << "Sound = ";
	animal.makeSound();
	std::cout << "\n";

	// TEST #2: DOG CLASS
	std::cout << "----- TEST #2: DOG CLASS -----\n\n";
	Dog dog;
	std::cout << "Type = " << dog.getType() << "\n";
	std::cout << "Sound = ";
	dog.makeSound();
	std::cout << "\n";

	// TEST #3: CAT CLASS
	std::cout << "----- TEST #3: DOG CLASS -----\n\n";
	Cat cat;
	std::cout << "Type = " << cat.getType() << "\n";
	std::cout << "Sound = ";
	cat.makeSound();
	std::cout << "\n";

	// TEST #4: PDF TEST
	std::cout << "----- TEST #4: PDF TEST -----\n\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "\n";

	// DESTRUCTORS
	std::cout << "----- DESTRUCTORS -----\n\n";
	return (0);
}
