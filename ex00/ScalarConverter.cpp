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

// PRINT FUNCTIONS

void printAllImpossible() {
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

bool isDisplayable(double c) {
    if(c >= 32 && c <= 126)
        return true;
    return false;
}

void printFromChar(char c){
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printFromInt(long n, bool valid) {
    if (!valid || n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
        printAllImpossible();
        return;
    }
    int x = static_cast<int>(n);
    if(isDisplayable(x)) {
        char c = static_cast<char>(x);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else {
        if(x >= 0 && x <= 127)
            std::cout << "char: non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << x << std::endl;
    std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
    return;
}

void printFromFloat(double n, bool valid) {
    if (!valid) {
        printAllImpossible();
        return;
    }
    float x = static_cast<float>(n);
    if(isDisplayable(x)) {
        char c = static_cast<char>(x);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else {
        if(!isDisplayable(n))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }
    if (n > std::numeric_limits<int>::min() && n < std::numeric_limits<int>::max()) {
        int i = static_cast<int>(x);
        std::cout << "int: " << i << std::endl;
    }
    else
        std::cout << "int: impossible" << std::endl;
    //std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
    std::cout << "double: " << x << "" << std::endl;
    return;
}

void printFromDouble(double n, bool valid) {
    if (!valid) {
        printAllImpossible();
        return;
    }
    if(isDisplayable(n)) {
        char c = static_cast<char>(n);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else {
        if(n < 0 || n > 127)
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }
    if (n > std::numeric_limits<int>::min() && n < std::numeric_limits<int>::max()) {
        int i = static_cast<int>(n);
        std::cout << "int: " << i << std::endl;
    }
    else
        std::cout << "int: impossible" << std::endl;
    //std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << n << std::endl;
    return;
}











// IS CHAR -----------------------------------------
bool isChar(std::string s) {
    if(s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
        return true;
    return false;
}

// IS INT -----------------------------------------
bool isInt(std::string s) {
    if(s.empty())
        return false;
    
    size_t i = 0;

    if(s[i] == '+' || s[i] == '-') {
        if(s.length() == 1) return false;
        i++;
    }
        
    for(; i < s.length(); i++) {
        if(!std::isdigit(s[i])) return false;
    }
    errno = 0;
    char *end = NULL;
    long v = std::strtol(s.c_str(), &end, 10);
    if (errno != 0) return false;
    if (v < INT_MIN || v > INT_MAX) return false;
    if(*end != '\0') return false;
    return true;
}

// IS FLOAT -----------------------------------------
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

// IS DOUBLE -----------------------------------------
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

bool isPseudoFloat(std::string s) {
    if (s == "inff" || s == "-inff" || s == "+inff" || s == "nanf") return true;
    return false;
}

bool isPseudoDouble(std::string s) {
    if (s == "-inf" || s == "+inf" || s == "nan" || s == "inf") return true;
    return false;
}

void ScalarConverter::convert(std::string s) {

    if (isChar(s)) {
        char c = s[0];
        printFromChar(c);
    } 
    else if (isInt(s) || isFloat(s) || isDouble(s) ) {
        char *end = NULL;
        errno = 0;
        bool valid = false;
        double n = strtod(s.c_str(), &end);
        if(errno == 0 && end && (*end == '\0' || *end == 'f')) valid = true;
        else valid = false;
        std::cout << valid << std::endl;
        if(isInt(s)) printFromInt(n, valid);
        else if(isFloat(s)) printFromFloat(n, valid);
        else if(isDouble(s)) printFromDouble(n, valid);
    }
    else
        printAllImpossible();
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