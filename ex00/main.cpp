#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        std::cout << "Usage: insert element" << std::endl;
        return 1;
    }
    (void)argc;
    std::string input = argv[1];
    ScalarConverter::convert(argv[1]);
    return 0;
}
