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
#include <cstdlib>
#include <iomanip>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "style.hpp"

static void print_header(const std::string& emoji, const std::string& title) {
	std::cout << std::endl << emoji << " " << title << "\n" << std::endl;
}

static void print_status(const ClapTrap& obj) {
	std::cout << "🤖 Status of " << obj.getName()
		<< ": HP=" << obj.getHitPoints()
		<< ", EP=" << obj.getEnergyPoints() << std::endl << std::endl;
}

static void test_construction_and_identity() {
	print_header("🏗️", "Construction & identity");
	DiamondTrap d("Diamond");
	print_status(d);
	d.whoAmI();
}

static void test_attack_and_damage() {
	print_header("💥", "Attack, damage & repair");
	DiamondTrap attacker("D-Atk");
	DiamondTrap defender("D-Def");
	print_status(attacker);
	print_status(defender);
	attacker.attack(defender.getName());
	defender.takeDamage(attacker.getAttackDamage());
	defender.beRepaired(5);
	print_status(defender);
}

static void test_energy_exhaustion() {
	print_header("🔋", "Energy exhaustion");
	DiamondTrap d("D-Energy");
	int attacks = d.getEnergyPoints() + 2;
	for (int i = 0; i < attacks; ++i) d.attack("target");
	print_status(d);
}

static void test_polymorphism() {
	print_header("🧬", "Polymorphism: base pointer to derived");
	ClapTrap* poly = new DiamondTrap("PolyDiamond");
	print_status(*poly);
	poly->attack("poly target");
	delete poly;
}

static void test_combined_specials() {
	print_header("🔒🎉", "Combined specials (Scav + Frag behaviors)");
	DiamondTrap d("D-Special");
	d.guardGate();
	d.highFivesGuys();
}

struct TestCase { const char* name; void (*func)(); };

static TestCase test_cases[] = {
	{"Construction & identity", test_construction_and_identity},
	{"Attack, damage & repair", test_attack_and_damage},
	{"Energy exhaustion", test_energy_exhaustion},
	{"Polymorphism", test_polymorphism},
	{"Combined specials", test_combined_specials}
};

static void show_menu() {
	std::cout << CYAN << "\n 🧪    Choose a test case" << RESET << "\n" << std::endl;
	int total = sizeof(test_cases)/sizeof(TestCase);
	for (int i = 0; i < total; ++i) {
		std::cout << " " << YELLOW << std::setw(2) << (i+1) << "." << RESET << "  "
			<< test_cases[i].name << "\n";
	}
	std::cout << " " << RED << std::setw(2) << 0 << "." << RESET << "  Exit\n";
	std::cout << "\nEnter test number: ";
}

int main() {
	std::string line;
	int total = sizeof(test_cases)/sizeof(TestCase);
	while (true) {
		show_menu();
		if (!std::getline(std::cin, line)) break;
		if (line.empty()) continue;
		int choice = atoi(line.c_str());
		if (choice == 0) break;
		if (choice < 1 || choice > total) {
			std::cout << RED << "Invalid input!" << RESET << "\n";
			continue;
		}
		test_cases[choice-1].func();
	}
	std::cout << "\n✅ Tests finished!\n" << std::endl;
	return 0;
}

