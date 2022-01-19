//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_EXPRESSION_H
#define CSVTABLEPARSER_EXPRESSION_H

#include "argument.h"
#include <vector>
#include <functional>

class expression {
public:
    virtual ~expression() = default;

    virtual std::vector<argument> get_args() const = 0;
    virtual std::function<int(int, int)> get_operator() const = 0;
};


#endif //CSVTABLEPARSER_EXPRESSION_H
