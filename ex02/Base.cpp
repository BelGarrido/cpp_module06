#include "Base.hpp"
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>


Base::Base() {

}
Base::~Base() {

}

Base * generate(void) {
    Base *ptr = NULL;
    int random = std::rand() % 3;
    if(random == 0) {
        ptr = new A;
    }
    else if(random == 1) {
        ptr = new B;
    }
    else
        ptr = new C;
    return ptr;
}


// dynamic_cast<A*>(p) → succeeds if p is really an A
//                     → returns nullptr if it's not

void identify(Base* p) {

    if (dynamic_cast<A*>(p))
        std::cout << "It's type A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
        std::cout << "It's type B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "It's type C" << std::endl;
    else
        std::cout << "Wrong type" << std::endl;
}

void identify(Base& p) {
    try {
        A& ref = dynamic_cast<A&>(p);
        std::cout << "It's type A" << std::endl;
        (void)ref;
    }
    catch (const std::exception &e) {
        try {
            B& ref = dynamic_cast<B&>(p);
            std::cout << "It's type B" << std::endl;
            (void)ref;
        }
        catch (const std::exception &e) {
            try {
                C& ref = dynamic_cast<C&>(p);
                std::cout << "It's type C" << std::endl;
                (void)ref;
            }
            catch (const std::exception &e) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}