#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>

int main(){
    Data ford("T", 1908);
    Data *ptr = &ford;
    uintptr_t serial = Serializer::serialize(ptr);
    Data *converted = Serializer::deserialize(serial);
    converted->printData();
}
