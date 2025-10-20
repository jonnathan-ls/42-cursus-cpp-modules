/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/18 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "style.hpp"

#include <iostream>

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap " << this->name
		<< " has been destroyed!" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
	std::cout << GREEN << "ScavTrap " << this->name
		<< " has been created!" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other) {
	*this = other;
	std::cout << GREEN << "ScavTrap " << this->name
		<< " has been copied!" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "ScavTrap " << this->name << RESET
		<< " has been assigned!" << RESET << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ScavTrap " << RESET  << this->name
			<< " cannot attack due to insufficient energy or hit points."
			<< RESET << std::endl;
		return;
	}
	this->energyPoints -= this->energyPoints / 10;
	std::cout << PINK << "ScavTrap " << CYAN
		<< this->name << " attacks " << YELLOW
		<< target << RESET << ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << PINK << "ScavTrap " << this->name << RESET
		<< " is now in Gate Keeper mode." << RESET << std::endl;
}