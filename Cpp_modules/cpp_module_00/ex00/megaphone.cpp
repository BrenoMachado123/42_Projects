/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:39:53 by bmachado          #+#    #+#             */
/*   Updated: 2022/03/03 17:15:53 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE NOISE SOUND *";
	else {
		for (int i = 1; argv[i]; i++) {
			std::string str(argv[i]);
			for (int j = 0; j < (int)str.length(); j++)
				str[j] = std::toupper(str[j]);
			std::cout << str << " "; 
		}
	}
	std::cout << std::endl;
	return (0);
}
