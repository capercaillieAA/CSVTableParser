//
// Created by andru on 14.01.2022.
//

#include "csv_table.h"

int csv_table::num_of_cells = 0;

void csv_table::put_next(const std::string& num_of_record, const std::string& value) {
    if (num_of_cells % column_names.size() == 0){
        record_numbers.push_back(num_of_record);
    }
    auto cell_address = column_names[num_of_cells % column_names.size()] + num_of_record;
    table[cell_address] = value;
    num_of_cells++;
}

std::string csv_table::get_cell_value(const std::string& cell_address) {
    return cell_exist(cell_address) ? table[cell_address] : "";
}

bool csv_table::cell_exist(const std::string& cell_address) {
    return table.find(cell_address) != table.end();
}

void csv_table::set_header(const std::vector<std::string> &header) {
    column_names = header;
}

std::string csv_table::to_csv() {
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



