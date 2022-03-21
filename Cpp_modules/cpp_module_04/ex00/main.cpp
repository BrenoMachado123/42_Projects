/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:03:28 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/21 15:58:48 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "WrongDog.hpp"

int main() {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "=== RIGHT ANIMAL TEST ===" << std::endl;
		std::cout << j->getType() << " " << std::endl; 
		std::cout << i->getType() << " " << std::endl; 
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta; delete j; delete i;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();

		std::cout << "=== WRONG ANIMAL TEST === " << std::endl;
		std::cout << j->getType() << " " << std::endl; 
		std::cout << i->getType() << " " << std::endl; 
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta; delete j; delete i;
	}
	std::cout << "==========================" << std::endl; 
	return 0;
}
