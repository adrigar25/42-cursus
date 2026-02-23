#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.value = 42;
    data.name  = "hello";

    std::cout << "Original pointer : " << &data << std::endl;

    uintptr_t n = Serializer::serialize(&data);
    std::cout << "Serialized value : " << n << std::endl;

    Data* recovered = Serializer::deserialize(n);
    std::cout << "Recovered pointer: " << recovered << std::endl;

    if (recovered == &data)
        std::cout << "OK: pointers match\n";
    else
        std::cout << "KO: pointers do not match\n";
}