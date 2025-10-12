/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/12 16:33:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "style.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &src) : x(src.x), y(src.y) {}

Point &Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		std::cout << YELLOW << "⚠️  Warning: "
			<< "Attempt to assign to a Point object (lhs = rhs)."
			<< " This operation is not allowed as Point members are const."
			<< RESET << std::endl;
	}
	return *this;
}

Point::~Point() {}

Fixed const Point::getX() const {
	return this->x;
}

Fixed const Point::getY() const {
	return this->y;
}
