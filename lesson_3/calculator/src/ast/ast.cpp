
#include "ast.h"

BasicOperationNode::~BasicOperationNode() = default;

double compute(Expression& expr) {
    auto&& lambda_call = [](auto&& arg) -> double {
        using Type = std::decay_t<decltype(arg)>;

        if constexpr (std::is_same<Type, NumericNode>::value) {
            return compute(arg);
        } else if constexpr (std::is_same<Type, std::unique_ptr<BasicOperationNode>>::value) {
            return compute(*arg);
        }
    };

    return std::visit(lambda_call, expr);
}

double compute(NumericNode &n) {
    return n.value;
}

double compute(BasicOperationNode &n) {
    double left = compute(n.m_left);
    double right = compute(n.m_right);

    switch(n.m_type) {
        case BasicOperationNode::Plus: return left + right;
        case BasicOperationNode::Minus: return left - right;
        case BasicOperationNode::Times: return left * right;
        case BasicOperationNode::Div: return left / right;
    }

    // Unreachable
    return 0;
}
