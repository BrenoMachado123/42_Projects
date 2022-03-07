/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:30:57 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/03 16:55:46 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
# define PHONEBOOK_SIZE 8

int	PhoneBook::_index = 0;
int PhoneBook::_old = 0;

static int	is_valid(std::string input, int max_index) {
	int size = input.length();
	for (int i = 0; i < size; i++) {
		if (!std::isdigit(input[i])) {
			std::cout << ">> Invalid input <<" << std::endl;
			return (0);
		}
	}
	if (std::stol(input) - 1 >= max_index || std::stol(input) - 1 < 0) {
		std::cout << ">> Index contact doesn't exist <<" << std::endl;
		return (0);
	}
	return (1);
}

void	PhoneBook::init() { std::cout << "<< AWESOME PHONEBOOK >>" << std::endl << "<< MAXIMUM SIZE: 8 >>" << std::endl; }

void	PhoneBook::add() {
	Contact contact;

	contact.create();
	if (_index < PHONEBOOK_SIZE) {
		_contact_lst[_index] = contact;
		std::cout << "<< Contact added >>" << std::endl;
		_index++;
	} else {
		if (_old == PHONEBOOK_SIZE) { _old = 0; }
		_contact_lst[_old] = contact; std::cout << "<< Phonebook limit reached | Oldest contact replaced >>" << std::endl;
		_old++;
	}
}

void	PhoneBook::print_phonebook() { for (int i = 0; i < _index; i++) _contact_lst[i].print_basic(i); }

void	PhoneBook::search() {
	if (_index == 0) {
		std::cout << ">> PhoneBook is empty <<" << std::endl;
		return ;
	}
	std::string	input;
	print_phonebook();
	std::cout << "[Select contact index] ";
	getline(std::cin >> std::ws, input);
	if (is_valid(input, _index)) {
		if (std::stol(input) - 1 < 0) { input = "0"; }
		_contact_lst[std::stol(input) - 1].info();
	}
}
