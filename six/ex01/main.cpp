#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data original;
    original.id = 42;
    original.name = "John";
    original.value = "Rua Aspicuelta, 422";

    Data* ptr = &original;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* recovered = Serializer::deserialize(raw);

    // Case 1: Endereço é o mesmo
    std::cout << "ptr:       " << ptr << std::endl;
    std::cout << "recovered: " << recovered << std::endl << std::endl;
    if (ptr == recovered)
        std::cout << "✅ Same address" << std::endl;
    else
        std::cout << "❌ Different address" << std::endl;

    // Case 2: Dados estão intactos (contra falso positivo)
    std::cout << std::endl;
    std::cout << "id:    " << recovered->id << std::endl;
    std::cout << "name:  " << recovered->name << std::endl;
    std::cout << "value: " << recovered->value << std::endl;

    // Case 3: Modificar original e ver que recovered or new_recovered reflete a mudança
    std::cout << std::endl;
    std::cout << "📝 Modificando original.id de 42 para 99" << std::endl << std::endl;
    original.id = 99;
    uintptr_t new_raw = Serializer::serialize(ptr);
    Data* new_recovered = Serializer::deserialize(new_raw);
    std::cout << "original.id:  " << original.id << std::endl;
    std::cout << "recovered->id: " << recovered->id << std::endl;
    std::cout << "new_recovered->id: " << new_recovered->id << std::endl;
    if (original.id == recovered->id && original.id == new_recovered->id)
        std::cout << std::endl << "✅ Same object (change reflected)" << std::endl;
    else
        std::cout << std::endl << "❌ Different objects (independent copy)" << std::endl;
    std::cout << std::endl;
    return 0;
}