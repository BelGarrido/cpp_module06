#include "Data.hpp"
#include "Serializer.hpp"
#include "../colors.hpp"

int main() {

    Data newData;
    newData.id = 101;
    newData.name = "trial";

    Data *ptrData = &newData;
    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ PRINT DATA VALUES ] *´¯`*..*´¯`* " << RESET << std::endl;
    std::cout << "ptrData->id: " << ptrData->id << std::endl;
    std::cout << "ptrData->name: " << ptrData->name << std::endl;

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ PRINT MEMORY ADDRESS ] *´¯`*..*´¯`* " << RESET << std::endl;
    std::cout << "ptrData(og pointer): " << ptrData << std::endl;
    std::cout << "&newData: " << &newData << std::endl;

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ SERIALIZER ] *´¯`*..*´¯`* " << RESET << std::endl;
    uintptr_t unit = Serializer::serialize(ptrData);
    std::cout << "Unit(uintptr_t from data*): " <<unit << std::endl;

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ DESERIALIZER ] *´¯`*..*´¯`* " << RESET << std::endl;
    Data *newPtrData = Serializer::deserialize(unit);
    std::cout << "newPtrData(data* from uintptr_t): " << newPtrData << std::endl;

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ PRINT DATA VALUES AGAIN ] *´¯`*..*´¯`* " << RESET << std::endl;
    std::cout << "newPtrData->id: " << newPtrData->id << std::endl;
    std::cout << "newPtrData->name: " << newPtrData->name << std::endl;
}

