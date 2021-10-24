#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a9.h"

#include <vector>

using namespace std;

TEST_CASE("a9: Example", "[task:a9]") {
    vector<vector<int>> matrix;
    vector<int> expected;
    SECTION("Example 1") {
        matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
        expected = {15};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }

    SECTION("Example 2") {
        matrix = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
        expected = {12};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }

    SECTION("Example 3") {
        matrix = {{3, 6}, {7, 1}, {5, 2}, {4, 8}};
        expected = {};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }
}

TEST_CASE("a9: Different sizes", "[task:a9]") {
    vector<vector<int>> matrix;
    vector<int> expected;
    SECTION("1 row 1 column") {
        matrix = {{1}};
        expected = {1};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }

    SECTION("1 row 2 columns") {
        matrix = {{1, 3}};
        expected = {1};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }

    SECTION("2 rows 1 column") {
        matrix = {{1}, {3}};
        expected = {3};
        REQUIRE(LuckyNumbers(matrix) == expected);
    }
}

TEST_CASE("a9: Const matrix", "[task:a9]") {
    const vector<vector<int>> matrix{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    REQUIRE_NOTHROW(LuckyNumbers(matrix));
}