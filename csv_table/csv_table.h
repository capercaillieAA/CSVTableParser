//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_TABLE_H
#define CSVTABLEPARSER_CSV_TABLE_H

#include "table.h"
#include <map>

class csv_table : public table {
public:
    void put(const std::string& record_number, const std::string& column_name, const std::string& value) override final;
    void put(const std::string &cell_address, const std::string &value) override;
    std::string get_cell_value(const std::string& cell_address) override final;
    bool cell_exist(const std::string& cell_address) override final;

    std::map<std::string, expression*> get_expressions() override final;

    std::string to_csv();

private:
    std::vector<std::string> column_names;
    std::vector<std::string> record_numbers;
    std::map<std::string, std::string> table;
    std::map<std::string, expression*> expressions;
};


#endif //CSVTABLEPARSER_CSV_TABLE_H
