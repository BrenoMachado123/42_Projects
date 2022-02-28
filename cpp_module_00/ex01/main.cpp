/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:37 by bmachado          #+#    #+#             */
/*   Updated: 2022/02/28 17:26:22 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	print_options(int counter) {
	std::cout << std::endl;
	std::cout << "[ ADD ] Add a contact to phonebook" << std::endl;
	std::cout << "[ SEARCH ] Show your contacts and expand their info" << std::endl;
	std::cout << "[ EXIT ] Close the phonebook" << std::endl;
	std::cout << "<< You have added " << counter << " contacts; if you reach the limit, the oldest contact will be replaced >>" << std::endl;
}

int	main() {
	PhoneBook	phonebook;
	std::string	option;
	int counter = 0;

	phonebook.init();
	while (option != "EXIT") {
		print_options(counter);
		getline(std::cin >> std::ws, option);
		if (option == "ADD") { phonebook.add(); counter++; }
		else if (option == "SEARCH")
			phonebook.search();
		else if (option != "EXIT")
			std::cout << ">> Invalid option <<" << std::endl;
	}
	return (0);
}
