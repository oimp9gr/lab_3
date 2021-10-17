#pragma once

#include <vector>
#include <cstdint>

using namespace std;

int64_t TheGreatestColumnSum(const vector<vector<int>> &matr) {
    if (matr.empty() || matr[0].empty()) {
        return 0;
    }
    int64_t greatest_sum = 0;
    for (size_t j = 0; j < matr[0].size(); ++j) {
        int64_t column_sum = 0;
        for (size_t i = 0; i < matr.size(); ++i) {
            column_sum += matr[i][j];
        }
        if (column_sum > greatest_sum) {
            greatest_sum = column_sum;
        }
    }
    return greatest_sum;
}