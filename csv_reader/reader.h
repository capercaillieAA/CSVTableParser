//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_READER_H
#define CSVTABLEPARSER_READER_H

#include "../csv_table/table.h"

class reader {
public:
    virtual ~reader() = default;

    virtual bool read(table& dest) = 0;
};


#endif //CSVTABLEPARSER_READER_H
