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

void ScalarConverter::convert(std::string s) {
    /* Detección: Analizar el string para ver si es un char, int, float o double.

    Conversión Inicial: Pasar ese string a un tipo contenedor (normalmente un double o un long double es buena idea porque "caben" todos los demás).

    Gestión de Casos Especiales: Si el string es "nan", "+inf", etc., ya sabes que el char y el int van a imprimir "impossible".

    El bloque de "Prints":

    Plaintext

    char:   [Aquí calculas y decides si imprimes el char, 'Non displayable' o 'impossible']
    int:    [Aquí calculas si cabe en un int o es 'impossible']
    float:  [Imprimes con un decimal .0f]
    double: [Imprimes con un decimal .0] */
}
