#include "Adder.hpp"

int main(void)
{
    std::cout << "Output desiderato: 8 -> ";
    std::cout << adder(3, 5) << std::endl;

    std::cout << "Output desiderato: 3 -> ";
    std::cout << adder(1, 2) << std::endl;

    std::cout << "Output desiderato: 15 -> ";
    std::cout << adder(12, 3) << std::endl;

    std::cout << "Output desiderato: 0 -> ";
    std::cout << adder(0, 0) << std::endl;

    std::cout << "Output desiderato: 1 -> ";
    std::cout << adder(1, 0) << std::endl;

    std::cout << "Output desiderato: 185447625 -> ";
    std::cout << adder(141324213, 44123412) << std::endl;

    std::cout << "Output desiderato: 435435435 -> ";
    std::cout << adder(123123123, 312312312) << std::endl;

    return (0);
}