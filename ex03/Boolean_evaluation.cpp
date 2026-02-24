#include "Boolean_evaluation.hpp"

node *create_node(char value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

node *create_operator_node(char value, node *left, node *right)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void clean_tree(node **root)
{
    if (*root == nullptr) {
        return;
    }
    clean_tree(&(*root)->left);
    clean_tree(&(*root)->right);
    delete *root;
    *root = nullptr;
}
void clear_holder(std::vector<node *> &holder)
{
    while (!holder.empty()) {
        clean_tree(&holder.back());
        holder.pop_back();
    }
}

bool eval_expression(node *root)
{
    std::map<char, bool> map = {
        {'0', false},
        {'1', true},
        {'!', !root->value},
        {'&', root->left->value - '0' && root->right->value - '0'},
        {'|', root->left->value - '0' || root->right->value - '0'},
        {'^', root->left->value - '0' != root->right->value - '0'},
        {'>', !(root->left->value - '0') || (root->right->value - '0')},
        {'=', root->left->value - '0' == root->right->value - '0'},
    };

    return (map[root->value]);
}

bool eval_tree(node *root)
{
    bool res;
    bool l_res;
    bool r_res;

    if (root->left == nullptr && root->right == nullptr) {
        return root->value == '1';
    }
    if (root->left) {
        l_res = eval_tree(root->left);
    }
    if (root->right) {
        r_res = eval_tree(root->right);
    }
    if (root->left && root->right) {
        root->left->value = l_res ? '1' : '0';
        root->right->value = r_res ? '1' : '0';
        res = eval_expression(root);
    } else {
        res = root->left ? !l_res : !r_res;
    }
    return res;
}

int check_input(std::string &formula, std::string &symbols)
{
    long unsigned int i = 0;
    bool has_operand = false;

    while (i < formula.length())
    {
        if (symbols.find(formula[i]) == std::string::npos) {
            return 1;
        }
        i++;
    }
    i = 0;
    while (i < formula.length()) {
        if (formula[i] == '0' || formula[i] == '1') {
            has_operand = true;
            break;
        }
        i++;
    }
    if (!has_operand) {
        return 1;
    }
    return 0;
}

bool eval_formula(std::string &formula)
{
    long unsigned int i = 0;
    std::string symbols = "01!&|^>=";
    std::string operators = "!&|^>=";
    std::vector<node *> holder;

    if (check_input(formula, symbols) == 1) {
        std::cout << "Input invalido => ";
        return false;
    }

    while (i < formula.length())
    {
        if (operators.find(formula[i]) != std::string::npos) {
            if (formula[i] == '!') {
                if (holder.size() < 1) {
                    std::cout << "Input invalido => ";
                    clear_holder(holder);
                    return false;
                }
                node *operand = holder.back();
                holder.pop_back();
                holder.push_back(create_operator_node(formula[i], nullptr, operand));
            } else {
                if (holder.size() < 2) {
                    std::cout << "Input invalido => ";
                    clear_holder(holder);
                    return false;
                }
                node *right = holder.back();
                holder.pop_back();
                node *left = holder.back();
                holder.pop_back();
                holder.push_back(create_operator_node(formula[i], left, right));
            }
        }
        else {
            holder.push_back(create_node(formula[i]));
        }
        i++;
    }
    if (holder.size() != 1) {
        std::cout << "Input invalido => ";
        clear_holder(holder);
        return false;
    }
    bool res = eval_tree(holder.back());
    clean_tree(&holder.back());
    return res;
}
