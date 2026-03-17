#include "ScalarConverter.hpp"

//______________________ DEFAULT_CONSTRUCTOR__

ScalarConverter::ScalarConverter() {
}

//_________________________________DESTRUCTOR__

ScalarConverter::~ScalarConverter() {
}

//_______________________________________COPY__

ScalarConverter::ScalarConverter(const ScalarConverter &original) {
    (void)original;
}

// Name is const, so only grade can be reassigned
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &original) {
    (void)original;
    return *this;
}


bool isChar(std::string s) {
    if(s.length() != 1)
        return false;
    if(!std::isdigit(s[0]))
        return true;
    return false;
}

bool isInt(std::string s) {
    if(s.empty())
        return false;
    
    size_t i = 0;

    if(s[i] == '+' || s[i] == '-') {
        if(s.length() == 1)
            return false;
        i++;
    }
        
    for(; i < s.length(); i++) {
        if(!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool isFloat(std::string s) {

}

bool isDouble(std::string s) {

}


void ScalarConverter::convert(std::string s) {
    double item;

    // 1. DETECCIÓN Y RELLENADO
    if (isChar(s)) {
        item = static_cast<double>(s[0]);
    }
    else if (isInt(s)) {
        item = std::atof(s.c_str()); // O usar strtod
    }
    else if (isFloat(s)) {
        // Cuidado: hay que quitar la 'f' del final antes de convertir
        item = std::atof(s.c_str());
    }
    else if (isDouble(s)) {
        item = std::atof(s.c_str());
    }
    else {
        //pseudo-literales como nan, +inf, etc.
        // O dejas que atof los maneje si son estándar.
    }

    // 2. IMPRESIÓN CONTROLADA
    printChar(item);
    printInt(item);
    printFloat(item);
    printDouble(item);
}
