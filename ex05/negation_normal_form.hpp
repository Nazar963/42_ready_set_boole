# ifndef NEGATION_NORMAL_FORM_HPP
# define NEGATION_NORMAL_FORM_HPP

# include <string>
# include <vector>
# include <iostream>

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
std::string tree_to_string(const node *root);
int check_input(std::string &formula, std::string &symbols);
node *remove_non_nnf_operators(node *root);
std::string negation_normal_form(std::string &formula);

# endif