#include "csv_reader/csv_reader.h"
#include "csv_table/csv_table.h"
#include "csv_calculator/csv_calculator.h"
#include <iostream>

int main(int argc, const char **argv) {
    auto file_name = argv[1];
    csv_reader reader(file_name);
    csv_table table;

    auto read_checker = reader.read(table);
    if (!read_checker){
        std::cout << "The specified file was not found or the table is set in the wrong format";
        return 0;
    }

    csv_calculator calculator;
    auto calc_checker = calculator.calculate(table);
    if (!calc_checker){
        std::cout << "The calculation cannot be performed";
        return 0;
    }

    std::cout << table.to_csv();
}
