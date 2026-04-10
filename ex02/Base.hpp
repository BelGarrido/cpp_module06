#ifndef BASE_HPP
#define BASE_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
    public:
        Base();
        //virtual destructor
        virtual ~Base();
};


Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif