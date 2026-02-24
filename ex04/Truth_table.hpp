#ifndef TRUTH_TABLE_HPP
#define TRUTH_TABLE_HPP

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

void print_truth_table(std::string &formula);
void print_truth_table_header(std::string &v_model);
void print_truth_table_row(std::string &v_model, std::map<char, bool> &map, bool res);

#endif