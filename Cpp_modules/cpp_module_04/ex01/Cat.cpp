/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:01:44 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/21 18:24:59 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() { 
	std::cout << "Cat class Initialized" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& other) { this->_brain = new Brain; *this = other; }

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other._type;
		*this->_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat() { std::cout << "Cat class Destroyed" << std::endl; delete this->_brain; }

void	Cat::makeSound() const { std::cout << "MEOW!" << std::endl; }
