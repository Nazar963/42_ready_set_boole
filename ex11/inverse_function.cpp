#include "inverse_function.hpp"

uint16_t dispalmare_bit(uint32_t k, bool xory)
{
    int i = 0;
    uint16_t res = 0;
    uint32_t bit = 0;

    if (xory)
    {
        while (i < 16)
        {
            bit = (k >> (2 * i)) & 1;
            res = res | (bit << i);
            i++;
        }
    }
    else
    {
        while (i < 16)
        {
            bit = (k >> (2 * i + 1)) & 1;
            res = res | (bit << i);
            i++;
        }
    }
    return (res);
}

std::vector<uint16_t> inverse_function(double n)
{
    uint16_t x;
    uint16_t y;
    uint32_t k;

    if (n == 1.0)
    {
        k = (1ULL << 32) - 1;
    }
    else
    {
        k = n * (1ULL << 32);
    }
    x = dispalmare_bit(k, true);
    y = dispalmare_bit(k, false);
    return {x, y};
}