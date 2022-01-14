//
// Created by andru on 14.01.2022.
//

#ifndef CSVTABLEPARSER_CSV_READER_H
#define CSVTABLEPARSER_CSV_READER_H

#include "reader.h"
#include "../csv_parser/parser.h"
#include <fstream>

class csv_reader : public reader{
public:
    explicit csv_reader(const std::string& file_name);
    ~csv_reader();

    csv_reader(const csv_reader& other) = delete;
    csv_reader& operator=(const csv_reader& other) = delete;

    bool read(table& dest) override final;

private:
    std::vector<std::string> read_strings();

    std::fstream csv_file;
    parser *parser;
};


#endif //CSVTABLEPARSER_CSV_READER_H
