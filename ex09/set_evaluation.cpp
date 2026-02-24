#include "set_evaluation.hpp"

std::string error_message()
{
    std::cout << "Input invalido";
    return "";
}

int check_input(std::string &formula, std::string &symbols)
{
    size_t i = 0;
    bool has_operand = false;

    while (i < formula.length())
    {
        if (symbols.find(formula[i]) == std::string::npos)
        {
            return 1;
        }
        i++;
    }
    i = 0;
    while (i < formula.length())
    {
        if (isalpha(formula[i]) && isupper(formula[i]))
        {
            has_operand = true;
            break;
        }
        i++;
    }
    if (!has_operand)
    {
        return 1;
    }
    return 0;
}

std::vector<int32_t> gest_neg(std::vector<int32_t> holder, std::vector<int32_t> universo)
{
    std::vector<int32_t> res;

    for (const auto &a : universo)
    {
        if (std::find(holder.begin(), holder.end(), a) != holder.end())
        {
            continue;
        }
        else
        {
            res.push_back(a);
        }
    }
    return (res);
}

std::vector<int32_t> gest_intersezione(std::vector<int32_t> left, std::vector<int32_t> right)
{
    std::vector<int32_t> res;

    for (const auto &a : left)
    {
        if (std::find(right.begin(), right.end(), a) != right.end())
        {
            res.push_back(a);
        }
    }
    return (res);
}

std::vector<int32_t> gest_unione(std::vector<int32_t> left, std::vector<int32_t> right)
{
    left.insert(left.end(), right.begin(), right.end());
    std::sort(left.begin(), left.end());
    left.erase(std::unique(left.begin(), left.end()), left.end());
    return (left);
}

std::vector<int32_t> eval_set(std::string &formula, std::vector<std::vector<int32_t>> sets)
{
    size_t i = 0;
    size_t j = 0;
    std::vector<std::vector<int32_t>> loco;
    std::vector<int32_t> right;
    std::vector<int32_t> left;
    std::vector<int32_t> holder_a;
    std::vector<int32_t> holder_b;
    std::vector<int32_t> holder_c;
    std::string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!&|^>=";
    std::string operators = "!&|^>=";
    std::vector<int32_t> universo;
    std::vector<std::vector<int32_t>> new_sets;

    if (check_input(formula, symbols) == 1)
    {
        error_message();
        return {};
    }

    for (auto &a : sets)
    {
        std::sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());
        new_sets.push_back(a);
        universo.insert(universo.end(), a.begin(), a.end());
    }
    std::sort(universo.begin(), universo.end());
    universo.erase(std::unique(universo.begin(), universo.end()), universo.end());

    while (i < formula.length())
    {
        if (operators.find(formula[i]) != std::string::npos)
        {
            if (formula[i] == '!')
            {
                if (loco.size() < 1)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                loco.push_back(gest_neg(right, universo));
            }
            else if (formula[i] == '&')
            {
                if (loco.size() < 2)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                left = loco.back();
                loco.pop_back();
                loco.push_back(gest_intersezione(left, right));
            }
            else if (formula[i] == '|')
            {
                if (loco.size() < 2)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                left = loco.back();
                loco.pop_back();
                loco.push_back(gest_unione(left, right));
            }
            else if (formula[i] == '^')
            {
                if (loco.size() < 2)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                left = loco.back();
                loco.pop_back();
                holder_a = gest_neg(right, left);
                holder_b = gest_neg(left, right);
                loco.push_back(gest_unione(holder_a, holder_b));
            }
            else if (formula[i] == '>')
            {
                if (loco.size() < 2)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                left = loco.back();
                loco.pop_back();
                holder_a = gest_neg(left, universo);
                loco.push_back(gest_unione(right, holder_a));
            }
            else if (formula[i] == '=')
            {
                if (loco.size() < 2)
                {
                    error_message();
                    return {};
                }
                right = loco.back();
                loco.pop_back();
                left = loco.back();
                loco.pop_back();
                holder_a = gest_neg(right, left);
                holder_b = gest_neg(left, right);
                holder_c = gest_unione(holder_a, holder_b);
                loco.push_back(gest_neg(holder_c, universo));
            }
        }
        else
        {
            j = formula[i] - 'A';
            if (j >= new_sets.size())
            {
                error_message();
                return {};
            }
            loco.push_back(new_sets[j]);
        }
        i++;
    }
    if (loco.size() != 1)
    {
        error_message();
        return {};
    }

    return (loco.back());
}