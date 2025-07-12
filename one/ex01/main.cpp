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

#include "Zombie.hpp"
#include "utils.hpp"
#include "style.hpp"

void testBasicZombieHorde();

void showMenu() {
	clearScreen();
	std::cout << BOLD << CYAN
		<< "🧟‍♂️  ZOMBIE TESTER 🧟‍♀️"
		<< RESET << std::endl << std::endl;
	
	std::cout << GREEN << "1️⃣  Basic Test: Zombie Horde" << RESET << std::endl;
	std::cout << GREEN << "2️⃣  Advanced Test: Zombie Horde with Random Names" << RESET << std::endl;
	std::cout << GREEN << "3️⃣  Edge Case: Zombie Horde with Zero Size" << RESET << std::endl;
	std::cout << GREEN << "4️⃣  Stress Test: Large Zombie Horde" << RESET << std::endl;

	std::cout << BOLD << WHITE << "\n📝 Choose an option: " << RESET;
}

int main() {
	std::string choice;

	while (true) {
		showMenu();
		std::getline(std::cin, choice);
		if (endOfFileDetected()) break;
		
		if (choice == "5") {
			clearScreen();
			std::cout << BOLD << GREEN 
				<< "👋 Thank you for using Zombie Memory Tester!" 
				<< RESET << std::endl;
			break;
		}
		
		if (choice.length() != 1) {
			std::cout << RED << "❌ Invalid option!" << RESET << std::endl;
			pause();
			continue;
		}
		
		clearScreen();
		switch (choice[0]) {
			case '1': testBasicZombieHorde(); break;
			default:
				std::cout << RED << "❌ Invalid option!"<< RESET << std::endl;
				break;
		}
		pause();
	}

	return 0;
}