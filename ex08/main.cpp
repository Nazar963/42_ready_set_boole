#include "powerset.hpp"

int main(void)
{
    std::vector<int32_t> set = {2, 1};
    std::vector<std::vector<int32_t>> loco = powerset(set);
    std::cout << "quantità di elementi del powerset: " << loco.size() << std::endl;
    for (const auto &a : loco)
    {
        for (const auto &b : a)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int32_t> set1 = {3, 2, 1};
    std::vector<std::vector<int32_t>> loco1 = powerset(set1);
    std::cout << "quantità di elementi del powerset: " << loco1.size() << std::endl;
    for (const auto &a : loco1)
    {
        for (const auto &b : a)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int32_t> set2 = {4, 3, 2, 1};
    std::vector<std::vector<int32_t>> loco2 = powerset(set2);
    std::cout << "quantità di elementi del powerset: " << loco2.size() << std::endl;
    for (const auto &a : loco2)
    {
        for (const auto &b : a)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}