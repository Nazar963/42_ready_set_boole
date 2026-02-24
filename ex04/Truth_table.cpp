#include "Truth_table.hpp"

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
    if (*root == nullptr)
    {
        return;
    }
    clean_tree(&(*root)->left);
    clean_tree(&(*root)->right);
    delete *root;
    *root = nullptr;
}

void clear_holder(std::vector<node *> &holder)
{
    while (!holder.empty())
    {
        clean_tree(&holder.back());
        holder.pop_back();
    }
}

bool apply_operator(char op, bool l, bool r)
{
    switch (op)
    {
    case '&':
        return l && r;
    case '|':
        return l || r;
    case '^':
        return l != r;
    case '>':
        return !l || r;
    case '=':
        return l == r;
    default:
        return false;
    }
}

bool eval_tree(node *root, std::map<char, bool> &map)
{
    bool res;
    bool l_res;
    bool r_res;

    if (root->left == nullptr && root->right == nullptr)
    {
        return isalpha(root->value) ? map[root->value] : root->value - '0';
    }
    if (root->left)
    {
        l_res = eval_tree(root->left, map);
    }
    if (root->right)
    {
        r_res = eval_tree(root->right, map);
    }
    if (root->left && root->right)
    {
        res = apply_operator(root->value, l_res, r_res);
    }
    else
    {
        res = root->left ? !l_res : !r_res;
    }
    return res;
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

void truth_table_engine(std::string &v_model, std::vector<node *> &holder)
{
    int potenza = (1 << v_model.length()) - 1;
    int mask = 0;
    size_t i = 0;
    std::map<char, bool> map = {};

    while (mask <= potenza)
    {
        while (i < v_model.length())
        {
            map[v_model[i]] = (mask & (1 << (v_model.length() - 1 - i))) != 0;
            i++;
        }
        bool res = eval_tree(holder.back(), map);
        print_truth_table_row(v_model, map, res);
        map.clear();
        mask++;
        i = 0;
    }
}

void print_truth_table(std::string &formula)
{
    size_t i = 0;
    std::string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!&|^>=";
    std::string operators = "!&|^>=";
    std::vector<node *> holder;
    std::string v_model;

    if (check_input(formula, symbols) == 1)
    {
        std::cout << "Input invalido => ";
        return;
    }

    while (i < formula.length())
    {
        if (operators.find(formula[i]) != std::string::npos)
        {
            if (formula[i] == '!')
            {
                if (holder.size() < 1)
                {
                    std::cout << "Input invalido => ";
                    clear_holder(holder);
                    return;
                }
                node *operand = holder.back();
                holder.pop_back();
                holder.push_back(create_operator_node(formula[i], nullptr, operand));
            }
            else
            {
                if (holder.size() < 2)
                {
                    std::cout << "Input invalido => ";
                    clear_holder(holder);
                    return;
                }
                node *right = holder.back();
                holder.pop_back();
                node *left = holder.back();
                holder.pop_back();
                holder.push_back(create_operator_node(formula[i], left, right));
            }
        }
        else
        {
            holder.push_back(create_node(formula[i]));
            v_model += formula[i];
        }
        i++;
    }
    if (holder.size() != 1)
    {
        std::cout << "Input invalido => ";
        clear_holder(holder);
        return;
    }
    print_truth_table_header(v_model);
    truth_table_engine(v_model, holder);
    clean_tree(&holder.back());
    return;
}
