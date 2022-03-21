/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:06:35 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/21 15:55:28 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(const Animal& other) { *this = other; }

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal(){}

void	Animal::makeSound() const { std::cout << "BrainzzzZZZ" << std::endl; }

std::string	Animal::getType() const { return(this->_type); }

