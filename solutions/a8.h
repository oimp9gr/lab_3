#pragma once

#include <vector>

using namespace std;

bool IsCorrectSudokuSquare(vector<vector<int>> square) {
    vector<bool>used(9, false);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (square[i][j] < 1 || square[i][j] > 9 || used[square[i][j]]) {
                return false;
            } else {
                used[square[i][j]] = true;
            }
        }
    }
    return true;
}