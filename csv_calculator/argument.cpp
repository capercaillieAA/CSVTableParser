//
// Created by andru on 19.01.2022.
//

#include "argument.h"
#include <algorithm>

argument::argument(const std::string &str) : arg_value(str){
}

int argument::get_as_number() const {
    return std::stoi(arg_value);
}

std::string argument::get_as_str() const{
    return arg_value;
}

bool argument::is_number() const{
    return !arg_value.empty() &&
           std::find_if(arg_value.begin(), arg_value.end(), [](auto ch){return !std::isdigit(ch);}) == arg_value.end();
}
