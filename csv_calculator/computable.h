//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_COMPUTABLE_H
#define CSVTABLEPARSER_COMPUTABLE_H

#include <map>
#include <string>
#include "expression.h"

class computable{
public:
    virtual ~computable() = default;

    virtual std::map<std::string, expression*> get_expressions() = 0;
};
#endif //CSVTABLEPARSER_COMPUTABLE_H
