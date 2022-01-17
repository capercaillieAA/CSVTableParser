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

    virtual std::vector<std::string> parse(const std::string& str, const std::string& delims) = 0;
};


#endif //CSVTABLEPARSER_PARSER_H
