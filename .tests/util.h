#pragma once

#include <vector>
#include <string>
#include <numeric>

using namespace std;

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

string GenerateStringFromAlphabet(const vector<char> &alphabet, size_t size) {
    string result;
    for (size_t i = 0; i < size; ++i) {
        result += alphabet[rand() % alphabet.size()];
    }
    return result;
}