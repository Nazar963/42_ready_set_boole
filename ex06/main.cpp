#include "conjunctive_normal_form.hpp"

int main(void)
{
    std::string formu = "CD&B|A&";
    std::cout << "Output desiderato: A|BC|BD|& -> ";
    std::cout << conjunctive_normal_form(formu) << std::endl;

    std::string formul = "AB&C|";
    std::cout << "Output desiderato: AB|AC|& -> ";
    std::cout << conjunctive_normal_form(formul) << std::endl;

    std::string formula = "AB&!";
    std::cout << "Output desiderato: A!B!| -> ";
    std::cout << conjunctive_normal_form(formula) << std::endl;

    std::string formula1 = "AB|!";
    std::cout << "Output desiderato: A!B!& -> ";
    std::cout << conjunctive_normal_form(formula1) << std::endl;

    std::string formula2 = "AB|C&";
    std::cout << "Output desiderato: AB|C& -> ";
    std::cout << conjunctive_normal_form(formula2) << std::endl;

    std::string formula3 = "AB|C|D|";
    std::cout << "Output desiderato: ABCD||| -> ";
    std::cout << conjunctive_normal_form(formula3) << std::endl;

    std::string formula4 = "AB&C&D&";
    std::cout << "Output desiderato: ABCD&&& -> ";
    std::cout << conjunctive_normal_form(formula4) << std::endl;

    std::string formula5 = "AB&!C!|";
    std::cout << "Output desiderato: A!B!C!|| -> ";
    std::cout << conjunctive_normal_form(formula5) << std::endl;

    std::string formula6 = "AB|!C!&";
    std::cout << "Output desiderato: A!B!C!&& -> ";
    std::cout << conjunctive_normal_form(formula6) << std::endl;

    std::string formula7 = "A";
    std::cout << "Output desiderato: A -> ";
    std::cout << conjunctive_normal_form(formula7) << std::endl;

    std::string formula8 = "A!";
    std::cout << "Output desiderato: A! -> ";
    std::cout << conjunctive_normal_form(formula8) << std::endl;

    std::string formula9 = "A!!";
    std::cout << "Output desiderato: A -> ";
    std::cout << conjunctive_normal_form(formula9) << std::endl;

    std::string formula10 = "AB&";
    std::cout << "Output desiderato: AB& -> ";
    std::cout << conjunctive_normal_form(formula10) << std::endl;

    std::string formula11 = "AB|";
    std::cout << "Output desiderato: AB| -> ";
    std::cout << conjunctive_normal_form(formula11) << std::endl;

    std::string formula12 = "AB|C&";
    std::cout << "Output desiderato: AB|C& -> ";
    std::cout << conjunctive_normal_form(formula12) << std::endl;

    std::string formula13 = "AB|CD|&";
    std::cout << "Output desiderato: AB|CD|& -> ";
    std::cout << conjunctive_normal_form(formula13) << std::endl;

    std::string formula14 = "ABC&|";
    std::cout << "Output desiderato: AB|AC|& -> ";
    std::cout << conjunctive_normal_form(formula14) << std::endl;

    std::string formula15 = "AB&C|";
    std::cout << "Output desiderato: AC|BC|& -> ";
    std::cout << conjunctive_normal_form(formula15) << std::endl;

    std::string formula16 = "AB&CD&|";
    std::cout << "Output desiderato: AC|AD|BC|BD|&&& -> ";
    std::cout << conjunctive_normal_form(formula16) << std::endl;

    std::string formula17 = "ABCD&|&";
    std::cout << "Output desiderato: ABC|BD|&& -> ";
    std::cout << conjunctive_normal_form(formula17) << std::endl;

    std::string formula18 = "ABC!&|!";
    std::cout << "Output desiderato: A!B!C|& -> ";
    std::cout << conjunctive_normal_form(formula18) << std::endl;

    /* ------------------------------------------------------------------------- */
    /*                              Casi con errori                              */
    /* ------------------------------------------------------------------------- */
    std::string formula19 = "AB|C&!&&";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << conjunctive_normal_form(formula19) << std::endl;

    std::string formula20 = "AB|1";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << conjunctive_normal_form(formula20) << std::endl;

    std::string formula21 = "ab|";
    std::cout << "Output desiderato: Input invalido -> ";
    std::cout << conjunctive_normal_form(formula21) << std::endl;

    return (0);
}