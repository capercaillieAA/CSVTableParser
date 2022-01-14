//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_PARSER_H
#define CSVTABLEPARSER_CSV_PARSER_H

#include "parser.h"

class csv_parser : public parser {
public:
    std::vector<std::string> parse_csv_str(std::string csv_str) override final;
};


#endif //CSVTABLEPARSER_CSV_PARSER_H
