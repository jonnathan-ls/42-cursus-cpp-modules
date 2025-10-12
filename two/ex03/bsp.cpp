/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/12 17:16:06 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

/**
 * @brief Computes the cross product of vectors 
 * from start to final and start to point.
 * @param start The starting point of the vectors.
 * @param final The ending point of the first vector.
 * @param point The ending point of the second vector.
 * @return The cross product as a Fixed value.
 * @note The sign of the cross product indicates the relative position:
 * positive if point is to the left of the line from start to final,
 * negative if to the right, and zero if collinear.
 */
static Fixed cross_product(Point const start,
	Point const final, Point const point)
{
	Fixed sf_x = final.getX() - start.getX();
	Fixed sf_y = final.getY() - start.getY();
	Fixed sp_x = point.getX() - start.getX();
	Fixed sp_y = point.getY() - start.getY();
	return (sf_x * sp_y - sf_y * sp_x);
}

/**
 * @brief Checks if any of the cross product signals is zero,
 * indicating the point is on an edge or vertex of the triangle.
 * @param signal1 The first cross product signal.
 * @param signal2 The second cross product signal.
 * @param signal3 The third cross product signal.
 * @return true if any signal is zero, false otherwise.
 */
bool is_colinear(Point const start,
	Point const final, Point const point)
{
	Fixed cross = cross_product(start, final, point);
	return (cross == Fixed(0));
}

/**
 * @brief Determines if the point is inside the triangle
 * based on the signs of the cross products.
 * @param signal1 The cross product for edge AB.
 * @param signal2 The cross product for edge BC.
 * @param signal3 The cross product for edge CA.
 * @return true if the point is inside the triangle, false otherwise.
 */
bool is_on_segment(Point const start,
	Point const final, Point const point)
{
	if (!is_colinear(start, final, point))
		return (false);

	Fixed min_x = (start.getX() < final.getX()) ? start.getX() : final.getX();
	Fixed max_x = (start.getX() > final.getX()) ? start.getX() : final.getX();
	Fixed min_y = (start.getY() < final.getY()) ? start.getY() : final.getY();
	Fixed max_y = (start.getY() > final.getY()) ? start.getY() : final.getY();

	return (point.getX() >= min_x && point.getX() <= max_x
		&& point.getY() >= min_y && point.getY() <= max_y);
}

/**
 * @brief Checks if the point is on any edge or vertex of the triangle.
 * @param signal1 The cross product for edge AB.
 * @param signal2 The cross product for edge BC.
 * @param signal3 The cross product for edge CA.
 * @return true if the point is on an edge or vertex, false otherwise.
 */
bool same_sign_and_nonzero(Fixed s1, Fixed s2, Fixed s3) {
	return (s1 > Fixed(0) && s2 > Fixed(0) && s3 > Fixed(0))
		|| (s1 < Fixed(0) && s2 < Fixed(0) && s3 < Fixed(0));
}

/**
 * @brief Determines if a point is inside
 * the triangle formed by points a, b, and c.
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to test.
 * @return true if the point is inside the triangle, false otherwise.
 * @note BSP = Binary Space Partitioning
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (is_on_segment(a, b, point)
		|| is_on_segment(b, c, point)
		|| is_on_segment(c, a, point))
		return (false);

	Fixed cross_sign_ab = cross_product(a, b, point);
	Fixed cross_sign_bc = cross_product(b, c, point);
	Fixed cross_sign_ca = cross_product(c, a, point);
	
	return same_sign_and_nonzero(cross_sign_ab, cross_sign_bc, cross_sign_ca);
}
