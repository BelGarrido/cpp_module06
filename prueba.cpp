#include <iostream>
#include <string>

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
    if (s == "-inff" || s == "+inff" || s == "nanf" || s == "inff") return true;
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
if (s == "-inf" || s == "+inf" || s == "nan" || s == "inff") return true;

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

#include <iostream>
#include <string>
#include <iomanip>


// Función auxiliar para que el test sea legible
void printTest(std::string label, std::string value, bool result) {
    std::cout << std::left << std::setw(10) << label 
              << " [" << std::setw(12) << value << "] -> " 
              << (result ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") 
              << std::endl;
}


int main()
{
    // Variables originales
    std::string a = "1293";
    std::string b = ".9f";
    std::string c = "10.f";
    std::string d = "1.23223434f";
    std::string e = "1.2";
    std::string f = "-1.f";
    std::string g = "v";
    std::string h = "1";
    std::string i = "hola";

    // Nuevas variables para Double y casos borde
    std::string b1 = ".9f";        // Esto es un float, isDouble debe dar 0
    std::string c1 = "10";         // Esto es un int, isDouble debe dar 0 (o 1 según tu lógica de punto)
    std::string d1 = "1.23223434"; // Double estándar
    std::string d2 = ".23223434";  // Double sin parte entera
    std::string d3 = "42.";        // Double sin parte decimal
    std::string d4 = "nan";        // Pseudo-literal Double
    std::string d5 = "-inf";       // Pseudo-literal Double

    std::cout << "--- TEST CHAR ---" << std::endl;
    std::cout << "isChar(g) [v]: " << isChar(g) << std::endl;
    std::cout << "isChar(h) [1]: " << isChar(h) << std::endl;

    std::cout << "\n--- TEST INT ---" << std::endl;
    std::cout << "isInt(a) [1293]: " << isInt(a) << std::endl;
    std::cout << "isInt(h) [1]:    " << isInt(h) << std::endl;

    std::cout << "\n--- TEST FLOAT ---" << std::endl;
    std::cout << "isFloat(b) [.9f]:  " << isFloat(b) << std::endl;
    std::cout << "isFloat(d) [1.23f]:" << isFloat(d) << std::endl;
    std::cout << "isFloat(e) [1.2]:  " << isFloat(e) << " (Debe ser 0)" << std::endl;

    std::cout << "\n--- TEST DOUBLE ---" << std::endl;
    std::cout << "isDouble(d1) [1.2322]: " << isDouble(d1) << std::endl;
    std::cout << "isDouble(d2) [.2322]:  " << isDouble(d2) << std::endl;
    std::cout << "isDouble(d3) [42.]:    " << isDouble(d3) << std::endl;
    std::cout << "isDouble(b1) [.9f]:    " << isDouble(b1) << " (Debe ser 0)" << std::endl;
    std::cout << "isDouble(d4) [nan]:    " << isDouble(d4) << std::endl;
    std::cout << "isDouble(d5) [-inf]:   " << isDouble(d5) << std::endl;

    return 0;
}