#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.x = 42;
    data.y = 84;

    uintptr_t raw = Serializer::serialize(&data);
    Data* dataPtr = Serializer::deserialize(raw);

    std::cout << "Original data: (" << data.x << ", " << data.y << ")" << std::endl;
    std::cout << "Deserialized data: (" << dataPtr->x << ", " << dataPtr->y << ")" << std::endl;

    // Verify that the deserialized pointer is the same as the original pointer
    if (dataPtr == &data) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}