/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 18:24:08 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ATACK_EMOJI "⚔️  "
#include <iostream>

int main() {
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << ATACK_EMOJI;
		bob.attack();
		club.setType("some other type of club");
		std::cout << ATACK_EMOJI;
		bob.attack();
	}
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

	return 0;
}