//
// Created by andru on 14.01.2022.
//

#include "csv_reader.h"
#include "../csv_parser/csv_parser.h"
#include "../csv_table/csv_table.h"

csv_reader::csv_reader(const std::string& file_name) {
    csv_file.open(file_name);
    parser = new csv_parser();
}

csv_reader::~csv_reader() {
    csv_file.close();
    delete parser;
}

bool csv_reader::read(table& csv_table) {
    if (csv_file.is_open()) {
        auto set_of_strings = read_strings();
        auto str_table_header = set_of_strings[0];
        auto table_header = parser->parse(str_table_header, ",");

        for (int i = 1; i < set_of_strings.size(); ++i) {
            auto cur_str = parser->parse(set_of_strings[i], ",");
            auto num_of_record = cur_str[0];
            for (int j = 1; j < cur_str.size(); ++j) {
                auto column_name = table_header[(j - 1) % table_header.size()];
                csv_table.put(num_of_record, column_name, cur_str[j]);
            }
        }

        return true;
    }

    return false;
}

std::vector<std::string> csv_reader::read_strings() {
    auto result_strings = std::vector<std::string>();

    std::string cur_str;
    while (std::getline(csv_file, cur_str)){
        result_strings.emplace_back(cur_str);
    }

    return result_strings;
}


