//
// Created by andru on 16.01.2022.
//

#include "expression_parser.h"

std::vector<std::string> expression_parser::parse(const std::string& expr_str, const std::string& delims) {
    auto expr_result = std::vector<std::string>(3);

    auto expr = expr_str.substr(1, expr_str.size() - 1);
    std::string cur_arg;
    for (const auto symb : expr){
        if (delims.find(symb) != std::string::npos) {
                expr_result[0] = symb;
                expr_result[1] = cur_arg;
                cur_arg = "";
            } else {
                cur_arg += symb;
            }
    }
    expr_result[2] = cur_arg;

    return expr_result;
}
