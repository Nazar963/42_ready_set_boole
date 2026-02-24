#include "powerset.hpp"

std::vector<std::vector<int32_t>> powerset_engine(std::vector<int32_t> &set, size_t i)
{
    std::vector<std::vector<int32_t>> res;
    std::vector<std::vector<int32_t>> res_loco;
    std::vector<int32_t> res_r;

    if (i == set.size())
    {
        return {{}};
    }
    res = powerset_engine(set, i + 1);
    for (const auto &a : res)
    {
        res_r.insert(res_r.end(), a.begin(), a.end());
        res_r.push_back(set[i]);
        res_loco.push_back(res_r);
        res_r.clear();
    }
    for (const auto &b : res_loco)
    {
        res.push_back(b);
    }

    return (res);
}

std::vector<std::vector<int32_t>> powerset(std::vector<int32_t> &set)
{
    size_t i = 0;
    return (powerset_engine(set, i));
}