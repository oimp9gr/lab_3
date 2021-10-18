#pragma once

#include "util.h"
#include "catch.hpp"
#include "../solutions/a4.h"

#include <vector>
#include <set>

using namespace std;

size_t AmountOfDifferentNumbers(const vector<vector<int>> &matr) {
    set<int> numbers;
    for (size_t i = 0; i < matr.size(); i++) {
        for (size_t j = 0; j < matr.size(); j++) {
            numbers.insert(matr[i][j]);
        }
    }
    return numbers.size();
}

bool IsSymmetrical(const vector<vector<int>> &matr) {
    for (size_t i = 0; i < matr.size(); i++) {
        for (size_t j = i + 1; j < matr.size(); j++) {
            if (matr[i][j] != matr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

TEST_CASE("4: Example", "[task:4]") {
    SECTION("Example 1") {
        size_t size = 2;
        vector<vector<int>> result = CreateSymmetrical(size);
        REQUIRE(IsSymmetrical(result));
        REQUIRE(AmountOfDifferentNumbers(result) == ((size + 1) * size) / 2);
    }SECTION("Example 2") {
        size_t size = 3;
        vector<vector<int>> result = CreateSymmetrical(size);
        REQUIRE(IsSymmetrical(result));
        REQUIRE(AmountOfDifferentNumbers(result) == ((size + 1) * size) / 2);
    }SECTION("Example 3") {
        size_t size = 0;
        vector<vector<int>> result = CreateSymmetrical(size);
        REQUIRE(IsSymmetrical(result));
        REQUIRE(AmountOfDifferentNumbers(result) == ((size + 1) * size) / 2);
    }
}

TEST_CASE("4: All sizes up to 10", "[task:4]") {
    for (size_t i = 0; i < 10; ++i) {
        size_t size = i;
        vector<vector<int>> result = CreateSymmetrical(size);
        REQUIRE(IsSymmetrical(result));
        REQUIRE(AmountOfDifferentNumbers(result) == ((size + 1) * size) / 2);
    }
}

TEST_CASE("4: Big matrix", "[task:4]") {
    size_t size = rand() % 1000;
    vector<vector<int>> result = CreateSymmetrical(size);
    REQUIRE(IsSymmetrical(result));
    REQUIRE(AmountOfDifferentNumbers(result) == ((size + 1) * size) / 2);
}