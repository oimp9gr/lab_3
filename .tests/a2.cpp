#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a2.h"

#include <vector>


TEST_CASE("a2: Example", "[task:a2]") {
    vector<vector<int>> matr = {};
    SECTION("Example 1") {
        matr = {{1, 2}, {3, 4}};
        REQUIRE(TheGreatestColumnSum(matr) == 6);
    }

    SECTION("Example 2") {
        matr = {{1, 2, 3}, {3, 2, 1}};
        REQUIRE(TheGreatestColumnSum(matr) == 4);
    }

    SECTION("Example 3") {
        matr = {};
        REQUIRE(TheGreatestColumnSum(matr) == 0);
    }
}

TEST_CASE("a2: Empty matrix", "[task:a2]") {
    vector<vector<int>> matr = {};
    SECTION("Zero rows") {
        matr = {};
        REQUIRE(TheGreatestColumnSum(matr) == 0);
    }

    SECTION("Zero columns") {
        matr = {{}, {}};
        REQUIRE(TheGreatestColumnSum(matr) == 0);
    }
}

TEST_CASE("a2: Square matrix", "[task:a2]") {
    vector<vector<int>> matr = {};
    SECTION("1 row 1 column") {
        matr = {{1}};
        REQUIRE(TheGreatestColumnSum(matr) == 1);
    }

    SECTION("2 rows 2 columns") {
        matr = {{13, 17}, {27, 24}};
        REQUIRE(TheGreatestColumnSum(matr) == 41);
    }

    SECTION("Random size") {
        size_t size = rand() % 1000;
        ResizeMatrix(matr, size);
        FillMatrixIota(matr);
        REQUIRE(TheGreatestColumnSum(matr) == (size) * (size - 1));
    }
}

TEST_CASE("a2: Non square matrix", "[task:a2]") {
    vector<vector<int>> matr = {};
    SECTION("1 row 2 columns") {
        matr = {{1, 2}};
        REQUIRE(TheGreatestColumnSum(matr) == 2);
    }

    SECTION("2 rows 1 columns") {
        matr = {{13}, {27}};
        REQUIRE(TheGreatestColumnSum(matr) == 40);
    }

    SECTION("Random size") {
        size_t row_new_size = rand() % 1000;
        size_t column_new_size = rand() % 1000;
        ResizeMatrix(matr, row_new_size, column_new_size);
        FillMatrixIota(matr);
        REQUIRE(TheGreatestColumnSum(matr) == (row_new_size) * (column_new_size - 1));
    }
}

TEST_CASE("a2: Big numbers", "[task:a2]") {
    vector<vector<int>> matr = {};
    int64_t size = 100;
    ResizeMatrix(matr, size);
    FillMatrixIota(matr, INT32_MAX - size);
    REQUIRE(TheGreatestColumnSum(matr) == (INT32_MAX - 1) * (size));
}

TEST_CASE("a2: Stress test", "[task:a2]") {
    size_t size = 10;
    vector<vector<int>>matr = {};
    ResizeMatrix(matr, size);
    FillMatrixIota(matr);
    uint32_t counter = 0;
    for (size_t i = 0; i < 700000; ++i) {
        counter += static_cast<uint32_t>(TheGreatestColumnSum(matr) == 90);
    }
    REQUIRE(counter == 700000);
}

TEST_CASE("a2: Const argument", "[task:a2]") {
    const vector<vector<int>> matr = {{1}};
    REQUIRE(TheGreatestColumnSum(matr) == 1);
}