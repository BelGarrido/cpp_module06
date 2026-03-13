#include "Bureaucrat.hpp"

int main() {
    std::cout << CYAN << "*´¯`*..*´¯`* [ VALID CREATION ] *´¯`*..*´¯`* " << RESET << std::endl;    
    try {
        Bureaucrat b1("Assistant", 149);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" <<"*´¯`*..*´¯`* [ TOO LOW (151) ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b2("Outsider", 151);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << CYAN << "\n" <<"*´¯`*..*´¯`* [ TOO HIGH (0) ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b3("God", 0);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ DECREMENT && DECREMENT OVERFLOW ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b4("Intern", 149);
        b4.decrement(); // 149 -> 150
        std::cout << b4 << std::endl;    
        b4.decrement(); // ERROR
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ INCREMENT && INCREMENT OVERFLOW ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b5("Boss", 2);
        b5.increment(); // 2 -> 1
        std::cout << b5 << std::endl;    
        b5.increment(); // ERROR
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ COPY TEST ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b6("Boss", 1);
        Bureaucrat b7("Fake Boss", 150);
        b7 = b6; // ASSIGMENT
        Bureaucrat copy = b6; // COPY CONSTRUCTOR
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
