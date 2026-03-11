#include "Adder.hpp"

uint32_t adder(uint32_t a, uint32_t b)
{
    uint32_t holder;

    while (b)
    {
        holder = (a & b) << 1;
        a = a ^ b;
        b = holder;
    }

    return (a);
}
