//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_TABLE_H
#define CSVTABLEPARSER_TABLE_H

#include "../csv_calculator/computable.h"

class table : public computable {
public:
    virtual ~table() = default;

    virtual void put(const std::string& record_number, const std::string& column_name, const std::string& value) = 0;
    virtual void put(const std::string& cell_address, const std::string& value) = 0;
    virtual std::string get_cell_value(const std::string& cell_address) const = 0;
    virtual bool cell_exist(const std::string& cell_address) const = 0;
};


#endif //CSVTABLEPARSER_TABLE_H
