/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/11 22:59:53 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "style.hpp"
#include <cmath>
#include <limits>

static int clamp_to_int(double value)
{
	double imax = static_cast<double>(std::numeric_limits<int>::max());
	double imin = static_cast<double>(std::numeric_limits<int>::min());
	if (value > imax)
		return std::numeric_limits<int>::max();
	if (value < imin)
		return std::numeric_limits<int>::min();
	return static_cast<int>(value);
}

Fixed::Fixed() : rawFixedPointValue(0)
{
	std::cout << "[ " << this << " ] "
		<< GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(int nbr)
{
	const int scale = 1 << fractionalBits;
	double tmpd = static_cast<double>(nbr) * static_cast<double>(scale);
	rawFixedPointValue = clamp_to_int(tmpd);
	std::cout << "[ " << this << " ] "
		<< GREEN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(float nbr)
{
	const int scale = 1 << fractionalBits;
	float scaled = roundf(nbr * static_cast<float>(scale));
	double tmpd = static_cast<double>(scaled);
	rawFixedPointValue = clamp_to_int(tmpd);
	std::cout << "[ " << this << " ] "
		<< GREEN << "Float constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "[ " << this << " ] "
		<< GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "[ " << this << " ] "
		<< GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		rawFixedPointValue = other.rawFixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "[ " << this << " ] "
		<< RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const
{
	return rawFixedPointValue;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(rawFixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return rawFixedPointValue / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	return os << fixed.toFloat();
}