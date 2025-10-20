/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/18 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "style.hpp"

#include <iostream>

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap " << this->name
		<< " has been destroyed!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << GREEN << "ClapTrap " << this->name
		<< " has been created!" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
	*this = other;
	std::cout << GREEN << "ClapTrap " << this->name
		<< " has been copied!" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << GREEN << "ClapTrap " << this->name
		<< " has been assigned!" << RESET << std::endl;
	return *this;
}

std::string ClapTrap::getName() const {
	return this->name;
}

int ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ClapTrap "  << RESET << this->name
			<< " cannot attack due to insufficient energy or hit points."
			<< RESET << std::endl;
		return;
	}
	this->energyPoints -= this->energyPoints / 10;
	std::cout << ORANGE << "ClapTrap " << CYAN
		<< this->name << " attacks " << YELLOW
		<< target << RESET << ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ClapTrap "  << RESET << this->name
			<< " is already destroyed and cannot take more damage."
			<< RESET << std::endl;
		return;
	}
	if (amount <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ClapTrap "  << RESET << this->name
			<< " received non-positive damage amount: " << amount
			<< RESET << std::endl;
		return;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << ORANGE << "ClapTrap " << MAGENTA << this->name << " takes "
		<< RESET  << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ClapTrap "  << RESET << this->name
			<< " cannot repair due to insufficient energy or hit points."
			<< RESET << std::endl;
		return;
	}
	if (amount <= 0) {
		std::cout << YELLOW << "⚠️  [ WARN ] ClapTrap "  << RESET << this->name
			<< RESET << " received non-positive repair amount: "
			<< amount << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints -= this->energyPoints / 10;
	std::cout << ORANGE << "ClapTrap " << GREEN << this->name << " repairs "
		<< RESET << amount << " hit points!" << RESET << std::endl;
}