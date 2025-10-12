/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/12 16:19:55 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/**
 * @class Point
 * @brief Represents a point in 2D space with fixed-point coordinates.
 */
class Point
{
private:
	/** The x-coordinate of the point. */
	Fixed const x;
	/** The y-coordinate of the point. */
	Fixed const y;

public:
	Point();
	Point(float const x, float const y);
	Point(Point const &src);
	~Point();

	Point &operator=(Point const &rhs);
	
	/** Gets the x-coordinate of the point.
	 * @return The x-coordinate as a Fixed object.
	 */
	Fixed const getX() const;
	/** Gets the y-coordinate of the point.
	 * @return The y-coordinate as a Fixed object.
	 */
	Fixed const getY() const;
};

#endif