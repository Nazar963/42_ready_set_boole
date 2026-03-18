# ready_set_boole: Boolean Algebra & Set Theory from Scratch 🧮

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_ready_set_boole)](https://github.com/Nazar963/42_ready_set_boole/blob/master/LICENSE)
[![C++](https://img.shields.io/badge/C++-98/11-blue)](https://isocpp.org/)
[![Exercises](https://img.shields.io/badge/Exercises-12/12-brightgreen)](https://github.com/Nazar963/42_ready_set_boole)

A complete implementation of boolean algebra, set theory and space-filling curves in C++ using only bitwise operations and custom data structures — no external libraries.

## Table of Contents 📖
- [Project Overview](#project-overview)
- [Mathematical Foundation](#mathematical-foundation)
- [Implementation](#implementation)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Limitations](#limitations)
- [Resources](#resources)
- [License](#license)

## Project Overview

ready_set_boole is a 42 School project that explores discrete mathematics and computer science fundamentals by implementing:
- Bitwise arithmetic (addition, multiplication)
- Gray code encoding
- Boolean formula evaluation using AST and RPN
- Truth table generation
- Negation Normal Form (NNF) conversion
- Conjunctive Normal Form (CNF) conversion
- SAT solver (boolean satisfiability)
- Power set generation
- Set-theoretic operations via formula evaluation
- Space-filling curves (Morton / Z-order)

**Project Requirements**:
- Implement without external/ML libraries
- Use only bitwise operations for arithmetic (ex00, ex01)
- Parse and evaluate formulas in Reverse Polish Notation (RPN)
- Build and traverse Abstract Syntax Trees (AST)
- Handle all boolean operators: `!` `&` `|` `^` `>` `=`
- Map 2D coordinates to 1D via Morton encoding and back

**Note**: All 12 exercises (ex00–ex11) are implemented in this solution.

## Mathematical Foundation

### Bitwise Arithmetic
Addition uses the half-adder identity — XOR for the sum bit, AND-shift for the carry:

$a + b = (a \oplus b) + ((a \wedge b) \ll 1)$

Multiplication reduces to repeated addition with bit-shifting:

$a \times b = \sum_{i=0}^{31} a \cdot b_i \cdot 2^i$

### Gray Code
A binary-reflected Gray code where adjacent values differ by exactly one bit:

$G(n) = n \oplus (n \gg 1)$

### Boolean Logic Operators (RPN)

| Symbol | Operation | Definition |
|--------|-----------|------------|
| `!` | Negation | $\neg A$ |
| `&` | Conjunction | $A \wedge B$ |
| `\|` | Disjunction | $A \vee B$ |
| `^` | Exclusive OR | $A \oplus B$ |
| `>` | Material Implication | $A \Rightarrow B \equiv \neg A \vee B$ |
| `=` | Logical Equivalence | $A \Leftrightarrow B \equiv (A \wedge B) \vee (\neg A \wedge \neg B)$ |

### Normal Forms

**Negation Normal Form (NNF)** — negations applied only to literals:
- $A \oplus B \Rightarrow (A \wedge \neg B) \vee (\neg A \wedge B)$
- $A \Rightarrow B \Rightarrow \neg A \vee B$
- $\neg(A \wedge B) \Rightarrow \neg A \vee \neg B$ (De Morgan)
- $\neg(A \vee B) \Rightarrow \neg A \wedge \neg B$ (De Morgan)

**Conjunctive Normal Form (CNF)** — conjunction of disjunctions:

$\bigwedge_{i} \left(\bigvee_{j} l_{ij}\right)$

### Morton Curve (Z-Order)
Maps 2D coordinates $(x, y)$ to $[0, 1)$ by interleaving their bits:

$Z(x, y) = \frac{\text{interleave}(x, y)}{2^{32}}$

## Implementation

### Key Code Snippets

**Bitwise Addition** — carry propagation loop:
```cpp
uint32_t adder(uint32_t a, uint32_t b)
{
    uint32_t holder;

    while (b)
    {
        holder = (a & b) << 1;
        a = a ^ b;
        b = holder;
    }
    return (a);
}
```

**Boolean Formula Evaluation** — AST-based RPN evaluator:
```cpp
bool eval_expression(node *root)
{
    std::map<char, bool> map = {
        {'0', false},
        {'1', true},
        {'&', root->left->value - '0' && root->right->value - '0'},
        {'|', root->left->value - '0' || root->right->value - '0'},
        {'^', root->left->value - '0' != root->right->value - '0'},
        {'>', !(root->left->value - '0') || (root->right->value - '0')},
        {'=', root->left->value - '0' == root->right->value - '0'},
    };
    return (map[root->value]);
}
```

**Morton Encoding** — bit interleaving for Z-order curve:
```cpp
uint32_t spalma_bit(uint16_t x)
{
    uint32_t res = 0;
    int bit = 0, i = 0;

    while (x)
    {
        bit = x & 1;
        res = res | (bit << i);
        x = x >> 1;
        i += 2;
    }
    return (res);
}

double map(uint16_t x, uint16_t y)
{
    double k = spalma_bit(x) | (spalma_bit(y) << 1);
    return k / (1ULL << 32);
}
```

## Features

### Exercise Breakdown

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | **Adder** | Addition using only bitwise XOR and AND |
| ex01 | **Multiplier** | Multiplication using `adder` and bit shifts |
| ex02 | **Gray Code** | Binary to Gray code conversion |
| ex03 | **Boolean Evaluation** | RPN formula evaluation via AST |
| ex04 | **Truth Table** | Generate truth tables for any formula |
| ex05 | **NNF** | Convert formula to Negation Normal Form |
| ex06 | **CNF** | Convert formula to Conjunctive Normal Form |
| ex07 | **SAT** | Boolean satisfiability solver |
| ex08 | **Power Set** | Recursive power set generation |
| ex09 | **Set Evaluation** | Evaluate set-theoretic formulas |
| ex10 | **Curve** | Morton / Z-order space-filling curve |
| ex11 | **Inverse Curve** | Reverse Morton encoding to (x, y) |

### Core Techniques
- **AST Construction**: Binary tree built from RPN tokens using a stack
- **De Morgan's Laws**: Applied recursively during NNF conversion
- **Cartesian Product**: Used to distribute OR over AND for CNF
- **Brute-Force SAT**: Enumerates all variable assignments over CNF
- **Bit Interleaving**: Morton encoding via single-bit extraction loop

## Installation

### Requirements
- C++ compiler (`g++` or `clang++`)
- GNU Make

### Setup
```bash
# Clone repository
git clone https://github.com/Nazar963/42_ready_set_boole.git
cd 42_ready_set_boole

# Build a specific exercise
cd ex00
make

# Build all exercises
for dir in ex*/; do make -C "$dir"; done
```

## Usage

### Running an Exercise
```bash
# Build and run
cd ex03
make
./ex03
```

### Example Outputs

**ex00 — Adder**:
```
adder(21, 21) = 42
```

**ex03 — Boolean Evaluation**:
```
10&  => 0
10|  => 1
11>  => 1
10=  => 0
```

**ex04 — Truth Table**:
```
| A | B | = |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |
```

**ex05 — NNF Conversion**:
```
AB|!  => A!B!&
AB>   => A!B|
AB=   => AB&A!B!&|
```

### Clean Build
```bash
# Clean a single exercise
cd ex00 && make fclean

# Clean all
for dir in ex*/; do make -C "$dir" fclean; done
```

## Limitations

This implementation has several constraints:
1. **Brute-Force SAT**: Exponential time — enumerates all 2^n assignments
2. **No DPLL/CDCL**: SAT solver lacks modern pruning heuristics
3. **Fixed Precision**: Morton curve limited to 16-bit coordinates
4. **No Polynomial Features**: Formulas are purely propositional (no arithmetic)
5. **No Interactive Mode**: Each exercise runs predefined test cases
6. **RPN Only**: Formulas must be written in Reverse Polish Notation

## Resources

1. [Boolean Algebra — Wikipedia](https://en.wikipedia.org/wiki/Boolean_algebra) — Theoretical background
2. [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) — RPN parsing reference
3. [De Morgan's Laws](https://en.wikipedia.org/wiki/De_Morgan%27s_laws) — NNF transformation rules
4. [Conjunctive Normal Form](https://en.wikipedia.org/wiki/Conjunctive_normal_form) — CNF conversion theory
5. [Morton Code (Z-Order Curve)](https://en.wikipedia.org/wiki/Z-order_curve) — Space-filling curve reference
6. [Boolean Satisfiability Problem](https://en.wikipedia.org/wiki/Boolean_satisfiability_problem) — SAT solver background

## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the application or adding more features.

## License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

## ⭐ Star this repository if you found it helpful!
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_ready_set_boole?style=social)](https://github.com/Nazar963/42_ready_set_boole/stargazers)

---

🧠 *"All models are wrong, but some are useful."* - George Box<br>
[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
[![GitHub Follow](https://img.shields.io/github/followers/Nazar963?style=social)](https://github.com/Nazar963)

---

## 🍀 Goodluck:
Good luck with your ready_set_boole project at 42! 🚀
