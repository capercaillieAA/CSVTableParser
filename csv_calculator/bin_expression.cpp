//
// Created by andru on 16.01.2022.
//

#include "bin_expression.h"

std::string bin_expression::operators = "+-*/";

bin_expression::bin_expression(const std::string& expr) {
    parser = new expression_parser();
    auto args = parser->parse(expr, operators);
    op = args[0];
    first_arg = args[1];
    second_arg = args[2];
}

bin_expression::~bin_expression() {
    delete parser;
}

std::vector<std::string> bin_expression::get_args() {
    return std::vector<std::string>{first_arg, second_arg};
}

std::string bin_expression::get_operator() {
    return op;
}
