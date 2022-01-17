//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_EXPRESSION_H
#define CSVTABLEPARSER_EXPRESSION_H

#include <string>
#include <vector>

class expression {
public:
    virtual ~expression() = default;

    virtual std::vector<std::string> get_args() = 0;
    virtual std::string get_operator() = 0;
};


#endif //CSVTABLEPARSER_EXPRESSION_H
