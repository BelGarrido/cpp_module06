#include "Data.hpp"
#include "Base.hpp"
#include "../colors.hpp"

int main() {
    std::srand(std::time(NULL));

    {   std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ DYNAMIC CAST #1 ] *´¯`*..*´¯`* " << RESET << std::endl;
        Base *newBase = generate();
        std::cout << CYAN << "Identify ptr --> " << RESET;
        identify(newBase);
        Base &ref = *newBase;
        std::cout << CYAN << "Identify ref --> " << RESET;
        identify(ref);
        delete(newBase);
    }

    {   std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ DYNAMIC CAST #2 ] *´¯`*..*´¯`* " << RESET << std::endl;
        Base *newBase = generate();
        std::cout << CYAN << "Identify ptr --> " << RESET;
        identify(newBase);
        Base &ref = *newBase;
        std::cout << CYAN << "Identify ref --> " << RESET;
        identify(ref);
        delete(newBase);
    }

    {   std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ DYNAMIC CAST #3 ] *´¯`*..*´¯`* " << RESET << std::endl;
        Base *newBase = generate();
        std::cout << CYAN << "Identify ptr --> " << RESET;
        identify(newBase);
        Base &ref = *newBase;
        std::cout << CYAN << "Identify ref --> " << RESET;
        identify(ref);
        delete(newBase);
    }

    return 0;
}
