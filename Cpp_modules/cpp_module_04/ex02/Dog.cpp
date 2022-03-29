/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:02:00 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/29 15:56:38 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog class Initialized" << std::endl;
	this->_brain = new Brain;
	this->_type = "Dog";
}

Dog::Dog(const Dog& other) { this->_brain = new Brain; *this = other; }

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
		*this->_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog(){ std::cout << "Dog class Destroyed" << std::endl; delete this->_brain; }

void	Dog::makeSound() const { std::cout << "Oof!" << std::endl; }
