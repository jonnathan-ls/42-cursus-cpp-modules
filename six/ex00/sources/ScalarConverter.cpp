#include "ScalarConverter.hpp"


/* ========================================================================= */
/*                             VALIDADORES                                   */
/* ========================================================================= */

bool is_nan(double val) {
    return val != val;
}

bool is_inf(double val) {
    return val == std::numeric_limits<double>::infinity() || val == -std::numeric_limits<double>::infinity();
}

void ScalarConverter::validateForChar(double val) {
    if (is_nan(val) || is_inf(val)) throw std::runtime_error("impossible");
    if (val < 0 || val > 127) throw std::runtime_error("impossible");
    if (val < 32 || val == 127) throw std::runtime_error("Non displayable");
}

void ScalarConverter::validateForInt(double val) {
    if (is_nan(val) || is_inf(val)) throw std::runtime_error("impossible");
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        throw std::runtime_error("impossible");
}

void ScalarConverter::validateForFloat(double val) {
    if (is_nan(val) || is_inf(val)) return;
    if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
        throw std::runtime_error("impossible");
}

/* ========================================================================= */
/*                              DETECÇÃO                                     */
/* ========================================================================= */

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal) {
    if (literal.empty()) return INVALID;
    if (isPseudoLiteral(literal)) return PSEUDO;
    if (literal.length() == 1 && !std::isdigit(literal[0])) return CHAR;

    char* endptr = NULL;
    errno = 0;
    double val = std::strtod(literal.c_str(), &endptr);

    if (is_nan(val) || is_inf(val)) return INVALID;

    if (*endptr == '\0') {
        if (literal.find('.') != std::string::npos)
            return DOUBLE;
        errno = 0;
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
            return DOUBLE;
        return INT;
    }
    if ((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0')
        return FLOAT;
    return INVALID;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf"
         || literal == "+inf" || literal == "+inff"
         || literal == "-inf" || literal == "-inff"
         || literal == "inf" || literal == "inff");
}


/* ========================================================================= */
/*                              PRINTERS                                     */
/* ========================================================================= */

void ScalarConverter::printChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << formatDecimal(f) << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << formatDecimal(d) << std::endl;
}

std::string ScalarConverter::formatDecimal(double val) {
    std::ostringstream oss;
    oss << val;
    std::string s = oss.str();
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
        s += ".0";
    return s;
}

void ScalarConverter::printPseudo(const std::string& literal) {
    std::string f_val, d_val;
    if (literal == "nan" || literal == "nanf") {
        f_val = "nanf";
        d_val = "nan";
    }
    else if (literal == "+inf" || literal == "inf" 
        || literal == "+inff" || literal == "inff") {
        f_val = "+inff";
        d_val = "+inf";
    }
    else if (literal == "-inf" || literal == "-inff") {
        f_val = "-inff";
        d_val = "-inf";
    }
    std::cout << "char: impossible" << std::endl
              << "int: impossible" << std::endl
              << "float: " << f_val << std::endl
              << "double: " << d_val << std::endl;
}

void ScalarConverter::printAllImpossible() {
    std::cout << "char: impossible" << std::endl
              << "int: impossible" << std::endl
              << "float: impossible" << std::endl
              << "double: impossible" << std::endl;
}

/* ========================================================================= */
/*        TEMPLATE: Casta do tipo nativo T para os 4 tipos escalares         */
/* ========================================================================= */

template <typename T>
void ScalarConverter::castAllAndPrint(T acquired) {
    try {
        validateForChar(acquired);
        printChar(static_cast<char>(acquired));
    } catch (std::exception& e) {
        std::cout << "char: " << e.what() << std::endl;
    }
    try {
        validateForInt(acquired);
        printInt(static_cast<int>(acquired));
    } catch (std::exception& e) {
        std::cout << "int: " << e.what() << std::endl;
    }
    try {
        validateForFloat(acquired);
        printFloat(static_cast<float>(acquired));
    } catch (std::exception& e) {
        std::cout << "float: " << e.what() << std::endl;
    }
    printDouble(static_cast<double>(acquired));
}

/* ========================================================================= */
/*                    MOTOR PRINCIPAL (convert = orquestrador)                */
/* ========================================================================= */

void ScalarConverter::convert(const std::string& literal) {
    e_type type = detectType(literal);

    if (type == INVALID) { printAllImpossible(); return; }
    if (type == PSEUDO)  { printPseudo(literal); return; }

    errno = 0;
    switch (type) {
        case CHAR:
            castAllAndPrint(literal[0]);
            break;
        case INT: {
            long raw = std::strtol(literal.c_str(), NULL, 10);
            if (errno == ERANGE) { printAllImpossible(); return; }
            castAllAndPrint(static_cast<int>(raw));
            break;
        }
        case FLOAT: {
            double raw = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE) { printAllImpossible(); return; }
            castAllAndPrint(static_cast<float>(raw));
            break;
        }
        case DOUBLE: {
            double raw = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE) { printAllImpossible(); return; }
            castAllAndPrint(raw);
            break;
        }
        default: break;
    }
}
