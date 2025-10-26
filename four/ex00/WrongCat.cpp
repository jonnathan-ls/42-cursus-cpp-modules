/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 15:50:36 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "style.hpp"
#include <iostream>

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << GREEN << "🔒 WrongCat default constructor called"
		<< RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED << "🔒 WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << MAGENTA << "🔒 WrongCat copy constructor called"
		<< RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << ORANGE << "🔒 WrongCat copy assignment operator called"
		<< RESET << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << YELLOW << "🔊 WrongCat meows."
		<< RESET << std::endl;
}
