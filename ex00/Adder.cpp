#include "Adder.hpp"

uint32_t adder(uint32_t a, uint32_t b)
{
    uint32_t holder;

    long long int z = b;
    std::cout << z << std::endl;

    while (b)
    {
        holder = (a & b) << 1;
        a = a ^ b;
        b = holder;
    }

    return (a);
}
