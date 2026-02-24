#ifndef SAT_HPP
#define SAT_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>

struct node
{
    char value;
    node *left;
    node *right;
};

std::string error_message();
node *create_node(char value);
node *create_operator_node(char value, node *left, node *right);
void clean_tree(node **root);
void clear_holder(std::vector<node *> &holder);
int check_input(std::string &formula, std::string &symbols);
node *remove_non_nnf_operators(node *root);
bool sat(std::string &formula);

#endif