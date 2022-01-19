//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_BIN_EXPRESSION_H
#define CSVTABLEPARSER_BIN_EXPRESSION_H

#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include "expression.h"
#include "argument.h"
#include "../csv_parser/expression_parser.h"

class bin_expression : public expression{
public:
    explicit bin_expression(const std::string& expr);
    ~bin_expression();

    bin_expression(const bin_expression& other) = delete;
    bin_expression& operator= (const bin_expression& other) = delete;

    std::vector<argument> get_args() const override final;
    std::function<int(int, int)> get_operator() const override final;

    bool is_division() const;

private:
    static std::string operators;

    parser* parser;
    argument first_arg, second_arg;
    std::string op;
};


#endif //CSVTABLEPARSER_BIN_EXPRESSION_H
