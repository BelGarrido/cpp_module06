#include "ScalarConverter.hpp"
#include "Data.hpp"
#include "Serializer.hpp"
#include "Base.hpp"
#include <ctime>

int main() {
    
    std::srand(std::time(NULL));
    Data newData;
    newData.id = 101;
    newData.name = "trial";

    Data *ptrData = &newData;

    std::cout << "ptrData(og pointer)" << ptrData << std::endl;
    std::cout << "&newData: "<< &newData << std::endl;
    
    uintptr_t unit = Serializer::serialize(ptrData);
    std::cout << "Unit(uintptr_t from data*): " <<unit << std::endl;
    Data *newPtrData = Serializer::deserialize(unit);
    std::cout << "newPtrData(data* from uintptr_t): " << newPtrData << std::endl;
    std::cout << "newPtrData->id: " << newPtrData->id << std::endl;
    std::cout << "newPtrData->name: " << newPtrData->name << std::endl;

    std::cout << "------------------- Dynamic_cast -------------------" << std::endl;

    Base *newBase = generate();
    identify(newBase);
    Base &ref = *newBase;
    identify(ref);
    return 0;
}
