/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:51 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/18 18:47:51 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	_hitPoints=100; _energyPoints=100; _attackDamage=30;
	std::cout << "FragTrap class Initialized" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints=100; _energyPoints=100; _attackDamage=30;
	std::cout << "FragTrap class Initialized" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other) { *this = other; }

FragTrap& FragTrap::operator=(FragTrap const& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return(*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap class Destroyed" << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (this->active()) {
		std::cout << "FlagCrap " << this->_name << " requests a high five! "
		<< std::endl;
		this->_attackDamage += 15;
		this->_energyPoints -= 30;
		this->active();
	}
}
