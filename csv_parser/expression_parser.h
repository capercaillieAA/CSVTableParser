//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_EXPRESSION_PARSER_H
#define CSVTABLEPARSER_EXPRESSION_PARSER_H

#include "parser.h"

class expression_parser : public parser{
public:
    std::vector<std::string> parse(const std::string& expr_str, const std::string& delims) override final;

};


#endif //CSVTABLEPARSER_EXPRESSION_PARSER_H
