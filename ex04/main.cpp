#include "Truth_table.hpp"

int main()
{
    std::string formula = "AB&C|";
    print_truth_table(formula);

    std::cout << std::endl;

    std::string formula1 = "AB&C|D!^";
    print_truth_table(formula1);
    return 0;
}