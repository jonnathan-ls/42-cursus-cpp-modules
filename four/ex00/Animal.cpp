/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 15:34:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "style.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << GREEN << "🔒 Animal default constructor called"
		<< RESET << std::endl;
}

Animal::~Animal() {
	std::cout << RED << "🔒 Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << MAGENTA << "🔒 Animal copy constructor called"
		<< RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << ORANGE << "🔒 Animal copy assignment operator called" 
		<< RESET << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << YELLOW << "🔊 Animal makes a generic sound."
		<< RESET << std::endl;
}