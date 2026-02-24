#ifndef BOOLEAN_EVALUATION_HPP
#define BOOLEAN_EVALUATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>

typedef struct node
{
    char value;
    node *left;
    node *right;
} node;

node *create_node(char value);
bool eval_formula(std::string &formula);

#endif  