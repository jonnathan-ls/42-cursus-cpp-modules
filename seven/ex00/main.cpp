#include <iostream>
#include <string>
#include "whatever.hpp"

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define MAGENTA     "\033[95m"
#define CYAN        "\033[96m"

enum TestOperation { OP_SWAP, OP_MIN, OP_MAX };

struct Wrapper
{
    int value;

    Wrapper(int v = 0) : value(v) {}

    bool operator<(const Wrapper &other) const { return value < other.value; }
    bool operator>(const Wrapper &other) const { return value > other.value; }
};

std::ostream &operator<<(std::ostream &os, const Wrapper &box)
{
    os << "Wrapper[" << box.value << "]";
    return os;
}

template <typename T>
void runTest(T a, T b, TestOperation op, const char *typeLabel)
{
    std::cout << CYAN << "  Type: " << typeLabel 
        << " | a=" << a << ", b=" << b << RESET << std::endl;

    switch (op)
    {
        case OP_SWAP:
        {
            std::cout << "    " << YELLOW << "[SWAP]" 
                << RESET << " Before: (" << a << ", " << b << ") ";
            ::swap(a, b);
            std::cout << "-> After: (" << a << ", " << b << ")" << std::endl;
            break;
        }
        case OP_MIN:
        {
            T result = ::min(a, b);
            std::cout << "    " << GREEN << "[MIN]" 
                << RESET << " = " << GREEN << result << RESET << std::endl;
            break;
        }
        case OP_MAX:
        {
            T result = ::max(a, b);
            std::cout << "    " << RED << "[MAX]" 
                << RESET << " = " << RED << result << RESET << std::endl;
            break;
        }
    }
}

void runTestSuite(TestOperation op, const char *operationLabel)
{
    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "==== TEST: " 
        << operationLabel << " ====" << RESET << std::endl;

    // Test with integers
    std::cout << BLUE << "Testing with int:" << RESET << std::endl;
    runTest<int>(42, 7, op, "int");
    runTest<int>(100, 100, op, "int (equal values)");
    runTest<int>(-5, 5, op, "int (negative vs positive)");
    runTest<int>(0, -1, op, "int (zero vs negative)");
    runTest<int>(2147483647, -2147483648, op, "int (max vs min)");
    runTest<int>(-2147483648, 2147483647, op, "int (min vs max)");
    runTest<int>(-100, -50, op, "int (both negative)");
    
    std::cout << std::endl;

    // Test with floats
    std::cout << BLUE << "Testing with float:" << RESET << std::endl;
    runTest<float>(3.14f, 2.71f, op, "float");
    runTest<float>(5.5f, 5.5f, op, "float (equal values)");
    runTest<float>(-1.0f, 1.0f, op, "float (negative vs positive)");
    runTest<float>(0.0f, -0.0f, op, "float (zero vs negative zero)");
    runTest<float>(1e-10f, 1e-9f, op, "float (very small values)");
    runTest<float>(1e10f, 1e9f, op, "float (very large values)");
    runTest<float>(1.000111f, 1.000121f, op, "float (close values)");


    // Test with doubles
    std::cout << BLUE << "Testing with double:" << RESET << std::endl;
    runTest<double>(3.1415926535, 2.7182818284, op, "double");
    runTest<double>(5.5, 5.5, op, "double (equal values)");
    runTest<double>(-1.0, 1.0, op, "double (negative vs positive)");
    runTest<double>(0.0, -0.0, op, "double (zero vs negative zero)");
    runTest<double>(1e-100, 1e-99, op, "double (very small values)");
    runTest<double>(1e100, 1e99, op, "double (very large values)");
    runTest<double>(1.0000000000001, 1.0000000000002, op, "double (close values)");

    // Test with characters
    std::cout << BLUE << "Testing with char:" << RESET << std::endl;
    runTest<char>('a', 'b', op, "char");
    runTest<char>('z', 'z', op, "char (equal values)");
    runTest<char>('A', 'a', op, "char (case sensitivity)");
    runTest<char>('0', '9', op, "char (digit characters)");

    std::cout << std::endl;

    // Test with strings
    std::cout << BLUE << "Testing with std::string:" << RESET << std::endl;
    runTest<std::string>("apple", "banana", op, "string");
    runTest<std::string>("zebra", "zebra", op, "string (equal values)");
    runTest<std::string>("grape", "grapefruit", op, "string (prefix order)");
    runTest<std::string>("cherry", "Cherry", op, "string (case sensitivity)");
    runTest<std::string>("", "empty", op, "string (empty string case)");
    runTest<std::string>("", "", op, "string (both empty)");

    std::cout << std::endl;

    // Test with custom type
    std::cout << BLUE << "Testing with Wrapper (custom struct):" << RESET << std::endl;
    runTest<Wrapper>(Wrapper(99), Wrapper(99), op, "Wrapper (equal values)");
    runTest<Wrapper>(Wrapper(10), Wrapper(30), op, "Wrapper (reverse order)");
    runTest<Wrapper>(Wrapper(30), Wrapper(10), op, "Wrapper (normal order)");
}

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
    std::cout << BOLD << GREEN << "  Template Functions Test Suite" << RESET << std::endl;
    std::cout << BOLD << GREEN << "  Testing: swap(), min(), max()" << RESET << std::endl;
    std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;

    runTestSuite(OP_SWAP, "SWAP");
    runTestSuite(OP_MIN, "MIN");
    runTestSuite(OP_MAX, "MAX");

    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "==== NOTES: Type Requirements ====" << RESET << std::endl;
    std::cout << "✓ Supported: types with operator< and operator>" << std::endl;
    std::cout << "✓ Examples: int, float, double, char, std::string, custom structs" << std::endl;
    std::cout << RED << "✗ NOT Supported: arrays, pointers (no comparison operators)" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << BOLD << GREEN << "All tests completed!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}