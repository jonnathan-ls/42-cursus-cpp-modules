/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Zombie.hpp"
#include "utils.hpp"

void testScope();
void testPerformance();
void testZombieArray();
void testInteractive();
void testBasicStackVsHeap();

void showMenu() {
	clearScreen();
	std::cout << BOLD << CYAN
		<< "🧟‍♂️  ZOMBIE TESTER 🧟‍♀️"
		<< RESET << std::endl << std::endl;
	
	std::cout << GREEN << "1️⃣  Basic Stack vs Heap Test" << RESET << std::endl;
	std::cout << BLUE << "2️⃣  Scope Test" << RESET << std::endl;
	std::cout << YELLOW << "3️⃣  Performance Test" << RESET << std::endl;
	std::cout << CYAN << "4️⃣  Interactive Mode" << RESET << std::endl;
	std::cout << WHITE << "5️⃣  Exit" << RESET << std::endl;

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
			case '1': testBasicStackVsHeap(); break;
			case '2': testScope(); break;
			case '3': testPerformance(); break;
			case '4': testInteractive(); break;
			default:
				std::cout << RED << "❌ Invalid option!"<< RESET << std::endl;
				break;
		}
		pause();
	}

	return 0;
}