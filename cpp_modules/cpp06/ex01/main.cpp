#include <iostream>
#include "Serializer.hpp"


int main()
{
    Data * original = new Data();
    original->id = 42;
    original->name = "Wassup Homie";
    original->value = 3.14;

    std::cout << "=== Original Data object ===" << std::endl;
    std::cout << "Pointer address : " << original        << std::endl;
    std::cout << "id              : " << original->id    << std::endl;
    std::cout << "name            : " << original->name  << std::endl;
    std::cout << "value           : " << original->value << std::endl;

    uintptr_t raw  = Serializer::serialize(original);
    std::cout << "\n=== After serialize ===" << std::endl;
    std::cout << "Raw integer value: " << raw << std::endl;
    std::cout << "Raw as hex       : " << std::hex << raw << std::dec << std::endl;

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "\n=== After deserialize ===" << std::endl;
    std::cout << "Recovered pointer: " << deserialized       << std::endl;
    std::cout << "id               : " << deserialized->id   << std::endl;
    std::cout << "name             : " << deserialized->name << std::endl;
    std::cout << "value            : " << deserialized->value << std::endl;

     std::cout << "\n=== Verification ===" << std::endl;
    if (original == deserialized)
        std::cout << "PASS: original == deserialized (same pointer)" << std::endl;
    else
        std::cout << "FAIL: pointers differ!" << std::endl;
 
    delete original;
}