cmake_minimum_required(VERSION 3.17)
project(CSVTableParser)

set(CMAKE_CXX_STANDARD 20)
set(HEADER_LIST csv_table/table.h csv_table/csv_table.h
                csv_parser/parser.h csv_parser/csv_parser.h
                csv_reader/reader.h csv_reader/csv_reader.h)
set(SRC_LIST    csv_table/csv_table.cpp
                csv_parser/csv_parser.cpp
                csv_reader/csv_reader.cpp
                main.cpp)

add_executable(${PROJECT_NAME} ${HEADER_LIST} ${SRC_LIST})