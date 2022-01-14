//
// Created by andru on 14.01.2022.
//

#include "csv_parser.h"

std::vector<std::string> csv_parser::parse_csv_str(std::string csv_str) {
    auto result_str_set = std::vector<std::string>();

    std::string cur_str;
    for (const auto symb : csv_str){
        if (symb == ',') {
            if (!cur_str.empty()) {
                result_str_set.emplace_back(cur_str);
                cur_str = "";
                continue;
            }
        }
        else {
            cur_str += symb;
        }
    }
    result_str_set.emplace_back(cur_str);

    return result_str_set;
}
