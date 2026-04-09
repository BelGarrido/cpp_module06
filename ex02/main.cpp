#include "Data.hpp"
#include "Base.hpp"

int main() {
    
    std::cout << "------------------- Dynamic_cast -------------------" << std::endl;

    Base *newBase = generate();
    identify(newBase);
    Base &ref = *newBase;
    identify(ref);
    delete(newBase);
    return 0;
}
