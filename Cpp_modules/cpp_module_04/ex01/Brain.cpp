/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:22:25 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/21 18:23:06 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain class Initialized" << std::endl; }

Brain::Brain(const Brain& other) { *this = other; }

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) { this->_ideas[i] = other._ideas[i]; }
	}
	return (*this);
}

Brain::~Brain(){ std::cout << "Brain class Destroyed" << std::endl; }
