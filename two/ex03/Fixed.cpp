/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/12 14:43:00 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "style.hpp"
#include <cmath>
#include <limits>

/**
 * @brief Clamps a double value to the range of int and converts it to int.
 *        If the value exceeds int limits, it returns INT_MAX or INT_MIN.
 * @param value The double value to clamp and convert.
 * @return The clamped int value.
 */
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

Fixed::Fixed() : rawFixedPointValue(0){}

Fixed::Fixed(int nbr)
{
	const int scale = 1 << fractionalBits;
	double tmpd = static_cast<double>(nbr) * static_cast<double>(scale);
	rawFixedPointValue = clamp_to_int(tmpd);
}

Fixed::Fixed(float nbr)
{
	const int scale = 1 << fractionalBits;
	float scaled = roundf(nbr * static_cast<float>(scale));
	double tmpd = static_cast<double>(scaled);
	rawFixedPointValue = clamp_to_int(tmpd);
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		rawFixedPointValue = other.rawFixedPointValue;
	return *this;
}

Fixed::~Fixed(){}

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

bool Fixed::operator>(const Fixed& other) const
{
    return rawFixedPointValue > other.rawFixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
    return rawFixedPointValue < other.rawFixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return rawFixedPointValue >= other.rawFixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return rawFixedPointValue <= other.rawFixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return rawFixedPointValue == other.rawFixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return rawFixedPointValue != other.rawFixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.rawFixedPointValue == 0) {
		std::cerr << RED << "Error: Division by zero" << RESET << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	++rawFixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	rawFixedPointValue++;
	return temp;
}

Fixed& Fixed::operator--()
{
	--rawFixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	rawFixedPointValue--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	return os << fixed.toFloat();
}