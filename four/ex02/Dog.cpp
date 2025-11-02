/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 21:51:12 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "style.hpp"
#include <iostream>

Dog::Dog() {
	this->brain = new Brain();
	std::cout << GREEN << "🔒 default constructor called" << RESET << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << RED << "🔒 destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << MAGENTA << "🔒 copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
	}
	std::cout << ORANGE << "🔒 copy assignment operator called"
		<< RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW << "🔊 Dog goes barks and 💭 think: "
		<< this->brain->think(11) << RESET << std::endl;
}

void Dog::sleep() const {
	std::cout << BLUE << "💤 Dog is sleeping." << RESET << std::endl;
	this->brain->clearIdeas();
}
