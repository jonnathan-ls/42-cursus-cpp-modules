#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Span.hpp"

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define MAGENTA     "\033[95m"
#define CYAN        "\033[96m"
#define WHITE       "\033[97m"

void printSection(const char* title)
{
	std::cout << std::endl;
	std::cout << MAGENTA << BOLD << title << RESET << std::endl;
	std::cout << MAGENTA << "═════════════════════════════════════════" << RESET << std::endl;
}

void testBasicExample(void)
{
	printSection("TEST 1: Basic Example (from subject)");
	
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << GREEN << "✓ All numbers added successfully" << RESET << std::endl;
		std::cout << CYAN << "  Numbers: 5, 3, 17, 9, 11" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testEmptyContainer(void)
{
	printSection("TEST 4: Empty Container (Error Expected)");
	
	try
	{
		Span sp = Span(5);
		std::cout << YELLOW << "  Attempting shortestSpan() on empty container..." << RESET << std::endl;
		int result = sp.shortestSpan();
		std::cout << RED << "✗ Should have thrown an exception! Got: " << result << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << GREEN << "✓ Correctly threw exception: " << CYAN << e.what() << RESET << std::endl;
	}
}

void testSingleElement(void)
{
	printSection("TEST 5: Single Element (Error Expected)");
	
	try
	{
		Span sp = Span(5);
		sp.addNumber(42);
		std::cout << YELLOW << "  Attempting shortestSpan() with only one number..." << RESET << std::endl;
		int result = sp.shortestSpan();
		std::cout << RED << "✗ Should have thrown an exception! Got: " << result << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << GREEN << "✓ Correctly threw exception: " << CYAN << e.what() << RESET << std::endl;
	}
}

void testCapacityExceeded(void)
{
	printSection("TEST 6: Capacity Exceeded (Error Expected)");
	
	try
	{
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << YELLOW << "  Container is full. Attempting to add one more..." << RESET << std::endl;
		sp.addNumber(4);
		std::cout << RED << "✗ Should have thrown an exception!" << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << GREEN << "✓ Correctly threw exception: " << CYAN << e.what() << RESET << std::endl;
	}
}

void testTwoElements(void)
{
	printSection("TEST 7: Exactly Two Elements");
	
	try
	{
		Span sp = Span(2);
		sp.addNumber(10);
		sp.addNumber(20);
		
		std::cout << GREEN << "✓ All numbers added successfully" << RESET << std::endl;
		std::cout << CYAN << "  Numbers: 10, 20" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testLargeNumbers(void)
{
	printSection("TEST 8: Large Numbers (within safe range)");
	
	try
	{
		Span sp = Span(4);
		sp.addNumber(-1000000);
		sp.addNumber(-5000);
		sp.addNumber(500000);
		sp.addNumber(1000000);
		
		std::cout << GREEN << "✓ All numbers added successfully" << RESET << std::endl;
		std::cout << CYAN << "  Numbers: -1000000, -5000, 500000, 1000000" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testThousandNumbers(void)
{
	printSection("TEST 9: 1000 Random Numbers");
	
	try
	{
		Span sp = Span(1000);
		
		std::cout << YELLOW << "  Generating and adding 1000 random numbers..." << RESET << std::endl;
		for (unsigned int i = 0; i < 1000; ++i)
		{
			sp.addNumber(rand() % 10000);
		}
		
		std::cout << GREEN << "✓ All 1000 numbers added successfully" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testTenThousandNumbers(void)
{
	printSection("TEST 10: 10,000 Random Numbers (Major Test)");
	
	try
	{
		Span sp = Span(10000);
		
		std::cout << YELLOW << "  Generating and adding 10,000 random numbers..." << RESET << std::endl;
		for (unsigned int i = 0; i < 10000; ++i)
		{
			sp.addNumber(rand() % 100000);
		}
		
		std::cout << GREEN << "✓ All 10,000 numbers added successfully" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testRangeAddition(void)
{
	printSection("TEST 10: Range Addition with Iterators (if implemented)");
	
	std::vector<int> data;
	data.push_back(1);
	data.push_back(5);
	data.push_back(10);
	data.push_back(15);
	data.push_back(20);
	
	Span sp = Span(5);
	
	std::cout << YELLOW << "  Adding numbers individually (1, 5, 10, 15, 20)..." << RESET << std::endl;
	std::cout << CYAN << "  Source vector: 1, 5, 10, 15, 20" << RESET << std::endl;
	
	sp.addNumber(1);
	sp.addNumber(5);
	sp.addNumber(10);
	sp.addNumber(15);
	sp.addNumber(20);
	
	std::cout << GREEN << "✓ All numbers added successfully" << RESET << std::endl;
	std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
	std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
}

void testReversedNumbers(void)
{
	printSection("TEST 11: Reversed Sequential Numbers (100 to 1)");
	
	try
	{
		Span sp = Span(100);
		
		std::cout << YELLOW << "  Adding reversed sequential numbers from 100 to 1..." << RESET << std::endl;
		for (int i = 100; i >= 1; --i)
		{
			sp.addNumber(i);
		}
		
		std::cout << GREEN << "✓ All 100 numbers added successfully" << RESET << std::endl;
		std::cout << CYAN << "  Expected: shortest = 1, longest = 99 (order doesn't matter)" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testAllSameNumber(void)
{
	printSection("TEST 12: All Same Number");
	
	try
	{
		Span sp = Span(10);
		
		std::cout << YELLOW << "  Adding the same number (42) ten times..." << RESET << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			sp.addNumber(42);
		}
		
		std::cout << GREEN << "✓ All 10 numbers added successfully" << RESET << std::endl;
		std::cout << CYAN << "  Expected: both spans = 0 (no difference)" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testNegativeAndPositive(void)
{
	printSection("TEST 13: Mixed Negative and Positive (Random)");
	
	try
	{
		Span sp = Span(50);
		
		std::cout << YELLOW << "  Adding 50 random numbers (both negative and positive)..." << RESET << std::endl;
		for (int i = 0; i < 50; ++i)
		{
			sp.addNumber((rand() % 2000) - 1000);
		}
		
		std::cout << GREEN << "✓ All 50 numbers added successfully" << RESET << std::endl;
		std::cout << YELLOW << "  Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "  Longest Span:  " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

void testOverflowDetection(void)
{
	printSection("TEST 14: Overflow Detection in longestSpan()");
	
	try
	{
		Span sp = Span(2);
		sp.addNumber(-2147483647);
		sp.addNumber(2147483646);
		
		std::cout << YELLOW << "  Testing longestSpan() with extreme values..." << RESET << std::endl;
		std::cout << CYAN << "  Numbers: -2147483647, 2147483646" << RESET << std::endl;
		
		int result = sp.longestSpan();
		std::cout << RED << "✗ Should have thrown OverflowException! Got: " << result << RESET << std::endl;
	}
	catch (const Span::OverflowException& e)
	{
		std::cout << GREEN << "✓ Correctly detected overflow: " << CYAN << e.what() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
	}
}

void testShortestSpanOverflow(void)
{
	printSection("TEST 15: Overflow Detection in shortestSpan()");
	
	try
	{
		Span sp = Span(2);
		sp.addNumber(-2147483647);
		sp.addNumber(2147483646);
		
		std::cout << YELLOW << "  Testing shortestSpan() with potentially overflowing diff..." << RESET << std::endl;
		std::cout << CYAN << "  Numbers: -2147483647, 2147483646" << RESET << std::endl;
		
		int result = sp.shortestSpan();
		std::cout << GREEN << "✓ Result: " << result << RESET << std::endl;
	}
	catch (const Span::OverflowException& e)
	{
		std::cout << GREEN << "✓ Correctly detected overflow: " << CYAN << e.what() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "✗ Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	srand(time(0));
	
	std::cout << BOLD << GREEN << std::endl;
	std::cout << "SPAN CLASS - COMPREHENSIVE TEST SUITE" << std::endl;
	std::cout << "(Module 08 - Exercise 01)" << RESET << std::endl;
	
	testBasicExample();
	testEmptyContainer();
	testSingleElement();
	testCapacityExceeded();
	testTwoElements();
	testLargeNumbers();
	testThousandNumbers();
	testTenThousandNumbers();
	testRangeAddition();
	testReversedNumbers();
	testAllSameNumber();
	testNegativeAndPositive();
	testOverflowDetection();
	testShortestSpanOverflow();
	
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "ALL TESTS COMPLETED SUCCESSFULLY!" << RESET << std::endl;
	std::cout << std::endl;
	
	return (0);
}