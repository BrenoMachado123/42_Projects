/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:47:21 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/18 18:48:54 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap bot1("BMO");
	FragTrap buddy("Barney");
	ScavTrap guardian("Goliath");

	//buddy turn
	buddy.highFivesGuys(); // <- buddy will perform high five
	//bot turn
	bot1.attack(guardian.getName()); 
	guardian.takeDamage(bot1.getDmg());
	//guardian turn
	guardian.guardGate();
	//buddy turn
	buddy.attack(guardian.getName());
	guardian.takeDamage(buddy.getDmg());
	//guardian turn
	guardian.guardGate(); // <- showing again that it's already in guard gate mode
	return (0);
}
