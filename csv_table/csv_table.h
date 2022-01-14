//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_TABLE_H
#define CSVTABLEPARSER_CSV_TABLE_H

#include "table.h"
#include <map>

class csv_table : public table {
public:
    void put_next(const std::string& num_of_record, const std::string& value) override final;
    std::string get_cell_value(const std::string& cell_address) override final;
    bool cell_exist(const std::string& cell_address) override final;
    void set_header(const std::vector<std::string>& header) override final;

    std::string to_csv();

private:
    static int num_of_cells;

    std::vector<std::string> column_names;
    std::vector<std::string> record_numbers;
    std::map<std::string, std::string> table;
};


#endif //CSVTABLEPARSER_CSV_TABLE_H
