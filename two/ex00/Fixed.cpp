/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/08/31 20:52:09 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "style.hpp"

Fixed::Fixed() : rawFixedPointValue(0) {
	std::cout << "[ " << this << " ] "
		<< GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "[ " << this << " ] "
		<< GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "[ " << this << " ] "
		<< GREEN << "Copy assignment operator called" 
		<< RESET << std::endl;
	if (this != &other) {
		rawFixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "[ " << this << " ] "
		<< RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "[ " << this << " ] " << YELLOW 
		<< "getRawBits member function called"
		<< RESET << std::endl;
	return rawFixedPointValue;
}
