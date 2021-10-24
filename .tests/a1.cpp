#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a1.h"

#include <vector>
#include <string>


using namespace std;

TEST_CASE("a1: Example", "[task:a1]") {
    vector<vector<int>> lhs = {};
    vector<vector<int>> rhs = {};
    SECTION("Example 1") {
        lhs = {{1, 2}, {1, 2}};
        rhs = {{1, 2}, {1, 2}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
    }

    SECTION("Example 2") {
        lhs = {{1, 2, 3}};
        rhs = {{3, 2, 1}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
    }

    SECTION("Example 3") {
        lhs = {};
        rhs = {{}};
        REQUIRE(AreMatricesIdentical(lhs, rhs) == false);
    }
}

TEST_CASE("a1: Empty matrices are identical", "[task:a1]")
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

TEST_CASE("a1: Equality of square matrices", "[task:a1]")
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

TEST_CASE("a1: Equality of non square matrices", "[task:a1]") {
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

TEST_CASE("a1: Equality of matrices with different sizes", "[task:a1]") {
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

TEST_CASE("a1: Const arguments", "[task:a1]") {
    const vector<vector<int>> lhs = {{1}};
    const vector<vector<int>> rhs = {{1}};
    REQUIRE(AreMatricesIdentical(lhs, rhs) == true);
}

TEST_CASE("a1: Stress test", "[task:a1]") {
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
