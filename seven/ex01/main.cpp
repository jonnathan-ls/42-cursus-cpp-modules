#include <iostream>
#include <string>
#include "iter.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define CYAN    "\033[96m"

void printInt(int x) { std::cout << x << " "; }
void printFloat(float x) { std::cout << x << " "; }
void printString(std::string str) { std::cout << "[" << str << "] "; }
void printChar(char c) { std::cout << "'" << c << "' "; }
void doubleInt(int &x) { x = x * 2; }
void toUpperChar(char &c) { if (c >= 'a' && c <= 'z') c = c - 32; }
void incrementFloat(float &x) { x = x + 0.5f; }

struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {}
    void operator()(int &x) const { x = x * factor; }
};

struct Squarer {
    void operator()(int &x) const { x = x * x; }
};

struct StringPrefixer {
    std::string prefix;
    StringPrefixer(const std::string &p) : prefix(p) {}
    void operator()(std::string &s) const { s = prefix + s; }
};

template <typename T, typename Func>
void test(const char *name, const char *desc, T *arr, int len, Func func)
{
    std::cout << CYAN << "• " << name << " (" << desc << ", size=" << len << ")" << RESET << " → ";
    iter(arr, len, func);
    std::cout << std::endl;
}

int main()
{
    std::cout << BOLD << GREEN << "\n▶ iter() Template Tests\n" << RESET << std::endl;

    std::cout << GREEN << "📦 INT Arrays & Modifications:" << RESET << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    test("print", "normal", arr1, 5, printInt);
    
    int arr2[] = {10};
    test("print", "single element", arr2, 1, printInt);
    
    int arr3[] = {1, 2, 3, 4, 5};
    iter(arr3, 5, doubleInt);
    test("doubled", "after 2x", arr3, 5, printInt);

    std::cout << GREEN << "\n📦 DUPLICATE Values Modification:" << RESET << std::endl;
    int arr_dup[] = {5, 5, 5, 5};
    std::cout << CYAN << "• before duplicate square: ";
    iter(arr_dup, 4, printInt);
    std::cout << RESET << std::endl;
    Squarer squarer;
    iter(arr_dup, 4, squarer);
    std::cout << YELLOW << "• after squaring duplicates: ";
    iter(arr_dup, 4, printInt);
    std::cout << RESET << std::endl;

    std::cout << GREEN << "\n📦 FLOAT Arrays:" << RESET << std::endl;
    float flt1[] = {1.5f, 2.5f, 3.5f};
    test("print", "normal", flt1, 3, printFloat);
    
    float flt2[] = {1.0f, 2.0f, 3.0f};
    iter(flt2, 3, incrementFloat);
    test("increment +0.5", "after modify", flt2, 3, printFloat);

    std::cout << GREEN << "\n📦 STRING Arrays & String Functor:" << RESET << std::endl;
    std::string str1[] = {"Hello", "World", "C++"};
    test("print", "normal", str1, 3, printString);
    
    StringPrefixer add_prefix(">>> ");
    std::string str2[] = {"apple", "banana", "cherry"};
    std::cout << CYAN << "• before prefix: ";
    iter(str2, 3, printString);
    std::cout << RESET << std::endl;
    iter(str2, 3, add_prefix);
    std::cout << YELLOW << "• after prefix: ";
    iter(str2, 3, printString);
    std::cout << RESET << std::endl;

    std::cout << GREEN << "\n📦 CHAR Arrays:" << RESET << std::endl;
    char chr1[] = {'a', 'b', 'c', 'd'};
    test("print", "lowercase", chr1, 4, printChar);
    
    char chr2[] = {'h', 'i', 't', 'h', 'e', 'r', 'e'};
    iter(chr2, 7, toUpperChar);
    test("uppercase", "after modify", chr2, 7, printChar);

    std::cout << GREEN << "\n📦 Multiple Functors (Different Behavior):" << RESET << std::endl;
    int multi1[] = {2, 3, 4, 5};
    std::cout << CYAN << "• multiply by 3 (before): ";
    iter(multi1, 4, printInt);
    std::cout << RESET << std::endl;
    Multiplier mult3(3);
    iter(multi1, 4, mult3);
    std::cout << YELLOW << "• multiply by 3 (after):  ";
    iter(multi1, 4, printInt);
    std::cout << RESET << std::endl;

    int multi2[] = {1, 2, 3, 4};
    std::cout << CYAN << "• multiply by 5 (before): ";
    iter(multi2, 4, printInt);
    std::cout << RESET << std::endl;
    Multiplier mult5(5);
    iter(multi2, 4, mult5);
    std::cout << YELLOW << "• multiply by 5 (after):  ";
    iter(multi2, 4, printInt);
    std::cout << RESET << std::endl;

    std::cout << GREEN << "\n📦 Edge Cases & Limits:" << RESET << std::endl;
    int limits[] = {-2147483647, -1, 0, 1, 2147483647};
    test("INT limits", "min to max", limits, 5, printInt);
    
    float extreme[] = {1e-10f, 1e10f};
    test("floats", "very small & large", extreme, 2, printFloat);
    
    char special[] = {'\0', 'A', 'z', '0', 127};
    test("special chars", "null, letters, digits, DEL", special, 5, printChar);

    std::cout << GREEN << "\n📦 Performance (1000 elements):" << RESET << std::endl;
    int big[1000];
    for (int i = 0; i < 1000; ++i) big[i] = i;
    std::cout << CYAN << "• first 10: ";
    for (int i = 0; i < 10; ++i) std::cout << big[i] << " ";
    std::cout << "..." << RESET << std::endl;
    
    std::cout << CYAN << "• processing 1000 elements with doubleInt..." << RESET << std::endl;
    iter(big, 1000, doubleInt);
    std::cout << CYAN << "• first 10 (after 2x): ";
    for (int i = 0; i < 10; ++i) std::cout << big[i] << " ";
    std::cout << "..." << RESET << std::endl;

    std::cout << BOLD << GREEN << "\n✓ All tests completed!\n" << RESET << std::endl;
    return 0;
}


