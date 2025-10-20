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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "style.hpp"

static void print_header(const std::string& emoji, const std::string& title) {
	std::cout << std::endl << emoji << " " << title << "\n" << std::endl;
}

static void print_status(const ClapTrap& obj) {
	std::cout << "🤖 Status of " << obj.getName()
		<< ": HP=" << obj.getHitPoints()
		<< ", EP=" << obj.getEnergyPoints() << std::endl << std::endl;
}

static void assert_attack(
const std::string& attackerName, const std::string& targetName,
int expectedDamage, bool attackerIsScav, bool attackerIsFrag) {
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	ClapTrap* attacker = NULL;
	if (attackerIsScav) attacker = new ScavTrap(attackerName);
	else if (attackerIsFrag) attacker = new FragTrap(attackerName);
	else attacker = new ClapTrap(attackerName);
	ClapTrap* target = new ClapTrap(targetName);
	print_header("💥 ", attacker->getName() + " attacked " + target->getName());
	print_status(*target);
	attacker->attack(target->getName());
	target->takeDamage(expectedDamage);
	std::cout << std::endl;
	print_status(*target);
	delete attacker;
	delete target;
	std::cout << "-----------------------------------" << std::endl;
}

static void assert_energ(
const std::string& name, int times, bool isScav,
bool isFrag, const std::string& title) {
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	ClapTrap* obj = NULL;
	if (isScav) obj = new ScavTrap(name);
	else if (isFrag) obj = new FragTrap(name);
	else obj = new ClapTrap(name);
	print_header("🔋", title);
	print_status(*obj);
	for (int i = 0; i < times; ++i) obj->attack("target");
	std::cout << std::endl;
	print_status(*obj);
	delete obj;
	std::cout << "-----------------------------------" << std::endl;
}

static bool choose_scav_or_frag(bool &isScav, bool &isFrag) {
	static int counter = 0;
	counter++;
	if ((counter % 2) == 0) {
		isScav = true; isFrag = false;
		std::cout << "Class in processing: " << "ScavTrap" << std::endl;
	} else {
		isScav = false; isFrag = true;
		std::cout << "Class in processing: " << "FragTrap" << std::endl;
	}
	return true;
}

static void test_attack() {
	bool useScav = false, useFrag = false;
	choose_scav_or_frag(useScav, useFrag);
	int expectedDamage = 5;
	if (useFrag) expectedDamage = 30;
	else if (useScav) expectedDamage = 20;
	std::string attackerName = "Attacker";
	std::string targetName = "Target";
	assert_attack(attackerName, targetName, expectedDamage, useScav, useFrag);
}

static void test_drain() {
	bool useScav = false, useFrag = false;
	choose_scav_or_frag(useScav, useFrag);
	std::string name;
	if (useScav) name = "Optimus";
	else if (useFrag) name = "Violet";
	else name = "Wall-E";
	int times = 5;
	assert_energ(name, times, useScav, useFrag, "Energy draining");
}

static void test_fatal() {
	bool useScav = false, useFrag = false;
	choose_scav_or_frag(useScav, useFrag);
	std::string attackerName = "Killer";
	std::string targetName = "Victim";
	int expectedDamage = 100;
	assert_attack(attackerName, targetName, expectedDamage, useScav, useFrag);
}

static void test_polymorphism() {
	print_header("🧬", "Polymorphism: ClapTrap pointer to ScavTrap");
	ClapTrap* poly = new ScavTrap("PolyBot");
	print_status(*poly);
	poly->attack("polymorphic target");
	delete poly;
}

static void test_special() {
	print_header("🎉", "FragTrap special ability");
	FragTrap ft("Violet");
	ft.highFivesGuys();
}

struct TestCase {
	const char* name;
	void (*func)();
};

static TestCase test_cases[] = {
	{"💥 Attack (alternating)", test_attack},
	{"🔋 Drain energy (alternating)", test_drain},
	{"💀 Fatal attack (alternating)", test_fatal},
	{"🧬 Polymorphism (ScavTrap)", test_polymorphism},
	{"🔒 Special ability (Frag)", test_special}
};

void run_test(int opcao) {
	int total = sizeof(test_cases)/sizeof(TestCase);
	if (opcao < 1 || opcao > total) {
		std::cout << RED << "Invalid option!" << RESET << "\n";
		return;
	}
	test_cases[opcao-1].func();
}

void show_menu() {
	std::cout << CYAN << "\n 🧪    Chosen a test case"
		<< RESET << "\n" << std::endl;
	int total = sizeof(test_cases)/sizeof(TestCase);
	for (int i = 0; i < total; ++i) {
		std::cout << " " << YELLOW << std::setw(2)
			<< (i+1) << "." << RESET << "  "
			<< test_cases[i].name << "\n";
	}
	std::cout << " " << RED << std::setw(2) << 0 
		<< "." << RESET << "  ❌ Exit\n";
	std::cout << "\nEnter test number: ";
}

int main(void) {
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
		run_test(choice);
	}
	std::cout << "\n✅ Tests finished!\n" << std::endl;
	return 0;
}