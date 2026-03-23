#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>

// Clase estática: constructores privados en el .hpp o simplemente vacíos aquí
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string s) {
    char* end;
    double n;

    // 1. Caso especial: Char único no numérico
    if (s.length() == 1 && !std::isdigit(s[0])) {
        n = static_cast<double>(s[0]);
    } else {
        // 2. Intentar convertir a double (esto maneja int, float, double, nan, inf)
        n = std::strtod(s.c_str(), &end);
        
        // Si no se convirtió nada o hay basura al final (que no sea la 'f' de float)
        if (s.c_str() == end || (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))) {
            std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
            return;
        }
    }

    // --- LOGICA DE IMPRESIÓN UNIFICADA ---

    // CHAR
    std::cout << "char: ";
    if (std::isnan(n) || std::isinf(n) || n < 0 || n > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(n))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
    }

    // INT
    std::cout << "int: ";
    if (std::isnan(n) || std::isinf(n) || n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(n) << std::endl;
    }

    // FLOAT & DOUBLE
    // Forzamos un decimal si es un número entero para cumplir con el formato 42.0f
    float f = static_cast<float>(n);
    if (f - static_cast<int>(f) == 0) {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << n << ".0" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << n << std::endl;
    }
}