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
int expectedDamage, bool attackerIsScav = false, bool targetIsScav = false) {
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	ClapTrap* attacker = attackerIsScav
		? new ScavTrap(attackerName) : new ClapTrap(attackerName);
	ClapTrap* target = targetIsScav
		? new ScavTrap(targetName) : new ClapTrap(targetName);
	print_header("💥 ", attacker->getName() + " attacked " + target->getName());
	print_status(*target);
	attacker->attack(target->getName());
	target->takeDamage(expectedDamage);
	print_status(*target);
	delete attacker;
	delete target;
	std::cout << "-----------------------------------" << std::endl;
}

static void assert_energ(
const std::string& name, int times, bool isScav, const std::string& title) {
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	ClapTrap* obj = isScav ? new ScavTrap(name) : new ClapTrap(name);
	print_header("🔋", title);
	print_status(*obj);
	for (int i = 0; i < times; ++i) obj->attack("target");
	std::cout << std::endl;
	print_status(*obj);
	delete obj;
	std::cout << "-----------------------------------" << std::endl;
}

static void test_attack_ct_st() {
	assert_attack("Wall-E", "Optimus", 20, false, true); 
}

static void test_attack_st_ct() {
	assert_attack("Optimus", "Wall-E", 20, true, false);
}

static void test_energy_ct() {
	assert_energ("Wall-E", 5, false, "Energy draining ClapTrap");
}

static void test_energy_st() {
	assert_energ("Optimus", 5, true, "Energy draining ScavTrap");
}

static void test_attack_light_ct() {
	assert_attack("Wall-E", "Wall-E", 5, false, false);
}

static void test_attack_light_st() {
	assert_attack("Optimus", "Optimus", 10, true, true);
}

static void test_attack_fatal_ct() {
	assert_attack("Wall-E", "Wall-E", 100, false, false);
}

static void test_attack_fatal_st() {
	assert_attack("Optimus", "Optimus", 100, true, true);
}

static void test_no_energy_ct() {
	assert_energ("Wall-E", 11, false, "Attack without energy ClapTrap");
}

static void test_no_energy_st() {
	assert_energ("Optimus", 11, true, "Attack without energy ScavTrap");
}

static void test_polymorphism() {
	print_header("🧬", "Polymorphism: ClapTrap pointer to ScavTrap");
	ClapTrap* poly = new ScavTrap("PolyBot");
	print_status(*poly);
	poly->attack("polymorphic target");
	delete poly;
}

static void test_special() {
	print_header("🔒", "ScavTrap special ability");
	ScavTrap st("Optimus");
	st.guardGate();
}

struct TestCase {
	const char* name;
	void (*func)();
};

static TestCase test_cases[] = {
	{"💥 Ataque ClapTrap -> ScavTrap", test_attack_ct_st},
	{"💥 Ataque ScavTrap -> ClapTrap", test_attack_st_ct},
	{"🔋 Drenar energia ClapTrap", test_energy_ct},
	{"🔋 Drenar energia ScavTrap", test_energy_st},
	{"💥 Ataque leve ClapTrap", test_attack_light_ct},
	{"💥 Ataque leve ScavTrap", test_attack_light_st},
	{"💀 Ataque fatal ClapTrap", test_attack_fatal_ct},
	{"💀 Ataque fatal ScavTrap", test_attack_fatal_st},
	{"⚡ Ataque sem energia ClapTrap", test_no_energy_ct},
	{"⚡ Ataque sem energia ScavTrap", test_no_energy_st},
	{"🧬 Polimorfismo ClapTrap* -> ScavTrap", test_polymorphism},
	{"🔒 Habilidade especial ScavTrap", test_special}
};

void run_test(int opcao) {
	int total = sizeof(test_cases)/sizeof(TestCase);
	if (opcao < 1 || opcao > total) {
		std::cout << RED << "Opção inválida!" << RESET << "\n";
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
		<< "." << RESET << "  ❌ Sair\n";
	std::cout << "\nEscolha o número do teste: ";
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
			std::cout << RED << "Entrada inválida!" << RESET << "\n";
			continue;
		}
		run_test(choice);
	}
	std::cout << "\n✅ Testes finalizados!\n" << std::endl;
	return 0;
}