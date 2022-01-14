#include "csv_reader/csv_reader.h"
#include "csv_table/csv_table.h"
#include <iostream>

int main(int argc, const char **argv) {
    auto file_name = argv[1];
    csv_reader reader(file_name);
    csv_table table;

    reader.read(table);
    std::cout << table.to_csv();
}
