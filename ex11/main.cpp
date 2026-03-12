#include "inverse_function.hpp"

#include <cstdint>
#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

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

void test_round_trip()
{
    const std::pair<uint16_t, uint16_t> cases[] = {
        {0, 0},
        {1, 0},
        {0, 1},
        {2, 0},
        {0, 2},
        {3, 5},
        {42, 999},
        {65535, 0},
        {0, 65535},
        {65535, 65535}};

    for (const auto &p : cases)
    {
        double n = map(p.first, p.second);
        auto xy = inverse_function(n);
        assert(xy.size() == 2);
        assert(xy[0] == p.first);
        assert(xy[1] == p.second);
    }

    std::cout << "OK: round-trip cases\n";
}

int main()
{
    test_round_trip();
    return 0;
}