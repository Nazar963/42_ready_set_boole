#include "curve.hpp"
#include <cstdint>
#include <cassert>
#include <iostream>
#include <vector>
#include <iomanip>

uint32_t morton_encode(uint16_t x, uint16_t y)
{
    return spalma_bit(x) | (spalma_bit(y) << 1);
}

void test_visual_4x4()
{
    const uint32_t expected[4][4] = {
        {0, 1, 4, 5},
        {2, 3, 6, 7},
        {8, 9, 12, 13},
        {10, 11, 14, 15}};

    std::cout << "Test B (visual): 4x4 Morton indices (k)\n";
    for (uint16_t y = 0; y < 4; ++y)
    {
        for (uint16_t x = 0; x < 4; ++x)
        {
            uint32_t k = morton_encode(x, y);
            std::cout << std::setw(2) << k << " ";
            assert(k == expected[y][x]);
        }
        std::cout << "\n";
    }
    std::cout << "OK: 4x4 table matches expected Z-order.\n\n";
}

int main()
{
    test_visual_4x4();

    return 0;
}