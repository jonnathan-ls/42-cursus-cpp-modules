#include "ABC.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
    int random = std::rand() % 3;
    switch (random) {
        case 0:  return new A();
        case 1:  return new B();
        default: return new C();
    }
}

void identify(Base* p) {
    if (!p) {
        std::cout << "NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

template <typename T>
static bool tryIdentify(Base& p, const std::string& name) {
    try {
        (void)dynamic_cast<T&>(p);
        std::cout << name << std::endl;
        return true;
    } catch (std::exception&) {
        return false;
    }
}

void identify(Base& p) {
    if (!tryIdentify<A>(p, "A") && !tryIdentify<B>(p, "B") && !tryIdentify<C>(p, "C"))
        std::cout << "Unknown" << std::endl;
}
