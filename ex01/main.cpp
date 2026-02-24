#include "Multiplier.hpp"

int main(void)
{
    std::cout << "Output desiderato: 15 -> ";
    std::cout << multiplier(3, 5) << std::endl;

    std::cout << "Output desiderato: 2 -> ";
    std::cout << multiplier(1, 2) << std::endl;

    std::cout << "Output desiderato: 0 -> ";
    std::cout << multiplier(0, 2) << std::endl;

    std::cout << "Output desiderato: 36 -> ";
    std::cout << multiplier(12, 3) << std::endl;

    std::cout << "Output desiderato: 6204 -> ";
    std::cout << multiplier(141, 44) << std::endl;

    std::cout << "Output desiderato: 37476 -> ";
    std::cout << multiplier(12, 3123) << std::endl;

    return (0);
}