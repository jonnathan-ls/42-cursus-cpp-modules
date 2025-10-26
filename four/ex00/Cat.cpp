/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 20:31:09 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "style.hpp"

#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	std::cout << GREEN << "🔒 Cat default constructor called"
		<< RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED << "🔒 Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << MAGENTA << "🔒 Cat copy constructor called"
		<< RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << ORANGE << "🔒 Cat copy assignment operator called"
		<< RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << YELLOW << "🔊 Cat meows."
		<< RESET << std::endl;
}
