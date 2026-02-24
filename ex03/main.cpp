#include "Boolean_evaluation.hpp"

int main()
{
    std::string formula = "10&";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "10|";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "11^";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "11>";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "10=";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "1011||=";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "1";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "0";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "1!";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "0!";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "0!!";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "01!>";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "11&";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "00&";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "10|";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "00|";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "10^";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "10>";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "01>";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "00>";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "11=";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "10&1|";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "11&0|";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "10|1&";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "11=0^";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "101&&";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "0!!1&";
    std::cout << "risultato aspettato: 0->" << eval_formula(formula) << std::endl; // 0

    formula = "10>0!|";
    std::cout << "risultato aspettato: 1->" << eval_formula(formula) << std::endl; // 1

    formula = "1a";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "12&";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "1 ";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "&&";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "!";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "101010";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // errore

    formula = "11!!";
    std::cout << "risultato aspettato: errore->" << eval_formula(formula) << std::endl; // 1

    return 0;
}