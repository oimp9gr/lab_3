#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "solution.h"

#include <vector>

using namespace std;

void ResizeMatrix(vector<vector<int>>& matrix, size_t row_new_size, size_t column_new_size = -1) {
    if (column_new_size == static_cast<size_t>(-1)) {
        column_new_size = row_new_size;
    }
    matrix.resize(row_new_size);
    for (auto &row: matrix) {
        row.resize(column_new_size);
    }
}

void FillMatrixIota(vector<vector<int>>& matrix) {
    for (auto &row: matrix) {
        iota(row.begin(), row.end(), 0);
    }
}

TEST_CASE("1: Empty matrices are identical", "[task:1]")
{
    vector<vector<int>> lhs = {};
    vector<vector<int>> rhs = {};
    SECTION("Zero rows") {
        REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
    }
    SECTION("Zero columns") {
        lhs = {{}};
        rhs = {{}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
    }
}

TEST_CASE("1: Equality of square matrices", "[task:1]")
{
    vector<vector<int>> lhs = {};
    vector<vector<int>> rhs = {};
    SECTION("Of size 1") {
        SECTION("Equal") {
            lhs = {{1}};
            rhs = {{1}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
        }

        SECTION("Not equal") {
            lhs = {{1}};
            rhs = {{2}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
        }
    }

    SECTION("Of size 2") {
        SECTION("Equal") {
            lhs = {{1, 1}, {2, 2}};
            rhs = {{1, 1}, {2, 2}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
        }

        SECTION("Not equal") {
            lhs = {{1, 1}, {2, 2}};
            rhs = {{2, 2}, {2, 2}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
        }
    }

    SECTION("Random size") {
        size_t size = rand() % 1000;
        ResizeMatrix(lhs, size);
        ResizeMatrix(rhs, size);
        FillMatrixIota(lhs);
        FillMatrixIota(rhs);

        SECTION("Equal") {
            REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
        }

        SECTION("Not equal") {
            lhs[size - 1][size - 1] = -1 * lhs[size - 1][size - 1];
            REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
        }
    }
}

TEST_CASE("1: Equality of non square matrices", "[task:1]") {
    vector<vector<int>> lhs = {};
    vector<vector<int>> rhs = {};

    SECTION("Row count 2, column count 1") {
        SECTION("Equal") {
            lhs = {{1}, {2}};
            rhs = {{1}, {2}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
        }

        SECTION("Not equal") {
            lhs = {{1}, {2}};
            rhs = {{1}, {3}};
            REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
        }
    }

    SECTION("Random size") {
        size_t size_1 = rand() % 1000;
        size_t size_2 = rand() % 1000;
        ResizeMatrix(lhs, size_1, size_2);
        ResizeMatrix(rhs, size_1, size_2);
        FillMatrixIota(lhs);
        FillMatrixIota(rhs);

        SECTION("Equal") {
            REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
        }

        SECTION("Not equal") {
            lhs[size_1 - 1][size_2 - 1] = -1 * lhs[size_1 - 1][size_2 - 1];
            REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
        }
    }
}

TEST_CASE("1: Equality of matrices with different sizes", "[task:1]") {
    vector<vector<int>> lhs;
    vector<vector<int>> rhs;

    SECTION("Square matrices") {
        lhs = {{1, 1}, {2, 2}};
        rhs = {{1}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == false);

        lhs = {{1}};
        rhs = {{1, 1}, {2, 2}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
    }

    SECTION("Non square matrices") {
        lhs = {{1, 1}};
        rhs = {{1, 1}, {2, 2}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
    }
}

TEST_CASE("1: Const arguments", "[task:1]") {
    const vector<vector<int>> lhs = {{1}};
    const vector<vector<int>> rhs = {{1}};
    REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
}

TEST_CASE("1: Stress test", "[task:1]") {
    size_t size = 10;
    vector<vector<int>>lhs(size, vector<int>(size));
    vector<vector<int>>rhs(size, vector<int>(size));
    FillMatrixIota(lhs);
    FillMatrixIota(rhs);
    uint32_t counter = 0;
    for (size_t i = 0; i < 500000; ++i) {
        counter += static_cast<uint32_t>(AreMatricesIdentical(lhs, rhs));
    }
    REQUIRE(counter == 500000);
}