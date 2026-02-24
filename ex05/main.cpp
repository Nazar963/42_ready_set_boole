#include "negation_normal_form.hpp"

int main(void)
{
    std::string formula1 = "AB&!";
    std::cout << "Output desiderato: A!B!| -> ";
    std::cout << negation_normal_form(formula1) << std::endl;

    std::string formula2 = "AB|!";
    std::cout << "Output desiderato: A!B!& -> ";
    std::cout << negation_normal_form(formula2) << std::endl;

    std::string formula3 = "AB>";
    std::cout << "Output desiderato: A!B| -> ";
    std::cout << negation_normal_form(formula3) << std::endl;

    std::string formula4 = "AB^";
    std::cout << "Output desiderato: AB!&BA!&| -> ";
    std::cout << negation_normal_form(formula4) << std::endl;

    std::string formula5 = "AB=";
    std::cout << "Output desiderato: AB&A!B!&| -> ";
    std::cout << negation_normal_form(formula5) << std::endl;

    std::string formula6 = "AB|C&!";
    std::cout << "Output desiderato: A!B!&C!| -> ";
    std::cout << negation_normal_form(formula6) << std::endl;

    /* ------------------------------------------------------------------------- */
    /*                              Casi con errori                              */
    /* ------------------------------------------------------------------------- */
    std::string formula7 = "AB|C&!&&";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << negation_normal_form(formula7) << std::endl;

    std::string formula8 = "AB|1";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << negation_normal_form(formula8) << std::endl;

    std::string formula9 = "ab|";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << negation_normal_form(formula9) << std::endl;

    return (0);
}
