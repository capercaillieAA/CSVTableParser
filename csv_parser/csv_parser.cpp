//
// Created by andru on 14.01.2022.
//

#include "csv_parser.h"

std::vector<std::string> csv_parser::parse(const std::string& csv_str, const std::string& delims) {
    auto result_str_set = std::vector<std::string>();

    std::string cur_str;
    for (const auto symb : csv_str) {
        if (delims.find(symb) != std::string::npos) {
            if (!cur_str.empty()) {
                result_str_set.emplace_back(cur_str);
                cur_str = "";
            }
        } else {
            cur_str += symb;
        }
    }
    result_str_set.emplace_back(cur_str);

    return result_str_set;
}
