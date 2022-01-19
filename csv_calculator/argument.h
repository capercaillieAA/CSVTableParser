//
// Created by andru on 19.01.2022.
//

#ifndef CSVTABLEPARSER_ARGUMENT_H
#define CSVTABLEPARSER_ARGUMENT_H

#include <string>

class argument {
public:
    argument() = default;
    explicit argument(const std::string& str);

    bool is_number() const;
    int get_as_number() const;
    std::string get_as_str() const;

private:
    std::string arg_value;
};


#endif //CSVTABLEPARSER_ARGUMENT_H
