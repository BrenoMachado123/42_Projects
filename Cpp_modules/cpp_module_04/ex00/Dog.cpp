/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:02:00 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/29 15:39:13 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){ this->_type = "Dog"; }

Dog::Dog(const Dog& other) { *this = other; }

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog(){}

void	Dog::makeSound() const { std::cout << "Oof!" << std::endl; }
