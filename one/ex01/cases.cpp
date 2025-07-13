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


void testPerformanceZombieHorde() {
	std::cout << BOLD << CYAN << "⚡ Performance Test" << RESET << std::endl;

	const int iterations = 10000;
	std::cout << YELLOW << "\nExecuting " << iterations << " iterations..." 
		<< RESET << std::endl;

	clock_t start = clock();

	std::cout << GREEN << "\nTesting STACK..." << RESET << std::endl;
	for (int i = 0; i < iterations; i++) {
		Zombie *zombie = new Zombie();
		zombie->setName("MultipleAllocZombie");
		delete zombie;
	}

	clock_t mid = clock();

	std::cout << BLUE << "\nTesting HEAP..." << RESET << std::endl;
	Zombie *horde= zombieHorde(iterations, "SingleAllocZombie");
	delete[] horde;

	clock_t end = clock();

	double multipleAllocTime = ((double)(mid - start)) / CLOCKS_PER_SEC;
	double singleAllocTime = ((double)(end - mid)) / CLOCKS_PER_SEC;

	std::cout << BOLD << GREEN << "\n📊 RESULTS:" << RESET << std::endl;
	std::cout << GREEN << "Multiple: " << multipleAllocTime << " seconds"
		<< RESET << std::endl;
	std::cout << BLUE << "Single: " << singleAllocTime << " seconds"
		<< RESET << std::endl;

	if (multipleAllocTime < singleAllocTime) {
		double diffSeconds = multipleAllocTime - singleAllocTime;
		if (diffSeconds < 0) diffSeconds = -diffSeconds;
		std::cout << BOLD << RED << "🏆 Multiple was "
			<< diffSeconds << " faster!" << RESET << std::endl;
	} else if (multipleAllocTime == singleAllocTime) {
		std::cout << BOLD << YELLOW << "🏅 Both took the same time!" 
			<< RESET << std::endl;
	} else {
		double diffSeconds = singleAllocTime - multipleAllocTime;
		if (diffSeconds < 0) diffSeconds = -diffSeconds;
		std::cout << BOLD << BLUE << "🏆 Single was "
			<< diffSeconds << " faster!" << RESET << std::endl;
	}
}
