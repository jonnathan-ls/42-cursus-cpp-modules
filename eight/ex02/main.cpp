#include <iostream>
#include <list>
#include <MutantStack.hpp>
#include <string>

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
	std::cout << MAGENTA << "-----------------------------------------" << RESET << std::endl;
}

template <typename Iter>
void printRange(Iter it, Iter end)
{
	while (it != end)
	{
		std::cout << CYAN << "  " << *it << RESET << std::endl;
		++it;
	}
}

void testSubjectExample(void)
{
	printSection("TEST 1: Subject Example");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << YELLOW << "  Top: " << GREEN << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << YELLOW << "  Size after pop: " << GREEN << mstack.size() << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << YELLOW << "  Iterating stack values:" << RESET << std::endl;
	printRange(it, ite);

	std::stack<int> s(mstack);
	std::cout << GREEN << "  std::stack copy size: " << s.size() << RESET << std::endl;
}

void testLifoBehavior(void)
{
	printSection("TEST 2: LIFO Behavior");

	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	std::cout << YELLOW << "  Expected top: 30" << RESET << std::endl;
	std::cout << GREEN << "  Top: " << mstack.top() << RESET << std::endl;

	mstack.pop();
	std::cout << YELLOW << "  Expected top after pop: 20" << RESET << std::endl;
	std::cout << GREEN << "  Top: " << mstack.top() << RESET << std::endl;
	std::cout << GREEN << "  Size: " << mstack.size() << RESET << std::endl;
}

void testForwardIteration(void)
{
	printSection("TEST 3: Forward Iteration Order");

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
	{
		mstack.push(i);
	}

	std::cout << YELLOW << "  Expected order: 1 2 3 4 5" << RESET << std::endl;
	printRange(mstack.begin(), mstack.end());
}

void testReverseIteration(void)
{
	printSection("TEST 4: Reverse Iteration Order");

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
	{
		mstack.push(i);
	}

	std::cout << YELLOW << "  Expected order: 5 4 3 2 1" << RESET << std::endl;
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	printRange(it, ite);
}

void testCopyAndAssignment(void)
{
	printSection("TEST 5: Copy and Assignment");

	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);

	MutantStack<int> copy(original);
	MutantStack<int> assigned;
	assigned = original;

	original.pop();
	std::cout << YELLOW << "  Original top after pop: " << GREEN << original.top() << RESET << std::endl;
	std::cout << YELLOW << "  Copy top should remain 3: " << GREEN << copy.top() << RESET << std::endl;
	std::cout << YELLOW << "  Assigned top should remain 3: " << GREEN << assigned.top() << RESET << std::endl;
}

void testConstIterators(void)
{
	printSection("TEST 6: Const Iterators");

	MutantStack<int> mstack;
	mstack.push(4);
	mstack.push(8);
	mstack.push(15);

	const MutantStack<int> constStack = mstack;
	MutantStack<int>::const_iterator it = constStack.begin();
	MutantStack<int>::const_iterator ite = constStack.end();

	std::cout << YELLOW << "  Const iteration:" << RESET << std::endl;
	printRange(it, ite);
}

void testEmptyIterators(void)
{
	printSection("TEST 7: Empty Stack Iterators");

	MutantStack<int> mstack;
	if (mstack.begin() == mstack.end())
	{
		std::cout << GREEN << "  OK: begin() == end() on empty stack" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "  FAIL: begin() != end() on empty stack" << RESET << std::endl;
	}
}

void testStdStackCompatibility(void)
{
	printSection("TEST 8: std::stack Compatibility");

	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(84);

	std::stack<int> s(mstack);
	std::cout << YELLOW << "  std::stack size: " << GREEN << s.size() << RESET << std::endl;
	std::cout << YELLOW << "  std::stack top:  " << GREEN << s.top() << RESET << std::endl;
}

void testStringType(void)
{
	printSection("TEST 9: std::string Type");

	MutantStack<std::string> mstack;
	mstack.push("one");
	mstack.push("two");
	mstack.push("three");

	std::cout << YELLOW << "  Iterating strings:" << RESET << std::endl;
	printRange(mstack.begin(), mstack.end());
}

void testDoubleType(void)
{
	printSection("TEST 10: double Type");

	MutantStack<double> mstack;
	mstack.push(1.5);
	mstack.push(2.25);
	mstack.push(3.75);

	std::cout << YELLOW << "  Forward iteration:" << RESET << std::endl;
	printRange(mstack.begin(), mstack.end());

	std::cout << YELLOW << "  Reverse iteration:" << RESET << std::endl;
	printRange(mstack.rbegin(), mstack.rend());
}

int main(void)
{
	std::cout << BOLD << GREEN << std::endl;
	std::cout << "MUTANTSTACK - COMPREHENSIVE TEST SUITE" << std::endl;
	std::cout << "(Module 08 - Exercise 02)" << RESET << std::endl;

	testSubjectExample();
	testLifoBehavior();
	testForwardIteration();
	testReverseIteration();
	testCopyAndAssignment();
	testConstIterators();
	testEmptyIterators();
	testStdStackCompatibility();
	testStringType();
	testDoubleType();

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "ALL TESTS COMPLETED." << RESET << std::endl;
	std::cout << std::endl;

	return (0);
}
