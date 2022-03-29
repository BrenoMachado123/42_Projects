/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:01:44 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/29 15:41:51 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() { this->_type = "Cat"; }

Cat::Cat(const Cat& other) { *this = other; }

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat(){}

void	Cat::makeSound() const { std::cout << "MEOW!" << std::endl; }
