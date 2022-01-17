//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_BIN_EXPRESSION_H
#define CSVTABLEPARSER_BIN_EXPRESSION_H

#include <string>
#include <vector>
#include "expression.h"
#include "../csv_parser/expression_parser.h"

class bin_expression : public expression{
public:
    explicit bin_expression(const std::string& expr);
    ~bin_expression();

    bin_expression(const bin_expression& other) = delete;
    bin_expression& operator= (const bin_expression& other) = delete;

    std::vector<std::string> get_args() override final;
    std::string get_operator() override final;

private:
    static std::string operators;

    parser* parser;
    std::string first_arg, second_arg, op;
};


#endif //CSVTABLEPARSER_BIN_EXPRESSION_H
