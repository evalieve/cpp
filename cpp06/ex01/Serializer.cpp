# include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer& other)
{
    (void)other;
    return (*this);
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}