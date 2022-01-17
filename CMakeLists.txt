cmake_minimum_required(VERSION 3.17)
project(CSVTableParser)

set(CMAKE_CXX_STANDARD 20)
set(HEADER_LIST csv_table/table.h csv_table/csv_table.h
        csv_parser/parser.h csv_parser/csv_parser.h csv_parser/expression_parser.h
        csv_reader/reader.h csv_reader/csv_reader.h
        csv_calculator/computable.h csv_calculator/expression.h csv_calculator/bin_expression.h csv_calculator/calculator.h csv_calculator/csv_calculator.h)
set(SRC_LIST csv_table/csv_table.cpp
        csv_parser/csv_parser.cpp csv_parser/expression_parser.cpp
        csv_reader/csv_reader.cpp
        csv_calculator/bin_expression.cpp csv_calculator/csv_calculator.cpp
        main.cpp)

add_executable(CSVTableParser ${HEADER_LIST} ${SRC_LIST})