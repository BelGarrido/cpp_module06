#ifndef BASE_HPP
#define BASE_HPP

#include <ostream>

class Base {
    public:
        Base();
        //virtual destructor
        virtual ~Base();
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif