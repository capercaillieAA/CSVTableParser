//
// Created by andru on 16.01.2022.
//

#include "csv_calculator.h"

void csv_calculator::calculate(computable &csv_scr) {
    auto csv_table = dynamic_cast<table*>(&csv_scr);
    auto expressions = csv_table->get_expressions();

    // TODO
}
