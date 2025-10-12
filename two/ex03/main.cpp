/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/08/31 18:49:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "style.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

struct Triangle {
	Point a_point;
	Point b_point;
	Point c_point;
};

static void	print_header(std::string emoji, std::string title)
{
	std::cout << MAGENTA << "\n" << emoji << "  " << title
		<< "\n" << RESET << std::endl;
}

static void print_title(const std::string& title)
{
	std::cout << std::endl << ORANGE << "📦  "
		<< title << RESET << std::endl << std::endl;
}


static void	assert_triangle_test(Triangle& triangle, Point point)
{
	bool res = bsp(triangle.a_point, triangle.b_point, triangle.c_point, point);
	std::cout << YELLOW << " ⚬  " << RESET;
	std::cout << "Point("<< point.getX().toFloat() << ", "
		<< point.getY().toFloat() << ") is "
		<< (res ? "inside" : "outside") << " the triangle." << std::endl;
}

/*
 * ASCII visualization (approximate) for triangle A(2,2), B(6,9), C(9,2)
 * y
 * 10 |           .
 *  9 |      B(6,9)
 *  8 |       .
 *  7 |      .   P_bc(7,6.67)
 *  6 |     .  
 *  5 |    .      .
 *  4 |   .  P_ab(3,3.75)
 *  3 |  .
 *  2 | A(2,2) . . . . P_ca(5,2) . C(9,2)
 *  1 |
 *    ------------------------------------------------ x
 *      0 1 2 3 4 5 6 7 8 9 10
 *
 * Explanation:
 *  - A at (2,2) and C at (9,2) form the horizontal base (CA).
 *  - B at (6,9) is the apex above the base.
 *  - P_ab is a point on AB (t=0.25 -> (3.0,3.75)).
 *  - P_bc is a point on BC (t=1/3 -> (7.0,6.666...)).
 *  - P_ca is on CA (5.0,2.0) — clearly on the base segment.
 */

int main(void)
{
	Triangle triangle = { Point(2, 2), Point(6, 9), Point(9, 2) };

	print_header("📐", "POINT IN TRIANGLE TESTS");

	std::cout << "Triangle vertices: A(2,2), B(6,9), C(9,2)" << std::endl;

	print_title("Testing inside cases");
	assert_triangle_test(triangle, Point(5.0f, 5.2f));
	assert_triangle_test(triangle, Point(5.1f, 4.0f));
	assert_triangle_test(triangle, Point(6.1f, 5.f));

	print_title("Testing outside cases");
	assert_triangle_test(triangle, Point(15.0f, 5.0f));
	assert_triangle_test(triangle, Point(0.0f, 0.0f));
	assert_triangle_test(triangle, Point(10.0f, 0.0f));
	assert_triangle_test(triangle, Point(5.0f, 0.0f));
	assert_triangle_test(triangle, Point(7.0f, 8.0f));
	assert_triangle_test(triangle, Point(5.0f, 10.0f));
	assert_triangle_test(triangle, Point(5.0f, 11.0f));
	assert_triangle_test(triangle, Point(-1.0f, -1.0f));
	assert_triangle_test(triangle, Point(0.0f, 5.0f));

	print_title("Testing vertices (should be outside)");
	assert_triangle_test(triangle, Point(2.0f, 2.0f)); // Vertex A
	assert_triangle_test(triangle, Point(6.0f, 9.0f)); // Vertex B
	assert_triangle_test(triangle, Point(9.0f, 2.0f)); // Vertex C
	
	print_title("Testing in the edge cases (should be outside)");
	assert_triangle_test(triangle, Point(3.0f, 3.75f)); // On edge AB
	assert_triangle_test(triangle, Point(7.0f, 6.6666667f)); // On edge BC
	assert_triangle_test(triangle, Point(5.0f, 2.0f)); // On edge CA

	std::cout << std::endl;

	return 0;
}
