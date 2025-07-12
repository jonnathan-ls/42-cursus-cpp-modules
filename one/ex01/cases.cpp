/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 18:22:53 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Zombie.hpp"
#include "utils.hpp"
#include "style.hpp"

Zombie* zombieHorde( int N, std::string name );

void testBasicZombieHorde() {
	std::cout << BOLD << YELLOW << "Test: Basic Zombie Horde" << RESET << std::endl;
	Zombie* horde = zombieHorde(5, "Zombie");
	if (horde) {
		for (int i = 0; i < 5; i++) {
			horde[i].announce();
		}
		delete[] horde;
	} else {
		std::cerr << BOLD << RED << "Error: Zombie horde creation failed." << RESET << std::endl;
	}
	std::cout << BOLD << YELLOW << "End of Basic Zombie Horde Test" << RESET << std::endl;
}
