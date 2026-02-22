#include "ABC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#define RST  "\033[0m"
#define GRN  "\033[32m"
#define CYN  "\033[36m"
#define YEL  "\033[33m"

int main(void) {
    std::srand(std::time(NULL));

    std::cout << std::endl;
    std::cout << GRN << "🎲 dynamic_cast identification" << RST << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        Base* instance = generate();

        std::cout << CYN << "Instance " << (i + 1) << RST << std::endl;
        std::cout << "  ptr → " << YEL;
        identify(instance);
        std::cout << RST << "  ref → " << YEL;
        identify(*instance);
        std::cout << RST << std::endl;

        delete instance;
    }

    std::cout << CYN << "NULL test" << RST << std::endl;
    std::cout << "  ptr → " << YEL;
    identify(static_cast<Base*>(NULL));
    std::cout << RST << std::endl;

    return 0;
}
