#pragma once

#include <vector>

using namespace std;

vector<vector<int>>CreateSymmetrical(size_t n) {
    vector<vector<int>>matr(n, vector<int>(n));
    int current_number = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            matr[i][j] = current_number;
            matr[j][i] = current_number;
            current_number++;
        }
    }
    return matr;
}