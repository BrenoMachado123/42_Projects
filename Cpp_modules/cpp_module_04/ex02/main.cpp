/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:03:28 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/29 15:56:00 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define N 10

int main() {
	{
		std::cout << " == Declaring test == " << std::endl;
		//create a 'dog' will call 'dog' class and after call 'brain' class; 
		const Animal* j = new Dog();
		//same with 'cat'
		const Animal* i = new Cat();

		//delete in reversal order;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << " == Animal array test == " << std::endl;
		//create an animal array - half of 'dog' and half 'cat'; 
		Animal *animals[N];
		for (int i = 0; i < N; i++) {
			if (i < N/2) { 
				animals[i]  = new Dog; 
			} else { animals[i] = new Cat; } 
		}
		// call getType() and makeSound() functions to check the animals and then delete them;
		for (int j = 0; j < N; j++) {
			std::cout << "-----------------------" << std::endl;
			std::cout << animals[j]->getType() << std::endl; 
			animals[j]->makeSound(); 
			std::cout << "-----------------------" << std::endl;
			delete animals[j]; 
		}
		std::cout << std::endl;
	}
	{
		std::cout << " == Pointer animal assignment test == " << std::endl;
		Animal *cat = new Cat();
		Animal *dog = new Dog();

		// assigning *cat with a *dog
		*cat = *dog;

		//both will have the type 'dog' now;
		std::cout << cat->getType() << std::endl;
		std::cout << dog->getType() << std::endl;

		//but 'cat' will do the 'cat' sound because only the type was copied; 
		cat->makeSound();
		dog->makeSound();

		delete cat;
		delete dog;

		std::cout << std::endl;
	}
	return 0;
}
