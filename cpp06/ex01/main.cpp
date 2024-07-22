# include "Serializer.hpp"
# include "Data.hpp"
# include "Color.hpp"


int main() {
    Data data;
    data.x = 42;
    data.y = 84;

    uintptr_t raw = Serializer::serialize(&data);
    Data* dataPtr = Serializer::deserialize(raw);

    std::cout << "Original data: (" YEL << data.x << NC ", " YEL << data.y << NC ")" << std::endl;
    std::cout << "Deserialized data: (" YEL << dataPtr->x << NC ", " YEL << dataPtr->y << NC ")" << std::endl;

    // Verify that the deserialized pointer is the same as the original pointer
    if (dataPtr == &data) {
        std::cout << "The deserialized pointer matches the original pointer! (" GRN "Success" NC ")"  << std::endl;
    } 
	else {
        std::cout << "The deserialized pointer does not match the original pointer! (" RED "Error" NC ")" << std::endl;
    }

    return 0;
}