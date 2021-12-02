#pragma once
#include <vector>

 bool AreMatricesIdentical(const std::vector<std::vector<int>>& first_vector, const std::vector<std::vector<int>>& second_vector) {
    for(int i = 0; i < first_vector.size(); i++)
    {
        for(int j = i + 1; j < first_vector.size(); j++)
            if(first_vector[i][j] != second_vector[i][j])
                return false;
    }
    return true;
}
