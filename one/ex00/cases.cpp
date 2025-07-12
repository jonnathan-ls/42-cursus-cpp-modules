/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 17:34:08 by jlacerda         ###   ########.fr       */
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

Zombie* newZombie(std::string name);
void randomChump(std::string name);

void testBasicStackVsHeap() {
	std::cout << BOLD << CYAN << "🔬 Stack vs Heap Test" << RESET << std::endl;

	std::cout << GREEN << "\n1️⃣  Testing HEAP (newZombie):"
		<< RESET << std::endl << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << BLUE << "\n2️⃣  Testing STACK (randomChump):"
		<< RESET << std::endl << std::endl;
	randomChump("StackZombie");

	std::cout << YELLOW << "\nNote: Stack zombie destroyed automatically!"
		<< RESET << std::endl;
}

void testScope() {
	std::cout << BOLD << CYAN << "🎯 Scope Test" << RESET << std::endl;

	Zombie* persistentZombie = NULL;

	std::cout << GREEN << "\nℹ️  Entering inner block..."
		<< RESET << std::endl;
	{
		persistentZombie = newZombie("Persistent");
		std::cout << YELLOW << "ℹ️  Creating temporary zombie..."
			<< RESET << std::endl;
		randomChump("Temporary");
		std::cout << RED << "ℹ️  Leaving inner block..." << RESET << std::endl;
	}

	std::cout << GREEN << "\nℹ️  Heap zombie still exists outside block:" 
		<< RESET << std::endl;
	persistentZombie->announce();
	delete persistentZombie;
}

void testPerformance() {
	std::cout << BOLD << CYAN << "⚡ Performance Test" << RESET << std::endl;

	const int iterations = 125;
	std::cout << YELLOW << "\nExecuting " << iterations << " iterations..." 
		<< RESET << std::endl;

	clock_t start = clock();

	std::cout << GREEN << "\nTesting STACK..." << RESET << std::endl;
	for (int i = 0; i < iterations; i++) {
		randomChump("StackZombie");
	}

	clock_t mid = clock();

	std::cout << BLUE << "\nTesting HEAP..." << RESET << std::endl;
	for (int i = 0; i < iterations; i++) {
		Zombie* z = newZombie("HeapZombie");
		delete z;
	}

	clock_t end = clock();

	double stackTime = ((double)(mid - start)) / CLOCKS_PER_SEC;
	double heapTime = ((double)(end - mid)) / CLOCKS_PER_SEC;

	std::cout << BOLD << GREEN << "\n📊 RESULTS:" << RESET << std::endl;
	std::cout << GREEN << "Stack: " << stackTime << " seconds"
		<< RESET << std::endl;
	std::cout << BLUE << "Heap: " << heapTime << " seconds"
		<< RESET << std::endl;

	if (stackTime < heapTime) {
		double diffSeconds = stackTime - heapTime;
		if (diffSeconds < 0) diffSeconds = -diffSeconds;
		std::cout << BOLD << RED << "🏆 Stack was "
			<< diffSeconds << " faster!" << RESET << std::endl;
	} else if (stackTime == heapTime) {
		std::cout << BOLD << YELLOW << "🏅 Both took the same time!" 
			<< RESET << std::endl;
	} else {
		double diffSeconds = heapTime - stackTime;
		if (diffSeconds < 0) diffSeconds = -diffSeconds;
		std::cout << BOLD << BLUE << "🏆 Heap was "
			<< diffSeconds << " faster!" << RESET << std::endl;
	}
}

void clearRemainingZombies(Zombie** zombies, int count) {
	if (count > 0) {
		std::cout << RED 
			<< "\n🧹 Clearing remaining zombies..." 
			<< RESET << std::endl;
		for (int i = 0; i < count; i++) {
			delete zombies[i];
		}
	}
}

void testInteractive() {
	std::cout << BOLD << CYAN << "🎮 Interactive Mode"
		<< RESET << std::endl << std::endl;

	const int MAX_ZOMBIES = 10;
	Zombie* heapZombies[MAX_ZOMBIES];
	int zombieCount = 0;

	std::string choice;
	std::string name;

	std::cout << GREEN << "1️⃣  Create heap zombie" << RESET << std::endl;
	std::cout << BLUE << "2️⃣  Create stack zombie" << RESET << std::endl;
	std::cout << MAGENTA << "3️⃣  Announce all heap zombies" << RESET << std::endl;
	std::cout << RED << "4️⃣  Clear all heap zombies" << RESET << std::endl;
	std::cout << YELLOW << "5️⃣  Exit" << RESET << std::endl;
	
	while (true) {
		std::cout << CYAN << "\n📝 Choose an option: " << RESET;
		std::getline(std::cin, choice);
		if (endOfFileDetected()) {
			clearRemainingZombies(heapZombies, zombieCount);
			return ;
		}
		
		if (choice == "5") break;
		
		if (choice == "1" || choice == "2") {
			std::cout << CYAN << "➡️  Zombie name: " << RESET;
			std::getline(std::cin, name);
			if (endOfFileDetected()) {
				clearRemainingZombies(heapZombies, zombieCount);
				return ;
			}
			
			if (choice == "1") {
				if (zombieCount < MAX_ZOMBIES) {
					heapZombies[zombieCount] = newZombie(name);
					std::cout << GREEN << "✅ Heap zombie created!" 
						<< RESET << std::endl;
					heapZombies[zombieCount]->announce();
					zombieCount++;
				} else {
					std::cout << RED << "❌ Zombie limit reached!" 
						<< RESET << std::endl;
				}
			} else {
				randomChump(name);
				std::cout << BLUE << "✅ Stack zombie created (destroyed)!" 
					<< RESET << std::endl;
			}
		} else if (choice == "3") {
			if (zombieCount == 0) {
				std::cout << RED << "😞 No heap zombies!" 
					<< RESET << std::endl;
			} else {
				std::cout << MAGENTA << "📢 Heap zombies announcing:"
					<< RESET << std::endl;
				for (int i = 0; i < zombieCount; i++) {
					heapZombies[i]->announce();
				}
			}
		} else if (choice == "4") {
			if (zombieCount == 0) {
				std::cout << RED << "😞 No heap zombies to clear!"
					<< RESET << std::endl;
			} else {
				std::cout << RED << "🧹 Clearing all heap zombies..." 
					<< RESET << std::endl;
				for (int i = 0; i < zombieCount; i++) {
					delete heapZombies[i];
				}
				zombieCount = 0;
				std::cout << GREEN << "✅ All zombies cleared!" 
					<< RESET << std::endl;
			}
		}
	}

	if (zombieCount > 0)
		clearRemainingZombies(heapZombies, zombieCount);
}