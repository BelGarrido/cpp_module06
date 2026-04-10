#include "ScalarConverter.hpp"

// Static utility-style class: constructor/destructor stay trivial.
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string s) {
    char* end;
    double n;

    // 1) Single non-digit character input (e.g. "a") -> convert from ASCII value.
    if (s.length() == 1 && !std::isdigit(s[0])) {
        n = static_cast<double>(s[0]);
    } else {
        // 2) Parse with strtod:
        //    - Converts the longest valid numeric prefix to double.
        //    - Supports sign, decimals, exponent notation, and inf/nan forms.
        //    - `end` points to the first character not consumed by the numeric parse.
        n = std::strtod(s.c_str(), &end);
        
        // Validation rule:
        // - If end == start, nothing numeric was parsed.
        // - If remaining chars are not empty (or exactly one trailing 'f'), input is invalid.
        // This keeps literals like 42.0f valid, but rejects tails like "42abc".
        if (s.c_str() == end || (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
    }

    // char output: valid ASCII printable range only.
    std::cout << "char: ";
    if (std::isnan(n) || std::isinf(n) || n < 0 || n > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(n))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
    }

    // int output: only if finite and inside int bounds.
    std::cout << "int: ";
    if (std::isnan(n) || std::isinf(n) || n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(n) << std::endl;
    }

    // float/double output: keep module format, forcing .0 for integer-looking values.
    float f = static_cast<float>(n);
    if (f - static_cast<int>(f) == 0) {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << n << ".0" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: "
         << std::setprecision(6)
         << n << std::endl;
    }
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