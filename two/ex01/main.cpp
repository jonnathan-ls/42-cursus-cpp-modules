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
#include <iomanip>
#include <climits>
#include <cmath>
#include "Fixed.hpp"
#include "style.hpp"

#define LOG_IN_MAIN "[ ---- main ---- ] "

static void inspect_raw_bits(float nbr)
{
	Fixed f(nbr);
	std::cout << LOG_IN_MAIN << "inspect nbr=" << nbr
		<< " raw=" << f.getRawBits()
		<< " fixed=" << f << "  as int: " << f.toInt() << std::endl;
}

static void test_int_limits(void)
{
	std::cout << MAGENTA << "\n--- INT LIMITS TEST ---" << RESET << std::endl;
	Fixed e(INT_MAX);
	Fixed f(INT_MIN);
	std::cout << LOG_IN_MAIN << "INT_MAX -> " << e
		<< "  as int: " << e.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "INT_MIN -> " << f
		<< "  as int: " << f.toInt() << std::endl;
	Fixed ef(static_cast<float>(INT_MAX));
	Fixed ff(static_cast<float>(INT_MIN));
	std::cout << LOG_IN_MAIN << "INT_MAX as float -> " << ef
		<< "  as int: " << ef.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "INT_MIN as float -> " << ff
		<< "  as int: " << ff.toInt() << std::endl;
}

static void test_precise(void)
{
	std::cout << MAGENTA << "\n--- PRECISION & LARGE VALUES ---" << RESET << std::endl;
	Fixed precise(123123123.13213231f);
	std::cout << LOG_IN_MAIN << "Precise float literal -> " << precise
		<< "  as int: " << precise.toInt() << std::endl;
	Fixed lf(1e7f);
	Fixed lfn(-1e7f);
	std::cout << LOG_IN_MAIN << "Large float 1e7 -> " << lf
		<< "  as int: " << lf.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "Large float -1e7 -> " << lfn
		<< "  as int: " << lfn.toInt() << std::endl;
}

static void test_zero_and_lsb(void)
{
	std::cout << MAGENTA << "\n--- ZERO & LSB ---" << RESET << std::endl;
	Fixed z0(0);
	Fixed zf(0.00390625f);
	std::cout << LOG_IN_MAIN << "Zero as float: " << z0
		<< "  as int: " << z0.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "One LSB (0.00390625) as float: "
		<< zf << "  as int: " << zf.toInt() << std::endl;
}

static void test_signs(void)
{
	std::cout << MAGENTA << "\n--- SIGNED VALUES ---" << RESET << std::endl;
	Fixed n1(-1);
	Fixed nf(-1.5f);
	std::cout << LOG_IN_MAIN << "Negative int -1 -> " << n1
		<< "  as int: " << n1.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "Negative float -1.5 -> " << nf
		<< "  as int: " << nf.toInt() << std::endl;
}

static void test_approx_range(void)
{
	std::cout << MAGENTA << "\n--- APPROX RANGE (fractionalBits=8) ---" << RESET << std::endl;
	const int approxMaxInt = INT_MAX / (1 << 8);
	Fixed big1(approxMaxInt);
	Fixed big2(approxMaxInt + 1);
	std::cout << LOG_IN_MAIN << "Approx max int representable (f=8): "
		<< approxMaxInt << std::endl;
	std::cout << LOG_IN_MAIN << "big1 -> " << big1
		<< "  as int: " << big1.toInt() << std::endl;
	std::cout << LOG_IN_MAIN << "big2 (one above) -> " << big2
		<< "  as int: " << big2.toInt() << std::endl;
}

static void test_inspect(void)
{
	std::cout << MAGENTA << "\n--- INSPECT FIXED DETAILS ---" << RESET << std::endl;
	inspect_raw_bits(0.0f);
	inspect_raw_bits(1.0f);
	inspect_raw_bits(-1.0f);
	inspect_raw_bits(123.456f);
	inspect_raw_bits(-123.456f);
	inspect_raw_bits(2);
	inspect_raw_bits(2.1);
}

static void basic_example(void)
{
	std::cout << GREEN
		"✅ Basic example (preserve this block exactly as requested)"
		<< RESET << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << LOG_IN_MAIN << "a is " << a << std::endl;
	std::cout << LOG_IN_MAIN << "b is " << b << std::endl;
	std::cout << LOG_IN_MAIN << "c is " << c << std::endl;
	std::cout << LOG_IN_MAIN << "d is " << d << std::endl;
	std::cout << LOG_IN_MAIN << "a is " << a.toInt()
		<< " as integer" << std::endl;
	std::cout << LOG_IN_MAIN << "b is " << b.toInt()
		<< " as integer" << std::endl;
	std::cout << LOG_IN_MAIN << "c is " << c.toInt()
		<< " as integer" << std::endl;
	std::cout << LOG_IN_MAIN << "d is " << d.toInt()
		<< " as integer" << std::endl;
}

static void other_cases(void)
{
	std::cout << MAGENTA << "\n----- OTHER CASES: range, sign, precision -----"
		<< RESET << std::endl;
	test_zero_and_lsb();
	test_signs();
	test_approx_range();
	test_int_limits();
	test_precise();
	test_inspect();
}

static void precision_test(void)
{
	std::cout << BLUE << "\nPrecision test (summing small increments)"
		<< RESET << std::endl;
	Fixed sum(0);
	for (int i = 0; i < 10; ++i)
		sum = Fixed(sum.toFloat() + 0.00390625f);
	std::cout << LOG_IN_MAIN << "sum after 10 LSB additions -> "
		<< sum << "  as int: " << sum.toInt() << std::endl;
}

static void summary(void)
{
	const int approxMaxInt = INT_MAX / (1 << 8);
	std::cout << CYAN << "\n🎯 Summary:" << RESET << std::endl;
	std::cout << LOG_IN_MAIN << " - fractionalBits = " << 8
		<< "  (LSB = 1/256 = 0.00390625)" << std::endl;
	std::cout << LOG_IN_MAIN << " - max integer representable (approx)"
		<< " = " << approxMaxInt << std::endl;
}

int main(void)
{
	std::cout << CYAN << "🔬 Fixed-point extended tests" << RESET
		<< std::endl;
	basic_example();
	other_cases();
	precision_test();
	summary();
	return 0;
}