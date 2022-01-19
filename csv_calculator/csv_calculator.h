//
// Created by andru on 16.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_CALCULATOR_H
#define CSVTABLEPARSER_CSV_CALCULATOR_H

#include "calculator.h"
#include <unordered_set>

class csv_calculator : public calculator{
public:
    bool calculate(computable &csv_src) override final;

private:
    void fill_graph(const std::map<std::string, expression*>& expressions);
    bool check_acyclicity(const std::string& beg_node, std::unordered_set<std::string>& marked_nodes) const;
    void top_sort(const std::string& beg_node, std::unordered_set<std::string>& mark_nodes, std::vector<std::string>& sorted_nodes, unsigned int& place_of_node) const;
    int convert_to_int(const argument& arg, const table& csv_table, bool& is_valid) const;

    std::map<std::string, std::vector<std::string>> calc_graph;
};


#endif //CSVTABLEPARSER_CSV_CALCULATOR_H
