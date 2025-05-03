#pragma once

#include <memory>
#include <variant>

struct NumericNode {
    double value;
    double compute() {
        return value;
    }
};

struct BasicOperationNode;

using Expression = std::variant<
    NumericNode,
    std::unique_ptr<BasicOperationNode>>;

struct BasicOperationNode {
    enum Type {
        None,
        Plus,
        Minus,
        Times,
        Div
    };
    ~BasicOperationNode();
    
    Expression m_left;
    Expression m_right;
    Type m_type;
};

double compute(Expression& expr);
double compute(NumericNode& expr);
double compute(BasicOperationNode& expr);
