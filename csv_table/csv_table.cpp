//
// Created by andru on 14.01.2022.
//

#include "csv_table.h"
#include "../csv_calculator/bin_expression.h"
#include <algorithm>

void csv_table::put(const std::string& record_number, const std::string& column_name, const std::string& value) {
    if (std::find(record_numbers.begin(), record_numbers.end(), record_number) == record_numbers.end()){
        record_numbers.push_back(record_number);
    }
    if (std::find(column_names.begin(), column_names.end(), column_name) == column_names.end()){
        column_names.push_back(column_name);
    }

    auto cell_address = column_name + record_number;
    if (value.starts_with('=')) {
        expressions[cell_address] = new bin_expression(value);
    }
    table[cell_address] = value;
}
void csv_table::put(const std::string &cell_address, const std::string &value) {
    table[cell_address] = value;
}

std::string csv_table::get_cell_value(const std::string& cell_address) const {
    return cell_exist(cell_address) ? table.at(cell_address) : "";
}

bool csv_table::cell_exist(const std::string& cell_address) const {
    return table.find(cell_address) != table.end();
}

std::map<std::string, expression*> csv_table::get_expressions() const {
    return expressions;
}

std::string csv_table::to_csv() const {
    std::string csv_result;

    for (const auto& column_name : column_names){
        csv_result += ("," + column_name);
    }
    csv_result += '\n';

    for (const auto& record_num : record_numbers){
        csv_result += record_num + ',';
        for (const auto& column_name: column_names){
            auto cell_address = column_name + record_num;
            csv_result += (get_cell_value(cell_address) + ',');
        }
        csv_result.pop_back();
        csv_result += '\n';
    }

    return csv_result;
}

