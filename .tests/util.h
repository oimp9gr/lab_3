#include <vector>

#pragma once

void ResizeMatrix(vector<vector<int>> &matrix, size_t row_new_size, size_t column_new_size = -1) {
    if (column_new_size == static_cast<size_t>(-1)) {
        column_new_size = row_new_size;
    }
    matrix.resize(row_new_size);
    for (auto &row: matrix) {
        row.resize(column_new_size);
    }
}

void FillMatrixIota(vector<vector<int>> &matrix, int start = 0) {
    for (auto &row: matrix) {
        iota(row.begin(), row.end(), start);
    }
}