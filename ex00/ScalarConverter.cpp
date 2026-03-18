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
    if(s.empty())
        return false;
    if(s.length() != 1)
        return false;
    if((s[0]) > 0 && (s[0]) < 127)
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
    if (s.length() < 2 || s[s.length() - 1] != 'f') return false;

    int dotCount = 0;

    if(s[0] == '.') {
        for(size_t i = 1; i < s.length() - 1; i++) {
            if(!std::isdigit(s[i]))
                return false;
        }
        return true;
    }

    size_t i = 0;
    if(s[i] == '+' || s[i] == '-') i++;

    for(; i < s.length() - 1; i++) {
        if (s[i]  == '.') {
            dotCount++;
            if(dotCount > 1) return false;
        }
        else if(!std::isdigit(s[i])) return false;
    }
    if(dotCount == 0) return false;
    return true;
}

bool isDouble(std::string s) {
    int dotCount = 0;

    if(s[0] == '.') {
        for(size_t i = 1; i < s.length(); i++) {
            if(!std::isdigit(s[i]))
                return false;
        }
        return true;
    }

    size_t i = 0;
    if(s[i] == '+' || s[i] == '-') i++;

    for(; i < s.length(); i++) {
        if (s[i]  == '.') {
            dotCount++;
            if(dotCount > 1) return false;
        }
        else if(!std::isdigit(s[i])) return false;
    }
    if(dotCount == 0) return false;
    return true;
}

bool isPseudo(std::string s) {
    if (s == "-inf" || s == "+inf" || s == "nan" || s == "inff" || s == "-inff" || s == "+inff" || s == "nanf" || s == "inff") return true;
    return false;
}

void ScalarConverter::convert(std::string s) {
    double item;

    // 1. DETECCIÓN Y RELLENADO
    if (isChar(s)) {
        item = static_cast<double>(s[0]);
    } else if (isInt(s) || isFloat(s) || isDouble(s) || isPseudo(s)) {
    
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



/* ./convert 42.0f

char: '*'
int: 42
float: 42.0f
double: 42.0 */

/* ./convert 4.242


char: Non displayable
int: 4
float: 4.2f
double: 4.242 */

/* ./convert nan

char: impossible
int: impossible
float: nanf
double: nan */


/* ./convert 'a'

char: 'a'
int: 97
float: 97.0f
double: 97.0 */