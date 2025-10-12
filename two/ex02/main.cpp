/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/12 12:00:00 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cmath>
#include "Fixed.hpp"
#include "style.hpp"

static void	print_header(std::string emoji, std::string title)
{
	std::cout << MAGENTA << "\n" << emoji << "  " << title
		<< "\n" << RESET << std::endl;
}

static void	print_title(const std::string& title)
{
	std::cout << ORANGE << title << RESET;
}

static void print_subtitle(const std::string& subtitle)
{
	std::cout << std::endl << ORANGE << "📦  "
		<< subtitle << RESET << std::endl << std::endl;
}

static void	print_test(std::string label, std::string value)
{
	std::cout << YELLOW << " ⚬  " << RESET
		<< label << " = " << value << std::endl;
}

static void	subject_test(void)
{
	print_title("✅  Subject Test Case");
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::endl;
	print_subtitle("a = 0, b = 5.05 * 2");
	std::cout << " " << a << std::endl;
	std::cout << " " << ++a << std::endl;
	std::cout << " " << a << std::endl;
	std::cout << " " << a++ << std::endl;
	std::cout << " " << a << std::endl;
	std::cout << " " << b << std::endl;
	std::cout << " " << Fixed::max( a, b ) << std::endl;
}

static void	test_arithmetic(void)
{
	print_header("➕", "ARITHMETIC OPERATORS");
	Fixed a(10.5f), b(2.5f);
	std::stringstream ss;

	print_subtitle("a = 10.5, b = 2.5");
	ss.str(""); ss << (a + b); print_test("a + b", ss.str());
	ss.str(""); ss << (a - b); print_test("a - b", ss.str());
	ss.str(""); ss << (a * b); print_test("a * b", ss.str());
	ss.str(""); ss << (a / b); print_test("a / b", ss.str());
	ss.str(""); ss << (a / Fixed(0));
	print_test("a / 0", ss.str());

	Fixed neg(-5.25f), pos(3.0f);
	print_test("neg", "-5.25");
	print_test("pos", "3.0");
	ss.str(""); ss << (neg + pos);
	print_test("neg + pos", ss.str());
	ss.str(""); ss << (neg * pos);
	print_test("neg * pos", ss.str());
}

static void	test_comparison(void)
{
	print_header("⚖️ ", "COMPARISON OPERATORS");
	Fixed a(10.5f), b(5.25f), c(10.5f);

	print_subtitle("a = 10.5, b = 5.25, c = 10.5");
	print_test("a > b", (a > b) ? "true" : "false");
	print_test("a < b", (a < b) ? "true" : "false");
	print_test("a >= c", (a >= c) ? "true" : "false");
	print_test("a <= c", (a <= c) ? "true" : "false");
	print_test("a == c", (a == c) ? "true" : "false");
	print_test("a != b", (a != b) ? "true" : "false");

	Fixed s1(0.00390625f), s2(0.0078125f);
	print_subtitle("s1 = 0.00390625, s2 = 0.0078125");
	print_test("s1", "0.00390625");
	print_test("s2", "0.0078125");
	print_test("s1 < s2", (s1 < s2) ? "true" : "false");
	print_test("s1 == s2", (s1 == s2) ? "true" : "false");
}

static void	test_increment(void)
{
	print_header("⬆️ ", "INCREMENT/DECREMENT");
	Fixed a(5.0f);
	std::stringstream ss;

	print_subtitle("a = 5.0");
	ss.str(""); ss << a; print_test("a", ss.str());
	ss.str(""); ss << (++a); print_test("++a", ss.str());
	ss.str(""); ss << a; print_test("a", ss.str());
	ss.str(""); ss << (a++); print_test("a++", ss.str());
	ss.str(""); ss << a; print_test("a", ss.str());
	ss.str(""); ss << (--a); print_test("--a", ss.str());
	ss.str(""); ss << a; print_test("a", ss.str());
	ss.str(""); ss << (a--); print_test("a--", ss.str());
	ss.str(""); ss << a; print_test("a", ss.str());
}

static void	test_epsilon(void)
{
	print_header("🔬", "EPSILON INCREMENTS");
	Fixed eps(0);
	std::stringstream ss;
	int i;

	i = 0;
	print_subtitle("Incrementing by smallest step (epsilon)");
	while (i++ < 5)
	{
		ss.str(""); ss << (++eps);
		print_test("++eps", ss.str());
	}
}

static void	test_negative(void)
{
	print_header("➖", "NEGATIVE INCREMENTS");
	Fixed neg(-1.0f);
	std::stringstream ss;

	print_subtitle("neg = -1.0");
	ss.str(""); ss << (++neg); print_test("++neg", ss.str());
	ss.str(""); ss << (++neg); print_test("++neg", ss.str());
}

static void	test_min_max(void)
{
	print_header("🔢", "MIN/MAX FUNCTIONS");
	Fixed a(42.42f), b(10.5f);
	std::stringstream ss;

	print_subtitle("a = 42.42, b = 10.5");
	ss.str(""); ss << Fixed::min(a, b);
	print_test("min(a, b)", ss.str());
	ss.str(""); ss << Fixed::max(a, b);
	print_test("max(a, b)", ss.str());

	Fixed const c(100.0f), d(50.0f);
	print_subtitle("c = 100.0 (const), d = 50.0 (const)");
	ss.str(""); ss << Fixed::min(c, d);
	print_test("min(c, d)", ss.str());
	ss.str(""); ss << Fixed::max(c, d);
	print_test("max(c, d)", ss.str());

	Fixed neg1(-10.0f), neg2(-5.0f);
	print_subtitle("neg1 = -10.0, neg2 = -5.0");
	ss.str(""); ss << Fixed::min(neg1, neg2);
	print_test("min(neg1, neg2)", ss.str());
	ss.str(""); ss << Fixed::max(neg1, neg2);
	print_test("max(neg1, neg2)", ss.str());
}

static void	test_edge_cases(void)
{
	print_header("⚠️ ", "EDGE CASES");
	Fixed zero(0), one(1);
	std::stringstream ss;

	print_subtitle("zero = 0, one = 1");
	ss.str(""); ss << (zero + one);
	print_test("zero + one", ss.str());
	ss.str(""); ss << (zero * one);
	print_test("zero * one", ss.str());
	ss.str(""); ss << (zero - one);
	print_test("zero - one", ss.str());

	Fixed lsb(0.00390625f);
	print_subtitle("lsb = 0.00390625 (smallest step)");
	ss.str(""); ss << lsb; print_test("lsb", ss.str());
	ss.str(""); ss << (lsb * Fixed(2));
	print_test("lsb * 2", ss.str());
	ss.str(""); ss << (lsb / Fixed(2));
	print_test("lsb / 2", ss.str());
}

static void	test_chained(void)
{
	print_header("🔗", "CHAINED OPERATIONS");
	Fixed x(2.0f), y(3.0f), z(4.0f);
	std::stringstream ss;

	print_subtitle("x = 2.0, y = 3.0, z = 4.0");
	ss.str(""); ss << ((x + y) * z);
	print_test("(x + y) * z", ss.str());
	ss.str(""); ss << (x * y + z);
	print_test("x * y + z", ss.str());
}

static void	test_precision(void)
{
	print_header("🎯", "PRECISION & ROUNDING");
	Fixed f1(1.5f), f2(2.5f);
	std::stringstream ss;

	print_subtitle("f1 = 1.5, f2 = 2.5");
	ss.str(""); ss << f1.toInt();
	print_test("Fixed(1.5).toInt()", ss.str());
	ss.str(""); ss << f2.toInt();
	print_test("Fixed(2.5).toInt()", ss.str());

	Fixed sum(0);
	int i;

	i = 0;
	print_subtitle("Sum of ten 0.1 increments");
	while (i++ < 10)
		sum = sum + Fixed(0.1f);
	ss.str(""); ss << sum;
	print_test("sum of 10 x 0.1", ss.str());

	Fixed div1(1.0f), div2(3.0f);
	print_subtitle("Division precision: 1.0 / 3.0");
	ss.str(""); ss << (div1 / div2);
	print_test("1.0 / 3.0", ss.str());
	ss.str(""); ss << ((div1 / div2) * div2);
	print_test("(1.0/3.0) * 3", ss.str());
}

static void	test_expressions(void)
{
	print_header("🧮", "COMPLEX EXPRESSIONS");
	Fixed a(5.0f), b(2.0f), c(3.0f);
	std::stringstream ss;

	print_subtitle("a = 5.0, b = 2.0, c = 3.0");
	ss.str(""); ss << ((a + b) * c);
	print_test("(a + b) * c", ss.str());
	ss.str(""); ss << (a * b + c);
	print_test("a * b + c", ss.str());
	ss.str(""); ss << ((a - b) / (c - Fixed(1)));
	print_test("(a - b) / (c - 1)", ss.str());

	Fixed x(10.0f);
	print_subtitle("x = 10.0");
	ss.str(""); ss << (++x * Fixed(2));
	print_test("++x * 2", ss.str());
	ss.str(""); ss << x; print_test("x after", ss.str());

	Fixed max_v = (a > b) ? a : b;
	ss.str(""); ss << max_v;
	print_test("(a > b) ? a : b", ss.str());
}

int	main(void)
{
	std::cout << std::endl;
	subject_test();
	test_arithmetic();
	test_comparison();
	test_increment();
	test_epsilon();
	test_negative();
	test_min_max();
	test_edge_cases();
	test_chained();
	test_precision();
	test_expressions();
	std::cout << std::endl;
	return (0);
}
