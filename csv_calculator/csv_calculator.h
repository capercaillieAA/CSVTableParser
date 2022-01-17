//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_CALCULATOR_H
#define CSVTABLEPARSER_CSV_CALCULATOR_H

#include "calculator.h"

class csv_calculator : public calculator{
public:
    void calculate(computable &csv_src) override final;
};


#endif //CSVTABLEPARSER_CSV_CALCULATOR_H
