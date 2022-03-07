/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:52:45 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/03 15:41:30 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void	print_parsed_info(std::string item, bool end_of_lst) {
	if (item.length() > 10) {
		item = item.substr(0, 9);
		item = item.replace(9,9,".");
		std::cout << item << "|";
		return ;
	}
	std::cout << std::setw(10) << item;
	if (end_of_lst == false) { std::cout << "|"; }
}

void	Contact::create() {
	std::cout << "[ First name ] "; 
	getline(std::cin >> std::ws, _fname);
	std::cout << "[ Last name ] "; 
	getline(std::cin >> std::ws, _lname);
	std::cout << "[ Nickname ] ";
	getline(std::cin >> std::ws, _nick);
	std::cout << "[ Phone Number ] ";
	getline(std::cin >> std::ws, _nphone);
	std::cout << "[ Darkest Secret ] ";
	getline(std::cin >> std::ws, _ds);
	std::cout << std::endl;
}

void	Contact::print_basic(int index) {
	bool end_of_lst = false;
	std::cout << std::setw(10) << index + 1 << "|";
	print_parsed_info(_fname, end_of_lst);
	print_parsed_info(_lname, end_of_lst);
	end_of_lst = true;
	print_parsed_info(_nick, end_of_lst);
	std::cout << std::endl;
}

void	Contact::info() {
	std::cout << std::endl;
	std::cout << "-------------------- Contact info ------------------------" << std::endl;
	std::cout << "[First name] " << _fname << std::endl;
	std::cout << "[Last name] " << _lname << std::endl;
	std::cout << "[Nickname] " << _nick << std::endl;
	std::cout << "[Phone number] " << _nphone << std::endl;
	std::cout << "[Darkest secret] " << _ds << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
}
