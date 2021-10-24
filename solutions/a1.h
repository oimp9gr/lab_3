#pragma once

#include <vector>

using namespace std;

bool AreMatricesIdentical(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
    return lhs == rhs;
}