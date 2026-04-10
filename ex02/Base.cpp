
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}
Base::~Base() {}

Base *generate(void) {
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

// `dynamic_cast` with a pointer:
// - Returns a valid pointer if the object is of that type.
// - Returns NULL if the object is not of that type.

// `dynamic_cast` with a reference:
// - Returns a valid reference if the object is of that type.
// - Throws an exception (`std::bad_cast`) if it is not.

void identify(Base* p) {
    // Pointer version: test each type with `dynamic_cast<...*>(p)`.
    // No exceptions are used here; failed casts simply return NULL.
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
    // Reference version: each failed cast throws, so we use nested try/catch
    // blocks to continue checking the next possible derived type.
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