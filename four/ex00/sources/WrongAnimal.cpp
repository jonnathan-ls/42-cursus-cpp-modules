/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 15:55:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "style.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << GREEN << "🔒 WrongAnimal default constructor called"
		<< RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "🔒 WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << MAGENTA << "🔒 WrongAnimal copy constructor called"
		<< RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << ORANGE << "🔒 WrongAnimal copy assignment operator called" 
		<< RESET << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << YELLOW << "🔊 WrongAnimal makes a generic sound."
		<< RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
