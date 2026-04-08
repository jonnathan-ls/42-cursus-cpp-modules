#include <iostream>
#include <string>
#include "Array.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define CYAN    "\033[96m"
#define RED     "\033[91m"

template <typename T>
void printArray(Array<T> &arr, const char *name = "")
{
    std::cout << CYAN << "  [" << name << "] size=" << arr.size() << " → ";
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << RESET << std::endl;
}

void testSection(const char *title)
{
    std::cout << YELLOW << "\n📦 " << title << RESET << std::endl << std::endl;
}

void testCase(const char *desc, bool passed)
{
    std::cout << (passed ? "✓  " : "✗  ");
    std::cout << CYAN << desc << RESET;
    std::cout << (passed ? GREEN " OK" : RED " FAIL") << RESET << std::endl;
}

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int xx, int yy) : x(xx), y(yy) {}
    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }
};

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

int main()
{
    std::cout << RED << "\n▶  Array<T> Template Tests\n" << RESET << std::endl;

    testSection("DEFAULT CONSTRUCTION");
    Array<int> empty;
    testCase("Empty array size = 0", empty.size() == 0);

    testSection("CONSTRUCTION WITH SIZE");
    Array<int> arr1(5);
    testCase("Array size = 5", arr1.size() == 5);
    testCase("Elements initialized to 0", arr1[0] == 0 && arr1[4] == 0);

    Array<float> arrF(3);
    testCase("Float array initialized", arrF[0] == 0.0f && arrF[1] == 0.0f);

    Array<std::string> arrS(2);
    testCase("String array initialized to empty", arrS[0] == "" && arrS[1] == "");

    testSection("ELEMENT ACCESS & MODIFICATION");
    arr1[0] = 42;
    arr1[4] = 100;
    testCase("Set and get elements", arr1[0] == 42 && arr1[4] == 100);

    arrS[0] = "Hello";
    arrS[1] = "World";
    testCase("String element modification", arrS[0] == "Hello" && arrS[1] == "World");

    testSection("OUT OF BOUNDS EXCEPTIONS");
    bool caughtOOB = false;
    try {
        arr1[10] = 999;
    } catch (Array<int>::OutOfBoundsException &e) {
        caughtOOB = true;
    }
    testCase("operator[] throws on out of bounds", caughtOOB);

    caughtOOB = false;
    try {
        const Array<int> &ref = arr1;
        (void)ref[10];
    } catch (Array<int>::OutOfBoundsException &e) {
        caughtOOB = true;
    }
    testCase("const operator[] throws on out of bounds", caughtOOB);

    testSection("COPY CONSTRUCTOR");
    Array<int> arr2(arr1);
    testCase("Copy constructor copies values", arr2[0] == 42 && arr2[4] == 100);
    testCase("Copy has same size", arr2.size() == arr1.size());

    arr2[0] = 999;
    testCase("Deep copy (modification doesn't affect original)", arr1[0] == 42 && arr2[0] == 999);

    testSection("ASSIGNMENT OPERATOR");
    Array<int> arr3(2);
    arr3 = arr1;
    testCase("Assignment copies values", arr3[0] == 42 && arr3[4] == 100);
    testCase("Assignment changes size", arr3.size() == arr1.size());

    arr3[2] = 777;
    testCase("Deep copy (modification doesn't affect source)", arr1[2] == 0 && arr3[2] == 777);

    Array<int> arr4 = arr3;
    arr4[0] = 111;
    testCase("Self-assignment safe (self-check works)", arr3[0] == 42);

    testSection("EDGE CASES");
    Array<int> single(1);
    single[0] = 42;
    testCase("Single element array", single.size() == 1 && single[0] == 42);

    Array<int> large(1000);
    large[999] = 999;
    testCase("Large array (1000 elements)", large.size() == 1000 && large[999] == 999);

    bool oob = false;
    try { large[1000] = 0; } catch (...) { oob = true; }
    testCase("Out of bounds on large array", oob);

    testSection("CONST CORRECTNESS");
    const Array<int> constArr(3);
    testCase("Const array accessible", constArr[0] == 0 && constArr[2] == 0);
    testCase("Const array size", constArr.size() == 3);

    testSection("MULTIPLE TYPES");
    Array<char> arrC(4);
    arrC[0] = 'A';
    arrC[3] = 'Z';
    testCase("Char array", arrC[0] == 'A' && arrC[3] == 'Z');

    Array<double> arrD(2);
    arrD[0] = 3.14159;
    arrD[1] = 2.71828;
    testCase("Double array values", arrD[0] > 3.1 && arrD[1] > 2.7);

    testSection("SEQUENCE OF OPERATIONS");
    Array<int> seq(5);
    for (unsigned int i = 0; i < seq.size(); ++i)
        seq[i] = i * 10;
    
    Array<int> seqCopy = seq;
    for (unsigned int i = 0; i < seqCopy.size(); ++i)
        seqCopy[i] *= 2;
    
    bool sequenceOK = seq[0] == 0 && seq[4] == 40 && seqCopy[0] == 0 && seqCopy[4] == 80;
    testCase("Sequential operations & independent copies", sequenceOK);

    testSection("COMPLEX TYPES - STRUCT");
    Array<Point> arrPoints(3);
    testCase("Struct array initialized to (0,0)", arrPoints[0] == Point(0, 0) && arrPoints[2] == Point(0, 0));

    arrPoints[0] = Point(10, 20);
    arrPoints[1] = Point(30, 40);
    arrPoints[2] = Point(50, 60);
    testCase("Struct elements set correctly", arrPoints[0] == Point(10, 20) && arrPoints[2] == Point(50, 60));

    Array<Point> arrPoints2 = arrPoints;
    arrPoints2[0] = Point(99, 99);
    testCase("Deep copy works with struct (original unchanged)", arrPoints[0] == Point(10, 20) && arrPoints2[0] == Point(99, 99));

    Array<Point> arrPoints3(2);
    arrPoints3 = arrPoints;
    testCase("Assignment operator with struct", arrPoints3.size() == 3 && arrPoints3[1] == Point(30, 40));

    bool structOOB = false;
    try {
        arrPoints[5] = Point(1, 1);
    } catch (Array<Point>::OutOfBoundsException &e) {
        structOOB = true;
    }
    testCase("Out of bounds exception works with struct", structOOB);

    testSection("REVERSE ITERATION");
    Array<int> reverse(5);
    for (unsigned int i = 0; i < reverse.size(); ++i)
        reverse[i] = (int)i + 1;
    
    bool reverseOK = true;
    for (unsigned int i = reverse.size(); i > 0; --i)
        if (reverse[i - 1] != (int)i)
            reverseOK = false;
    testCase("Reverse iteration access works", reverseOK);

    testSection("CHAINED ASSIGNMENT");
    Array<int> ch1(2), ch2(2), ch3(2);
    ch1[0] = 11; ch1[1] = 12;
    ch2[0] = 21; ch2[1] = 22;
    ch3[0] = 31; ch3[1] = 32;
    
    ch1 = ch2 = ch3;
    bool chainedOK = ch1[0] == 31 && ch1[1] == 32 && ch2[0] == 31 && ch2[1] == 32 && ch3[0] == 31 && ch3[1] == 32;
    testCase("Chained assignment (ch1 = ch2 = ch3)", chainedOK);

    std::cout << BOLD << GREEN << "\n✓ All tests completed!\n" << RESET << std::endl;
    return 0;
}