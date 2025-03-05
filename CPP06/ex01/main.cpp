#include "Serializer.hpp"

int main() {
    Data original = {"John", 30, 5.9};
    std::cout << "Original Data: " << original.name << ", " << original.age << ", " << original.height << std::endl;
    
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;
    
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << deserialized->name << ", " << deserialized->age << ", " << deserialized->height << std::endl;
    
    if (&original == deserialized) {
        std::cout << "Success: Pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }
    
    Data another = {"Anna", 25, 5.5};
    uintptr_t anotherRaw = Serializer::serialize(&another);
    Data* anotherDeserialized = Serializer::deserialize(anotherRaw);
    
    std::cout << "\nAdditional Test: " << std::endl;
    std::cout << "Original Data: " << another.name << ", " << another.age << ", " << another.height << std::endl;
    std::cout << "Serialized uintptr_t: " << anotherRaw << std::endl;
    std::cout << "Deserialized Data: " << anotherDeserialized->name << ", " << anotherDeserialized->age << ", " << anotherDeserialized->height << std::endl;
    
    if (&another == anotherDeserialized) {
        std::cout << "Success: Pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }
    
    return 0;
}
