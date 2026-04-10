#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <iomanip>
#include <errno.h>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>


class ScalarConverter {
    private:
    
        // DEFAULT_CONSTRUCTOR
        ScalarConverter();
        // PARAMETIZED_CONSTRUCTOR
        ScalarConverter(std::string const &name, int grade);

        // COPY
        ScalarConverter(const ScalarConverter &original);
        ScalarConverter &operator=(const ScalarConverter &original);

        // DESTRUCTOR
        ~ScalarConverter();

    public:

        static void convert(std::string s);

} ;

std::ostream& operator<<(std::ostream& output, const ScalarConverter& bureau);

#endif