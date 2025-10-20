/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/18 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "style.hpp"

#include <iostream>

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap " << this->name
		<< " has been destroyed!" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
	std::cout << GREEN << "FragTrap " << this->name
		<< " has been created!" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap(other) {
	*this = other;
	std::cout << GREEN << "FragTrap " << this->name
		<< " has been copied!" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "FragTrap " << this->name<< RESET
		<< " has been assigned!" << RESET << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << PINK << "FragTrap " << this->name << RESET
		<< " is requesting a high five! ✋" << RESET << std::endl;
}