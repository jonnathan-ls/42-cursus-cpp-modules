#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define MAGENTA     "\033[95m"
#define CYAN        "\033[96m"

template <typename T>
void printContainer(const T& container, const char* name)
{
	std::cout << CYAN << name << ": [ ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << RESET << std::endl;
}

template <typename T>
void testFind(T& container, int value, const char* containerType)
{
	std::cout << BLUE << "  Looking for " << YELLOW << value << BLUE << " in " << containerType << RESET << std::endl;
	
	try
	{
		typename T::iterator result = easyfind(container, value);
		int position = 0;
		for (typename T::iterator it = container.begin(); it != result; ++it)
			++position;
		std::cout << GREEN << "    ✓ Found! Value at position: " << position << RESET << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << RED << "    ✗ Not found: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "  easyfind() Template Function Test Suite" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;

	// Test with vector
	std::cout << std::endl;
	std::cout << MAGENTA << BOLD << "[TEST 1: std::vector<int>]" << RESET << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		
		printContainer(vec, "Vector");
		
		testFind(vec, 30, "vector");
		testFind(vec, 50, "vector (last element)");
		testFind(vec, 10, "vector (first element)");
		testFind(vec, 99, "vector");
		testFind(vec, 0, "vector");
	}

	// Test with list
	std::cout << std::endl;
	std::cout << MAGENTA << BOLD << "[TEST 2: std::list<int>]" << RESET << std::endl;
	{
		std::list<int> myList;
		myList.push_back(5);
		myList.push_back(15);
		myList.push_back(25);
		myList.push_back(35);
		
		printContainer(myList, "List");
		
		testFind(myList, 25, "list");
		testFind(myList, 5, "list (first element)");
		testFind(myList, 35, "list (last element)");
		testFind(myList, 100, "list");
	}

	// Test with deque
	std::cout << std::endl;
	std::cout << MAGENTA << BOLD << "[TEST 3: std::deque<int>]" << RESET << std::endl;
	{
		std::deque<int> dq;
		dq.push_back(100);
		dq.push_back(200);
		dq.push_back(300);
		dq.push_back(400);
		dq.push_back(500);
		dq.push_back(600);
		
		printContainer(dq, "Deque");
		
		testFind(dq, 300, "deque");
		testFind(dq, 100, "deque");
		testFind(dq, 600, "deque (last element)");
		testFind(dq, 250, "deque");
		testFind(dq, 1000, "deque");
	}

	// Test with array (raw array wrapped in container-like behavior)
	std::cout << std::endl;
	std::cout << MAGENTA << BOLD << "[TEST 4: Edge Cases]" << RESET << std::endl;
	{
		std::vector<int> empty;
		std::cout << BLUE << "  Testing with empty vector:" << RESET << std::endl;
		testFind(empty, 42, "empty vector");
		
		std::vector<int> single;
		single.push_back(42);
		std::cout << BLUE << "  Testing with single-element vector:" << RESET << std::endl;
		printContainer(single, "Single");
		testFind(single, 42, "single (matching element)");
		testFind(single, 43, "single (non-matching element)");
		
		std::vector<int> duplicates;
		duplicates.push_back(7);
		duplicates.push_back(7);
		duplicates.push_back(7);
		duplicates.push_back(7);
		std::cout << BLUE << "  Testing with duplicate values (should find first):" << RESET << std::endl;
		printContainer(duplicates, "Duplicates");
		testFind(duplicates, 7, "duplicates");
	}

	std::cout << std::endl;
	std::cout << BOLD << MAGENTA << "==== NOTES: Container Requirements ====" << RESET << std::endl;
	std::cout << "✓ Supported: Any container with begin() and end() iterators" << std::endl;
	std::cout << "✓ Examples: std::vector, std::list, std::deque, std::array" << std::endl;
	std::cout << "✓ Elements: Must be comparable (operator==)" << std::endl;
	std::cout << RED << "✗ Returns: Iterator to first occurrence or throws NotFoundException" << RESET << std::endl;

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "All tests completed!" << RESET << std::endl;
	std::cout << std::endl;

	return 0;
}