#include <parser.h>

#include <string>
#include <iostream>

int main() {
    Expression expr = parse("1 + (2 * 2) + 5");
    std::cout << "Result: " << compute(expr) << "\n";
    return 0;
}