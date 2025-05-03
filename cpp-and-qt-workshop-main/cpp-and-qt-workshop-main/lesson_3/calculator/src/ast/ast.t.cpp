#include "ast.h"
#include <iostream>
#include <cassert>

int main() {
    NumericNode n1{3};
    NumericNode n2{5};

    BasicOperationNode expr{n1, n2, BasicOperationNode::Type::Minus};

    assert(compute(expr) == -2);
}
