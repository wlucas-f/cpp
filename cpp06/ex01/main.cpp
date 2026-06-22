#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(){
    Data ford;
    ford.model = "T";
    ford.year = 1908;
    Data *ptr = &ford;
    uintptr_t serial = Serializer::serialize(ptr);
    Data *converted = Serializer::deserialize(serial);
    std::cout << "Model: " << converted->model << "\n";
    std::cout << "Year: " << converted->year << "\n";
}
