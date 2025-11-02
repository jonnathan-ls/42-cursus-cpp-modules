/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 17:34:22 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "style.hpp"
#include <iostream>

Cat::Cat() {
	this->brain = new Brain();
	std::cout << GREEN << "🔒 Cat default constructor called"
		<< RESET << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << RED << "🔒 Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << MAGENTA << "🔒 Cat copy constructor called"
		<< RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << ORANGE << "🔒 Cat copy assignment operator called"
		<< RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << YELLOW << "🔊 Cat goes meows and 💭 think: "
		<< this->brain->think(1) << RESET << std::endl;
}

void Cat::sleep() const {
	std::cout << BLUE << "💤 Cat is sleeping." << RESET << std::endl;
	this->brain->clearIdeas();
}
