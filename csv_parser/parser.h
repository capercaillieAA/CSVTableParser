//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_PARSER_H
#define CSVTABLEPARSER_PARSER_H

#include <vector>
#include <string>

class parser {
public:
    virtual ~parser() = default;

    virtual std::vector<std::string> parse_csv_str(std::string csv_str) = 0;
};


#endif //CSVTABLEPARSER_PARSER_H
