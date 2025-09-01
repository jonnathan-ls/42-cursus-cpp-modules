/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/08/31 21:10:25 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(int nbr);
	Fixed(float nbr);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int toInt(void) const;
	int getRawBits() const;
	float toFloat(void) const;

private:
	int rawFixedPointValue;
	static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& f);

#endif