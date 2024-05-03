#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

// Function to evaluate logical AND
bool logicalAnd(bool a, bool b) {
    return a && b;
}

// Function to evaluate logical OR
bool logicalOr(bool a, bool b) {
    return a || b;
}

// Function to evaluate logical NOT
bool logicalNot(bool a) {
    return !a;
}

// Function to evaluate conditional operator (->) ~pVq
bool conditionalOperator(bool a, bool b) {
    return !a || b;
}
 
// Function to evaluate biconditional operator (<->) p->q and q->p
bool biconditionalOperator(bool a, bool b) {
    return (!a || b) && (!b || a);
}

// Function to generate truth table for given algebraic equation
void generateTruthTable(std::string equation) {
    std::vector<char> variables;

    // Extract variables from the equation
    for (char ch : equation) {
        if (isalpha(ch) && ch!='v') {
            variables.push_back(ch);
        }
    }

    // Print header
    std::cout << std::setw(5);
    for (char var : variables) {
        std::cout << var << " ";
    }
    std::cout << equation << std::endl;

    // Generate truth table rows
    for (int i = 0; i < std::pow(2, variables.size()); ++i) {
        std::cout << std::setw(5);
        for (int j=0;j<variables.size();j++) {
            std::cout << ((i >> (variables.size() - 1 - j)) & 1 ? "F" : "T") << " ";
            //std::cout << ((i >> (variables.size() - 1 - (var - 'a'))) & 1 ? "T" : "F") << " ";
        }

        // Evaluate the equation
        bool result = true;
        for (int j=0;j<equation.length();j++) {
            char ch=equation[j];
            if (isalpha(ch) && ch!='v') {
                result = result && ((i >> (equation.size() - 1 - j)) & 1);
            } else if (ch == '^') {
                result = result && logicalAnd(result,!result);
            } else if (ch == 'v') {
                result = result && logicalOr(result,!result);
            } else if (ch == '~') {
                result = result && logicalNot(result);
            } else if (ch == '>') {
                result = result && conditionalOperator(result,!result);
            } else if (ch == '<' && equation[1] == '-' && equation[2] == '>') {
                result = result && biconditionalOperator(result,!result);
            }
           
        }

         std::cout << (result ? "T" : "F") << std::endl;
    }
}

int main() {
    std::string equation;
    std::cout << "Enter algebraic equation: ";
    std::getline(std::cin, equation);

    generateTruthTable(equation);

    return 0;
}
