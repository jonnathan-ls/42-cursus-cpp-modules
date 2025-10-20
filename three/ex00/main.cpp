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
#include "ClapTrap.hpp"
#include "style.hpp"


static void print_header(const std::string& emoji, const std::string& title) {
	std::cout << std::endl << emoji << " " << title << "\n" << std::endl;
}

static void print_status(const ClapTrap& obj) {
	std::cout << std::endl << "🤖 Status of " << obj.getName()
		<< ": HP=" << obj.getHitPoints()
		<< ", EP=" << obj.getEnergyPoints() << std::endl;
}

static void assert_attack(
ClapTrap& attacker, ClapTrap& target, int expectedDamage) {
	std::cout << "🗡️  " << attacker.getName()
		<< " attacked " << target.getName() << std::endl << std::endl;
	attacker.attack(target.getName());
	target.takeDamage(expectedDamage);
}

int main(void) {
	ClapTrap robo1("Wall-E");
	ClapTrap robo2("EVA");
	print_status(robo1);
	print_status(robo2);

	print_header("💥 ", "Basic attack");
	assert_attack(robo1, robo2, 1);
	print_status(robo2);

	print_header("🔋", "Energy draining");
	for (int i = 0; i < 9; ++i) {
		robo1.attack("target");
	}
	print_status(robo1);

	print_header("🔧", "Repair");
	robo2.beRepaired(5);
	print_status(robo2);

	print_header("💀", "Fatal damage");
	robo2.takeDamage(100);
	print_status(robo2);

	print_header("🪫 ", "Attack without energy");
	robo1.attack("target");
	print_status(robo1);

	print_header("🪫 ", "Repair without energy");
	robo1.beRepaired(10);
	print_status(robo1);

	std::cout << "\n✅ All basic ClapTrap tests executed!\n";
	std::cout << std::endl;
	return 0;
}