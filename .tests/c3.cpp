#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/c3.h"

#include <fstream>
#include <vector>

using namespace std;

TEST_CASE("c3: Example", "[task:c3]") {
    size_t m, n;
    vector<vector<int>> expected;

    SECTION("Example 1") {
        m = 2;
        n = 3;
        expected = {{1, 2, 3}, {6, 5, 4}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Example 2") {
        m = 3;
        n = 3;
        expected = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
        REQUIRE(expected == CreateSpiral(m, n));
    }
}

TEST_CASE("c3: Corner cases", "[task:c3]") {
    size_t m, n;
    vector<vector<int>> expected;

    SECTION("Single row") {
        m = 1;
        n = 5;
        expected = {{1, 2, 3, 4, 5}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Single column") {
        m = 5;
        n = 1;
        expected = {{1}, {2}, {3}, {4}, {5}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Single row and single column") {
        m = 1;
        n = 1;
        expected = {{1}};
        REQUIRE(expected == CreateSpiral(m, n));
    }
}


TEST_CASE("c3: Different width and height", "[task:c3]") {
    size_t m, n;
    vector<vector<int>> expected;

    SECTION("Both odd") {
        m = 3;
        n = 7;
        expected = {{1,2,3,4,5,6,7},{16,17,18,19,20,21,8},{15,14,13,12,11,10,9}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("One even one odd") {
        m = 5;
        n = 8;
        expected = {{1,2,3,4,5,6,7,8},{22,23,24,25,26,27,28,9},{21,36,37,38,39,40,29,10},{20,35,34,33,32,31,30,11},{19,18,17,16,15,14,13,12}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Both even") {
        m = 4;
        n = 6;
        expected = {{1,2,3,4,5,6},{16,17,18,19,20,7},{15,24,23,22,21,8},{14,13,12,11,10,9}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Equal width and height odd") {
        m = 5;
        n = 5;
        expected = {{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};
        REQUIRE(expected == CreateSpiral(m, n));
    }

    SECTION("Equal width and height even") {
        m = 6;
        n = 6;
        expected = {{1,2,3,4,5,6},{20,21,22,23,24,7},{19,32,33,34,25,8},{18,31,36,35,26,9},{17,30,29,28,27,10},{16,15,14,13,12,11}};
        REQUIRE(expected == CreateSpiral(m, n));
    }
}


TEST_CASE("c3: Gigantic matrix (m = 1000, n = 1000)", "[task:c3]") {
    size_t m = 1000, n = 1000;
    vector<vector<int>> expected(m, vector<int>(n));
    ifstream in(".tests/test_c3.txt");
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            in >> expected[i][j];
        }
    }
    REQUIRE(expected == CreateSpiral(m, n));
}