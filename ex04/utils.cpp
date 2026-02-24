#include "Truth_table.hpp"

void print_truth_table_header(std::string &v_model)
{
    size_t i = 0;
    std::cout << "| ";
    while (i < v_model.length())
    {
        std::cout << v_model[i] << " | ";
        i++;
    }
    std::cout << "= |" << std::endl;
    std::cout << "|";
    i = 0;
    while (i < v_model.length())
    {
        std::cout << "---|";
        i++;
    }
    std::cout << "---|" << std::endl;
}

void print_truth_table_row(std::string &v_model, std::map<char, bool> &map, bool res)
{
    size_t i = 0;
    std::cout << "| ";
    while (i < v_model.length())
    {
        std::cout << map[v_model[i]] << " | ";
        i++;
    }
    std::cout << (res ? "1" : "0") << " |" << std::endl;
}