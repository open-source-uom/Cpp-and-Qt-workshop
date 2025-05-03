#include "parser.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

std::string read_until_delimiters(
    std::istringstream &f,
    std::vector<char> delimiters) {
    
    std::string return_str;
    while(std::find(std::begin(delimiters), std::end(delimiters), f.peek()) == std::end(delimiters)) {
        return_str += f.get();
    }

    return return_str;
}

Expression read_number(std::istringstream &f) {
    std::string curr_number = read_until_delimiters(f, {'+', '-', '*', '/', ')', EOF});
    double value = std::stod(curr_number);
    return NumericNode{value};
}

Expression parse(std::istringstream &s) {
    std::optional<Expression> prev;
    std::optional<Expression> curr;

    BasicOperationNode::Type type = BasicOperationNode::Type::None;
    while(s.peek() != EOF) {
        switch(s.peek()) {
            case '+': type = BasicOperationNode::Type::Plus; s.ignore(); break;
            case '-': type = BasicOperationNode::Type::Minus; s.ignore(); break;
            case '*': type = BasicOperationNode::Type::Times; s.ignore(); break;
            case '/': type = BasicOperationNode::Type::Div; s.ignore(); break;
            case ' ': {
                while (s.peek() == ' ') {
                    s.ignore();
                }
            } break;
            case '(':
                s.ignore();
                curr.emplace(parse(s));
                if (prev.has_value()) {
                    auto new_prev = std::make_unique<BasicOperationNode>(
                        std::move(prev.value()),
                        std::move(curr.value()),
                        type);
                    
                    prev.emplace(std::move(new_prev));
                } else {
                    prev.emplace(std::move(curr.value()));
                }
            break;
            case ')':
                s.ignore();
                return std::move(prev. value());
            break;
            default: {
                curr.emplace(read_number(s));
                if (prev.has_value()) {
                    auto new_prev = std::make_unique<BasicOperationNode>(
                        std::move(prev.value()),
                        std::move(curr.value()),
                        type);
                    
                    prev.emplace(std::move(new_prev));
                } else {
                    prev.emplace(std::move(curr.value()));
                }
            } break;
        }
    }

    return std::move(prev.value());
}

Expression parse(std::string s) {
    std::istringstream ss(s);
    return parse(ss);
}
