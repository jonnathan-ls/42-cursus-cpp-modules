/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/19 21:51:28 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "style.hpp"

#include <iostream>

DiamondTrap::~DiamondTrap() {
	std::cout << RED << "DiamondTrap " << this->name
		<< " has been destroyed!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &n)
	: ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n), name(n) {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << GREEN << "DiamondTrap " << this->name
		<< " has been created!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << GREEN << "DiamondTrap " << this->name
		<< " has been copied!" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "DiamondTrap " << this->name << RESET
		<< " has been assigned!" << RESET << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << PURPLE << "DiamondTrap name: " << CYAN << this->name
		<< PURPLE << ", ClapTrap name: " << CYAN << ClapTrap::name
		<< RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
