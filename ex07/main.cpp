#include "sat.hpp"

int main(void)
{
    std::string formula = "AB|";
    std::cout << "Output desiderato: true -> ";
    std::cout << sat(formula) << std::endl;

    std::string formula1 = "AB&";
    std::cout << "Output desiderato: true -> ";
    std::cout << sat(formula1) << std::endl;

    std::string formula2 = "AA!&";
    std::cout << "Output desiderato: false -> ";
    std::cout << sat(formula2) << std::endl;

    std::string formula3 = "AA^";
    std::cout << "Output desiderato: false -> ";
    std::cout << sat(formula3) << std::endl;

    /* ------------------------------------------------------------------------- */
    /*                              Casi con errori                              */
    /* ------------------------------------------------------------------------- */
    std::string formula19 = "AB|C&!&&";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << sat(formula19) << std::endl;

    std::string formula20 = "AB|1";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << sat(formula20) << std::endl;

    std::string formula21 = "ab|";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << sat(formula21) << std::endl;

    return (0);
}