#include "Gray_code.hpp"

int main()
{
    std::cout << "Output desiderato: 0 -> " << gray_code (0) << std::endl;
    std::cout << "Output desiderato: 1 -> " << gray_code (1) << std::endl;
    std::cout << "Output desiderato: 3 -> " << gray_code (2) << std::endl;
    std::cout << "Output desiderato: 2 -> " << gray_code (3) << std::endl;
    std::cout << "Output desiderato: 6 -> " << gray_code (4) << std::endl;
    std::cout << "Output desiderato: 7 -> " << gray_code (5) << std::endl;
    std::cout << "Output desiderato: 5 -> " << gray_code (6) << std::endl;
    std::cout << "Output desiderato: 4 -> " << gray_code (7) << std::endl;
    std::cout << "Output desiderato: 12 -> " << gray_code (8) << std::endl;
    std::cout << "Output desiderato: 13 -> " << gray_code (9) << std::endl;
    std::cout << "Output desiderato: 15 -> " << gray_code (10) << std::endl;
    std::cout << "Output desiderato: 14 -> " << gray_code (11) << std::endl;
    std::cout << "Output desiderato: 10 -> " << gray_code (12) << std::endl;
    return 0;
}