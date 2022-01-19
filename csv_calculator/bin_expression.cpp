//
// Created by andru on 16.01.2022.
//

#include "bin_expression.h"

std::string bin_expression::operators = "+-*/";

bin_expression::bin_expression(const std::string& expr) {
    parser = new expression_parser();
    auto args = parser->parse(expr, operators);
    op = args[0];
    first_arg = argument(args[1]);
    second_arg = argument(args[2]);
}

bin_expression::~bin_expression() {
    delete parser;
}

std::vector<argument> bin_expression::get_args() const {
    return std::vector<argument>{first_arg, second_arg};
}

std::function<int(int, int)> bin_expression::get_operator() const {
    auto func = std::function < int(int, int) > ();
    if (op == "+") {
        func = std::plus<>();
    } else if (op == "-") {
        func = std::minus<>();
    } else if (op == "*") {
        func = std::multiplies<>();
    } else if (op == "/") {
        func = std::divides<>();
    }

    return func;
}
