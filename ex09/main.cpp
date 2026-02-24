#include "set_evaluation.hpp"

int main()
{
    std::string formula = "A&B|C";
    std::vector<std::vector<int32_t>> sets = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int32_t> result = eval_set(formula, sets);
    std::cout << "[ ";
    for (const auto &a : result)
    {
        std::cout << a << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::string formula2 = "AB&";
    std::vector<std::vector<int32_t>> sets2 = {{0, 1, 2}, {0, 3, 4}};
    std::vector<int32_t> result2 = eval_set(formula2, sets2);
    std::cout << "[ ";
    for (const auto &a : result2)
    {
        std::cout << a << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::string formula3 = "AB|";
    std::vector<std::vector<int32_t>> sets3 = {{0, 1, 2}, {3, 4, 5}};
    std::vector<int32_t> result3 = eval_set(formula3, sets3);
    std::cout << "[ ";
    for (const auto &a : result3)
    {
        std::cout << a << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::string formula4 = "A!";
    std::vector<std::vector<int32_t>> sets4 = {{0, 1, 2}};
    std::vector<int32_t> result4 = eval_set(formula4, sets4);
    std::cout << "[ ";
    for (const auto &a : result4)
    {
        std::cout << a << " ";
    }
    std::cout << " ]" << std::endl;
    std::cout << std::endl;
    return 0;
}