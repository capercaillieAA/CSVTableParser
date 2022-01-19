//
// Created by andru on 16.01.2022.
//

#include "csv_calculator.h"

bool csv_calculator::calculate(computable &csv_scr) {
    auto csv_table = dynamic_cast<table *>(&csv_scr);
    auto expressions = csv_table->get_expressions();
    fill_graph(expressions);

    unsigned int num_of_nodes = calc_graph.size();
    auto sorted_nodes = std::vector<std::string>(num_of_nodes);
    auto marked_nodes = std::unordered_set<std::string>();

    auto start_place = num_of_nodes - 1;
    for (const auto &node : calc_graph) {
        if (marked_nodes.find(node.first) == marked_nodes.end()) {
            if (!check_acyclicity(node.first, marked_nodes)){
                return false;
            }
        }
        marked_nodes.clear();
    }

    marked_nodes.clear();

    for (const auto &node : calc_graph) {
        if (marked_nodes.find(node.first) == marked_nodes.end()) {
            top_sort(node.first, marked_nodes, sorted_nodes, start_place);
        }
    }

    for (const auto &cell : sorted_nodes) {
        if (expressions.find(cell) != expressions.end()) {
            auto args = expressions[cell]->get_args();
            bool convert_validator = true;
            auto first_arg = convert_to_int(args[0], *csv_table, convert_validator);
            if (!convert_validator){
                return false;
            }
            auto second_arg = convert_to_int(args[1], *csv_table, convert_validator);
            if (!convert_validator){
                return false;
            }
            auto func = expressions[cell]->get_operator();

            csv_table->put(cell, std::to_string(func(first_arg, second_arg)));
        }
    }

    return true;
}

void csv_calculator::fill_graph(const std::map<std::string, expression*>& expressions) {
    for (const auto& expr : expressions){
        if (calc_graph.find(expr.first) == calc_graph.end()) {
            calc_graph[expr.first] = std::vector<std::string>();
        }
        for (const auto& arg : expr.second->get_args()){
            if (!arg.is_number()){
                calc_graph[arg.get_as_str()].push_back(expr.first);
            }
        }
    }
}

bool csv_calculator::check_acyclicity(const std::string& beg_node, std::unordered_set<std::string>& marked_nodes) const {
    if (marked_nodes.find(beg_node) != marked_nodes.end()){
        return false;
    }
    marked_nodes.emplace(beg_node);
    for (const auto& node : calc_graph.at(beg_node)) {
        return check_acyclicity(node, marked_nodes);
    }
    marked_nodes.erase(beg_node);
    return true;
}

void csv_calculator::top_sort(const std::string& beg_node, std::unordered_set<std::string>& marked_nodes, std::vector<std::string>& sorted_nodes, unsigned int& place_of_node) const {
    marked_nodes.emplace(beg_node);
    for (const auto& node : calc_graph.at(beg_node)){
        if (marked_nodes.find(node) == marked_nodes.end()){
            top_sort(node, marked_nodes, sorted_nodes, place_of_node);
        }
    }
    sorted_nodes[place_of_node--] = beg_node;
}

int csv_calculator::convert_to_int(const argument &arg, const table& csv_table, bool& is_valid) const {
    int result = 0;

    if (arg.is_number()){
        result = arg.get_as_number();
    }
    else{
        auto first_arg = csv_table.get_cell_value(arg.get_as_str());
        if (first_arg.empty()){
            is_valid = false;
        }
        else {
            result = std::stoi(first_arg);
        }
    }

    return result;
}
