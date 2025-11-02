/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 14:21:23 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "style.hpp"
#include <iostream>

Cat::Cat() {
	this->brain = new Brain();
	std::cout << GREEN << "🔒 default constructor called"
		<< RESET << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << RED << "🔒 destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << MAGENTA << "🔒 copy constructor called"
		<< RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
	}
	std::cout << ORANGE << "🔒 copy assignment operator called"
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
