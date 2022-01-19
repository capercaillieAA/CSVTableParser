//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_CALCULATOR_H
#define CSVTABLEPARSER_CALCULATOR_H

#include "../csv_table/table.h"

class calculator{
public:
    virtual ~calculator() = default;

    virtual bool calculate(computable& source) = 0;
};

#endif //CSVTABLEPARSER_CALCULATOR_H
