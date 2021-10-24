#pragma once

#include <vector>

using namespace std;

void RotateMatrix(vector<vector<int>> &matrix) {
    size_t n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = result;
}