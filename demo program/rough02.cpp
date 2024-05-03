#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

void generateTruthTable(int n) {
    std::vector<std::string> variables(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter variable " << (char)('a' + i) << ": ";
        std::cin >> variables[i];
    }

    std::cout << std::setw(5);
    for (const std::string& var : variables) {
        std::cout << var << " ";
    }
    std::cout << std::endl;

    int combinations = std::pow(2, n);
    for (int i = 0; i < combinations; ++i) {
        std::cout << std::setw(5);
        for (int j = 0; j < n; ++j) {
            std::cout << ((i >> (n - 1 - j)) & 1 ? "F" : "T") << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of variables: ";
    std::cin >> n;

    generateTruthTable(n);

    return 0;
}
