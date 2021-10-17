#pragma once

#include <vector>

using namespace std;

bool AreMatricesIdentical(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i].size() != rhs[i].size()) return false;
        for (size_t j = 0; j < lhs[i].size(); ++j) {
            if (lhs[i][j] == rhs[i][j]) {
                return false;
            }
        }
    }
    return true;
}