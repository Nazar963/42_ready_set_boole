#include "powerset.hpp"

int main(void)
{
    std::vector<int32_t> set = {1, 2, 3};
    std::vector<std::vector<int32_t>> ps = powerset(set);
    for (const auto &s : ps)
    {
        for (const auto &e : s)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int32_t> set2 = {1, 2, 3, 4};
    std::vector<std::vector<int32_t>> ps2 = powerset(set2);
    for (const auto &s : ps2)
    {
        for (const auto &e : s)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}