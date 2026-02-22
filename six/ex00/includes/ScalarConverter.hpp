#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <stdexcept>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& rhs);
    ~ScalarConverter();

    enum e_type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

    static e_type       detectType(const std::string& literal);
    static bool         isPseudoLiteral(const std::string& literal);

    static void         validateForChar(double val);
    static void         validateForInt(double val);
    static void         validateForFloat(double val);

    static void         printChar(char c);
    static void         printInt(int i);
    static void         printFloat(float f);
    static void         printDouble(double d);

    template <typename T>
    static void         castAllAndPrint(T acquired);

    static std::string  formatDecimal(double val);
    static void         printPseudo(const std::string& literal);
    static void         printAllImpossible();
};
