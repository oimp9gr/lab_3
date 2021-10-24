#pragma once

#include <vector>
#include <climits>

using namespace std;

bool checkIfMax(const vector<vector<int>>& matrix, int min, size_t j) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][j] > min) {
            return false;
        }
    }
    return true;
}

vector<int> LuckyNumbers (const vector<vector<int>>& matrix) {
    int min = INT_MAX;
    size_t min_ind;
    vector<int>numbers;
    for (size_t i = 0; i < matrix.size(); ++i) {
        min = INT_MAX;
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_ind = j;
            }
        }
        if (checkIfMax(matrix, min, min_ind)) {
            numbers.push_back(min);
        }
    }
    return numbers;
}