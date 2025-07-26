/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/26 14:43:26 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

#define ATACK_EMOJI "⚔️  "

int main() {
	std::cout << std::endl
		<< "=================================================="
		<< std::endl;
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << ATACK_EMOJI;
		bob.attack();
		club.setType("some other type of club");
		std::cout << ATACK_EMOJI;
		bob.attack();
	}
	std::cout 
		<< "=================================================="
		<< std::endl;
	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		std::cout << ATACK_EMOJI;
		jim.attack();
		club.setType("some other type of club");
		std::cout << ATACK_EMOJI;
		jim.attack();
	}
	std::cout
		<< "=================================================="
		<< std::endl << std::endl;
	return 0;
}