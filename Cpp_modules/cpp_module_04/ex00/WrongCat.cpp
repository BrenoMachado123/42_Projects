/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:41:46 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/21 15:41:53 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() { this->_type = "WrongCat"; }

WrongCat::WrongCat(const WrongCat& other) { *this = other; }

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat(){}

void	WrongCat::makeSound() const { std::cout << "MEOW!" << std::endl; }
