#include "Multiplier.hpp"

uint32_t multiplier(uint32_t a, uint32_t b)
{
    uint32_t tot = 0;
    uint32_t bit_b = 0;

    while (b)
    {
        bit_b = b & 1;
        if (bit_b == 1)
        {
            tot = adder(tot, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return tot;
}