#include "Data.hpp"
#include "Serializer.hpp"

int main() {

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
}


/* Creas un objeto Data myData.

Guardas su dirección en un puntero: Data* ptr = &myData;.

Serializas: Conviertes ese puntero en un número: uintptr_t raw = Serializer::serialize(ptr);.

Deserializas: Conviertes el número otra vez en puntero: Data* result = Serializer::deserialize(raw);.

Compruebas: Si result == ptr, ¡has ganado! La dirección de memoria ha sobrevivido al viaje de ida y vuelta. */