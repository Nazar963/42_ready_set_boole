#include "sat.hpp"

std::string error_message()
{
    std::cout << "Input invalido";
    return "";
}

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

node *xor_handler(node *root)
{
    return (create_operator_node('|',
                                 create_operator_node('&',
                                                      create_node(root->left->value), create_operator_node('!', nullptr, create_node(root->right->value))),
                                 create_operator_node('&',
                                                      create_node(root->right->value), create_operator_node('!', nullptr, create_node(root->left->value)))));
}

node *condizione_materiale_handler(node *root)
{
    return (create_operator_node('|', create_operator_node('!', nullptr, create_node(root->left->value)), create_node(root->right->value)));
}

node *ugualianza_logica_handler(node *root)
{
    return (create_operator_node('|', create_operator_node('&', create_node(root->left->value), create_node(root->right->value)),
                                 create_operator_node('&',
                                                      create_operator_node('!', nullptr, create_node(root->left->value)), create_operator_node('!', nullptr, create_node(root->right->value)))));
}

node *operators_expander(node *root)
{
    node *new_root = root;
    switch (root->value)
    {
    case '^':
        new_root = xor_handler(root);
        clean_tree(&root);
        break;
    case '>':
        new_root = condizione_materiale_handler(root);
        clean_tree(&root);
        break;
    case '=':
        new_root = ugualianza_logica_handler(root);
        clean_tree(&root);
        break;
    default:
        break;
    }
    return (new_root);
}

node *remove_non_nnf_operators(node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root;
    }
    if (root->left)
    {
        root->left = remove_non_nnf_operators(root->left);
    }
    if (root->right)
    {
        root->right = remove_non_nnf_operators(root->right);
    }
    if (root->left && root->right)
    {
        root = operators_expander(root);
    }

    return (root);
}

node *resolve_negations(node *root, bool neg)
{
    node *right;
    node *left;
    node *result;

    if (root->value == '!')
    {
        result = resolve_negations(root->right, !neg);
        delete root;
        return (result);
    }
    if (isalpha(root->value) && isupper(root->value))
    {
        if (neg)
            result = create_operator_node('!', nullptr, create_node(root->value));
        else
            result = create_node(root->value);
        delete root;
        return (result);
    }
    if (root->value == '&' && neg)
    {
        right = resolve_negations(root->right, neg);
        left = resolve_negations(root->left, neg);
        result = create_operator_node('|', left, right);
        delete root;
        return (result);
    }
    else if (root->value == '|' && neg)
    {
        right = resolve_negations(root->right, neg);
        left = resolve_negations(root->left, neg);
        result = create_operator_node('&', left, right);
        delete root;
        return (result);
    }
    else
    {
        right = resolve_negations(root->right, neg);
        left = resolve_negations(root->left, neg);
        result = create_operator_node(root->value, left, right);
        delete root;
        return (result);
    }
}

std::vector<std::vector<std::string>> prodotto_cartesiano(std::vector<std::vector<std::string>> v1, std::vector<std::vector<std::string>> v2)
{
    std::vector<std::vector<std::string>> res;

    for (const auto &a : v1)
    {
        for (const auto &b : v2)
        {
            std::vector<std::string> loco = a;
            loco.insert(loco.end(), b.begin(), b.end());
            res.push_back(loco);
        }
    }
    return (res);
}

std::vector<std::vector<std::string>> from_NNF_to_CNF(node *root)
{
    std::vector<std::vector<std::string>> l;
    std::vector<std::vector<std::string>> r;

    if (isalpha(root->value) || root->value == '!')
    {
        if (isalpha(root->value))
        {
            std::vector<std::vector<std::string>> letterale = {{}};
            letterale[0].push_back(std::string(1, root->value));
            return letterale;
        }
        else
        {
            std::vector<std::vector<std::string>> letterale = {{}};
            letterale[0].push_back(std::string{root->right->value, root->value});
            return letterale;
        }
    }
    if (root->value == '&')
    {
        std::vector<std::vector<std::string>> letterale;
        l = from_NNF_to_CNF(root->left);
        letterale.insert(letterale.end(), l.begin(), l.end());
        r = from_NNF_to_CNF(root->right);
        letterale.insert(letterale.end(), r.begin(), r.end());
        return letterale;
    }
    if (root->value == '|')
    {
        std::vector<std::vector<std::string>> res;
        l = from_NNF_to_CNF(root->left);
        r = from_NNF_to_CNF(root->right);
        res = prodotto_cartesiano(l, r);
        return (res);
    }
    return {{}};
}

bool satter(std::vector<std::vector<std::string>> &cnf, std::map<char, bool> &map)
{
    bool res;
    bool letterale;

    for (const auto &a : cnf)
    {
        res = false;
        for (const auto &b : a)
        {
            letterale = false;
            if (b.length() > 1)
                letterale = !map[b[0]];
            else
                letterale = map[b[0]];
            res = res | letterale;
        }
        if (!res)
            return (false);
    }
    return (true);
}

bool mappatura(std::string &v_model, std::vector<std::vector<std::string>> &cnf)
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

        if (satter(cnf, map))
            return true;
        map.clear();
        mask++;
        i = 0;
    }
    return false;
}

bool sat(std::string &formula)
{
    size_t i = 0;
    std::string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!&|^>=";
    std::string operators = "!&|^>=";
    std::vector<node *> holder;
    node *root = nullptr;
    std::string v_model;

    if (check_input(formula, symbols) == 1)
    {
        error_message();
        return false;
    }

    while (i < formula.length())
    {
        if (operators.find(formula[i]) != std::string::npos)
        {
            if (formula[i] == '!')
            {
                if (holder.size() < 1)
                {
                    clear_holder(holder);
                    error_message();
                    return false;
                }
                node *operand = holder.back();
                holder.pop_back();
                holder.push_back(create_operator_node(formula[i], nullptr, operand));
            }
            else
            {
                if (holder.size() < 2)
                {
                    clear_holder(holder);
                    error_message();
                    return false;
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
        clear_holder(holder);
        error_message();
        return false;
    }
    root = holder.back();
    root = remove_non_nnf_operators(root);
    root = resolve_negations(root, false);
    std::vector<std::vector<std::string>> cnf = from_NNF_to_CNF(root);
    clean_tree(&root);
    return (mappatura(v_model, cnf));
}
