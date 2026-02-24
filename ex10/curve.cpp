#include "curve.hpp"

uint32_t spalma_bit(uint16_t x)
{
    uint32_t res = 0;
    int bit = 0;
    int i = 0;

    while (x)
    {
        bit = x & 1;
        res = res | (bit << i);
        x = x >> 1;
        i += 2;
    }
    return (res);
}

double map(uint16_t x, uint16_t y)
{
    double k = spalma_bit(x) | (spalma_bit(y) << 1);
    double res = k / (1ULL << 32);
    return (res);
}