/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 20:31:09 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "style.hpp"

#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	std::cout << GREEN << "🔒 Dog default constructor called"
		<< RESET << std::endl;
}

Dog::~Dog() {
	std::cout << RED << "🔒 Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << MAGENTA << "🔒 Dog copy constructor called"
		<< RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << ORANGE << "🔒 Dog copy assignment operator called"
		<< RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW << "🔊 Dog barks."
		<< RESET << std::endl;
}
