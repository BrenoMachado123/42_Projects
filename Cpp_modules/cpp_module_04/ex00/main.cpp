/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:03:28 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/29 15:37:27 by bmachado         ###   ########.fr       */
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
		std::cout << j->getType() << " " << std::endl; //dog
		std::cout << i->getType() << " " << std::endl; //cat
		i->makeSound(); // cat sound
		j->makeSound(); // dog sound
		meta->makeSound(); //animal sound

		delete meta; delete j; delete i;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();

		std::cout << "=== WRONG ANIMAL TEST === " << std::endl;
		std::cout << j->getType() << " " << std::endl; //dog
		std::cout << i->getType() << " " << std::endl; //cat
		i->makeSound(); //amimal sound
		j->makeSound(); //animal sound
		meta->makeSound(); // animal sound

		delete meta; delete j; delete i;
	}
	std::cout << "==========================" << std::endl; 
	return 0;
}
